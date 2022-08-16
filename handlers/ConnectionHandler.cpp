#include "ConnectionHandler.h"
#include <QtNetwork>
#include <QDebug>
Handlers::ConnectionHandler* Handlers::ConnectionHandler::p_instance = NULL;


Handlers::ConnectionHandler::ConnectionHandler(QObject *parent):QObject(parent)
{
    m_tcpConnection = new Connection::TcpConnection(this);
    m_currentConnection = m_tcpConnection;

    m_udpConnection = new Connection::UdpConnection(this);

    m_simulation = new Connection::Simulation(this);
    m_connectionStatus = "Disconnected";
    connect(m_tcpConnection, SIGNAL(statusChanged()),
            this, SLOT(tcpConnectionStatusChangeHandler()));
    connect(m_udpConnection, SIGNAL(statusChanged()),
            this, SLOT(udpConnectionStatusChangeHandler()));
    connect(m_simulation, SIGNAL(statusChanged()),
            this, SLOT(simulationConnectionStatusChangeHandler()));

}

void Handlers::ConnectionHandler::connectToSelectedHost()
{
    if(m_currentConnection != NULL){
        m_currentConnection->connectToHost();
    }
}

void Handlers::ConnectionHandler::disconnectFromSelectedHost()
{
    if(m_currentConnection != NULL){
        m_currentConnection->disconnectFromHost();
    }
}

void Handlers::ConnectionHandler::connectDisconnect()
{
   if(m_currentConnection != NULL ){
       if(m_currentConnection->isConnected()){
            m_currentConnection->disconnectFromHost();
       }else{
           m_currentConnection->connectToHost();
       }
   }
}

void Handlers::ConnectionHandler::selectConnection(Handlers::ConnectionHandler::ConnectionType type)
{
    if(type == TCP){
      setCurrentConnectionTCP();
    }else if(type == UDP){
      setCurrentConnectionUDP();
    }else if(type == SIMULATION){
        setCurrentConnectionSimulation();
    }
}

const QString &Handlers::ConnectionHandler::connectionStatus()
{
    return m_connectionStatus;
}

bool Handlers::ConnectionHandler::isConnected()
{
   if(m_currentConnection != NULL){
       return m_currentConnection->isConnected();
   }
   return false;
}

bool Handlers::ConnectionHandler::isTCPConnection()
{
    return  m_currentConnection == m_tcpConnection;
}

bool Handlers::ConnectionHandler::isUDPConnection()
{
    return  m_currentConnection == m_udpConnection;
}

bool Handlers::ConnectionHandler::isSimulation()
{
    return m_currentConnection == m_simulation;
}

Connection::TcpConnection *Handlers::ConnectionHandler::tcpConnection() const
{
    return m_tcpConnection;
}

Connection::UdpConnection *Handlers::ConnectionHandler::udpConnection() const
{
    return m_udpConnection;
}

Connection::Simulation *Handlers::ConnectionHandler::simulation() const
{
    return m_simulation;
}

void Handlers::ConnectionHandler::tcpConnectionStatusChangeHandler()
{
    if(isTCPConnection()){
        m_connectionStatus = m_tcpConnection->isConnected() ? "Connected to TCP" : "Disconnected";
        setConnectionStatusChanged();
    }
}

void Handlers::ConnectionHandler::udpConnectionStatusChangeHandler()
{
    if(isUDPConnection()){
        m_connectionStatus = m_udpConnection->isConnected() ? "Connected to UDP" : "Disconnected";
        setConnectionStatusChanged();
    }
}

void Handlers::ConnectionHandler::simulationConnectionStatusChangeHandler()
{
    if(isSimulation()){
        m_connectionStatus = m_simulation->isConnected() ? "Simulation" : "Disconnected";
        setConnectionStatusChanged();
    }
}

void Handlers::ConnectionHandler::setCurrentConnectionTCP()
{
  if(m_currentConnection != NULL && !isTCPConnection()){
      if(m_currentConnection->isConnected()){
          qDebug() << "NEED a dialog because there is a live connection";
          m_currentConnection->disconnectFromHost();
      }
      m_currentConnection = m_tcpConnection;
      emit selectedConnectionChanged();
  }
}

void Handlers::ConnectionHandler::setCurrentConnectionUDP()
{
    if(m_currentConnection != NULL && !isUDPConnection()){
        if(m_currentConnection->isConnected()){
            qDebug() << "NEED a dilago because there is a live connection";
             m_currentConnection->disconnectFromHost();
        }
        m_currentConnection = m_udpConnection;
        emit selectedConnectionChanged();
    }
}

void Handlers::ConnectionHandler::setCurrentConnectionSimulation()
{
    if(m_currentConnection != NULL && !isSimulation()){
        if(m_currentConnection->isConnected()){
            qDebug() << "NEED a dilago because there is a live connection";
             m_currentConnection->disconnectFromHost();
        }
        m_currentConnection = m_simulation;
        emit selectedConnectionChanged();
    }
}

void Handlers::ConnectionHandler::setConnectionStatusChanged()
{
    emit connectionStatusChanged();
    if(m_currentConnection != NULL && !m_currentConnection->isConnected()){
      emit disconnected();
    }
}




