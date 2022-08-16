#include "Simulation.h"
#include <QDebug>
#include "handlers/DataHandler.h"
Connection::Simulation::Simulation(QObject *parent) : Connection::AbstractConnection(parent)
{
   m_file =new QFile(":/configs/demo.nmea");
    isFileOpen = m_file->open(QIODevice::ReadOnly | QIODevice::Text);
    if(isFileOpen) {
        m_in = new QTextStream(m_file);
    }
    m_timer = new QTimer(this);
    connect(m_timer, SIGNAL(timeout()),this, SLOT(timerUpdateHandler()));
}

void Connection::Simulation::connectToHost()
{
    m_in->reset();
    m_timer->start(200);
     setStatus(Connected);
}

void Connection::Simulation::disconnectFromHost()
{
    m_timer->stop();
     setStatus(NotConnected);
}

void Connection::Simulation::timerUpdateHandler()
{
    if(m_in->atEnd()){
        m_in->reset();
    }
    QString message = m_in->readLine() + "\r\n";
   // qDebug() << "SIMULATION MESSAGE: " << message;
    Handlers::DataHandler::instance()->handleMessage(message);
}

