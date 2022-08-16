#ifndef UDPCONNECTION_H
#define UDPCONNECTION_H

#include <QObject>
#include <QUdpSocket>
#include "AbstractConnection.h"
namespace Connection{
    class UdpConnection : public AbstractConnection
    {
        Q_OBJECT
         Q_PROPERTY(int port READ port WRITE setPort NOTIFY portChanged)
    public:
        UdpConnection(QObject *parent = 0);
        ~UdpConnection();
        void connectToHost();
        void disconnectFromHost();
        const int& port();
        void setPort(int port);
    signals:
        void portChanged();
    public slots:
    private slots:
        void readUdp();
        void udpConnected();
        void displayError(QAbstractSocket::SocketError socketError);
    private:
        QUdpSocket *m_udpSocket;
        int m_port;
    };
}

#endif // UDPCONNECTION_H
