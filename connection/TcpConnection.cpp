#include "TcpConnection.h"
#include "handlers/DataHandler.h"


Connection::TcpConnection::TcpConnection(QObject *parent) : Connection::AbstractConnection(parent),
    m_host("localhost"), m_port(3331)
{
    tcpSocket = new QTcpSocket(this);
    connect(tcpSocket, SIGNAL(connected()), this, SLOT(tcpConnected()));
    connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(readTcp()));
    connect(tcpSocket, SIGNAL(error(QAbstractSocket::SocketError)),
            this, SLOT(displayError(QAbstractSocket::SocketError)));
}

Connection::TcpConnection::~TcpConnection()
{

}

void Connection::TcpConnection::connectToHost()
{
    qDebug() << "TCP connection connect"<<m_host << ":"<<m_port;
    tcpSocket->abort();
    tcpSocket->connectToHost(m_host,m_port);
    tcpSocket->waitForConnected(1000);
}

void Connection::TcpConnection::disconnectFromHost()
{
    tcpSocket->disconnectFromHost();
    setStatus(NotConnected);
}

const QString &Connection::TcpConnection::host()
{
    return m_host;
}

const short &Connection::TcpConnection::port()
{
    return m_port;
}

void Connection::TcpConnection::setHost(QString host)
{
    qDebug() << "SET HOST: "<< host;
    if(host != m_host){
        m_host = host;
        //emit hostChanged();
    }
}

void Connection::TcpConnection::setPort(short port)
{
    if(m_port != port){
        m_port = port;
        //emit portChanged();
    }
}

void Connection::TcpConnection::readTcp()
{

    QString message = tcpSocket->readAll();
    Handlers::DataHandler::instance()->handleMessage(message);
//    qDebug() << "TCP message";
//    qDebug() <<  message;
//    qDebug() <<  "---";
}

void Connection::TcpConnection::tcpConnected()
{
    setStatus(Connected);
}

void Connection::TcpConnection::displayError(QAbstractSocket::SocketError socketError)
{
    switch (socketError) {
    case QAbstractSocket::RemoteHostClosedError:
    case QAbstractSocket::HostNotFoundError:
    case QAbstractSocket::ConnectionRefusedError:
    default:
     setStatus(NotConnected);
    }
}


