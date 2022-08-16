#include <QNetworkInterface>
#include <QDebug>
#include "UdpConnection.h"
#include "handlers/DataHandler.h"
Connection::UdpConnection::UdpConnection(QObject *parent) : AbstractConnection(parent)
{
    m_udpSocket = new QUdpSocket(this);
    m_port = 33333;
    connect(m_udpSocket, SIGNAL(connected()), this, SLOT(udpConnected()));
    connect(m_udpSocket, SIGNAL(readyRead()), this, SLOT(readUdp()));
    connect(m_udpSocket, SIGNAL(error(QAbstractSocket::SocketError)),
            this, SLOT(displayError(QAbstractSocket::SocketError)));



}

Connection::UdpConnection::~UdpConnection()
{

}

void Connection::UdpConnection::connectToHost()
{
    qDebug() << "UDP connection connect " << m_port;
    bool isBind = m_udpSocket->bind(QHostAddress::AnyIPv4, m_port, QUdpSocket::ShareAddress);
    qDebug() << isBind;
    qDebug() << "-----";
    setStatus(Connected);
//    QHostAddress groupAddress = QHostAddress("224.0.0.1");

//    bool x = m_udpSocket->joinMulticastGroup(groupAddress);
//    qDebug() << x;
}

void Connection::UdpConnection::disconnectFromHost()
{
    m_udpSocket->disconnectFromHost();
    setStatus(NotConnected);

}

const int &Connection::UdpConnection::port()
{
   return m_port;
}

void Connection::UdpConnection::setPort(int port)
{
    if(m_port != port){
        m_port = port;
        //emit portChanged();
    }
}

void Connection::UdpConnection::readUdp()
{
            QByteArray datagram;
            datagram.resize(m_udpSocket->pendingDatagramSize());
            QHostAddress sender;
            quint16 senderPort;

            m_udpSocket->readDatagram(datagram.data(), datagram.size(),
                                    &sender, &senderPort);

            QString message = datagram.data();
            Handlers::DataHandler::instance()->handleMessage(message);

            qDebug() << "UDP message ";
            qDebug() <<  message;
            qDebug() <<  "---";

}

void Connection::UdpConnection::udpConnected()
{
    setStatus(Connected);
}

void Connection::UdpConnection::displayError(QAbstractSocket::SocketError socketError)
{
    switch (socketError) {
    case QAbstractSocket::RemoteHostClosedError:
    case QAbstractSocket::HostNotFoundError:
    case QAbstractSocket::ConnectionRefusedError:
    default:
     setStatus(NotConnected);
    }
}
