#ifndef TCPCONNECTION_H
#define TCPCONNECTION_H

#include <QObject>
#include <QTcpSocket>
#include "AbstractConnection.h"
namespace Connection{
    class TcpConnection : public AbstractConnection
    {
        Q_OBJECT
        Q_PROPERTY(QString host READ host WRITE setHost NOTIFY hostChanged)
        Q_PROPERTY(short port READ port WRITE setPort NOTIFY portChanged)
    public:
        TcpConnection(QObject *parent = 0);
        ~TcpConnection();
        void connectToHost();
        void disconnectFromHost();
        const QString& host();
        const short& port();
        void setHost(QString host);
        void setPort(short port);
    signals:
        void hostChanged();
        void portChanged();
    public slots:

    private slots:
        void readTcp();
        void tcpConnected();
        void displayError(QAbstractSocket::SocketError socketError);
    private:
        QTcpSocket *tcpSocket;
        QString m_host;
        short m_port;
    };
}

#endif // TCPCONNECTION_H
