#ifndef CONNECTIONHANDLER_H
#define CONNECTIONHANDLER_H

#include <QObject>

#include "connection/AbstractConnection.h"
#include "connection/TcpConnection.h"
#include "connection/UdpConnection.h"
#include "connection/Simulation.h"
namespace Handlers{
    class ConnectionHandler : public QObject
    {

        Q_OBJECT
        Q_PROPERTY(QString connectionStatus READ connectionStatus  NOTIFY connectionStatusChanged)
        Q_PROPERTY(bool isConnected READ isConnected  NOTIFY connectionStatusChanged)
        Q_PROPERTY(bool isTCPConnection READ isTCPConnection  NOTIFY selectedConnectionChanged)
        Q_PROPERTY(bool isUDPConnection READ isUDPConnection  NOTIFY selectedConnectionChanged)
        Q_PROPERTY(bool isSimulation READ isSimulation  NOTIFY selectedConnectionChanged)
        Q_PROPERTY(Connection::TcpConnection* tcpConnection READ tcpConnection CONSTANT)
        Q_PROPERTY(Connection::UdpConnection* udpConnection READ udpConnection CONSTANT)
        Q_PROPERTY(Connection::Simulation* simulation READ simulation CONSTANT)
    public:
        enum ConnectionType{
           TCP, UDP, SIMULATION
        };

        Q_ENUMS(ConnectionType)

         ConnectionHandler(QObject *parent = 0);
        static ConnectionHandler* instance(){
            if(p_instance == NULL){
                p_instance = new ConnectionHandler();
            }
            return p_instance;
        }

        Q_INVOKABLE void connectToSelectedHost();
        Q_INVOKABLE void disconnectFromSelectedHost();
        Q_INVOKABLE void connectDisconnect();
        Q_INVOKABLE void selectConnection(ConnectionType type);
        const QString& connectionStatus();       
        bool isConnected();
        bool isTCPConnection();
        bool isUDPConnection();
        bool isSimulation();
        Connection::TcpConnection* tcpConnection() const;
        Connection::UdpConnection* udpConnection() const;
        Connection::Simulation *simulation() const;



    signals:
        void connectionStatusChanged();
        void selectedConnectionChanged();
        void disconnected();
    private slots:
        void tcpConnectionStatusChangeHandler();
        void udpConnectionStatusChangeHandler();
        void simulationConnectionStatusChangeHandler();
    private:
       static ConnectionHandler* p_instance;
       Connection::AbstractConnection* m_currentConnection;       
       Connection::TcpConnection* m_tcpConnection;
       Connection::UdpConnection* m_udpConnection;
       Connection::Simulation* m_simulation;
       QString m_connectionStatus;

       void setCurrentConnectionTCP();
       void setCurrentConnectionUDP();
       void setCurrentConnectionSimulation();

       void setConnectionStatusChanged();
    };
}

#endif // CONNECTIONHANDLER_H
