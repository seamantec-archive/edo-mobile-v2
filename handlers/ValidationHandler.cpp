#include "ValidationHandler.h"
#include "handlers/ConnectionHandler.h"
#include <QDebug>
const short Handlers::ValidationHandler::INTERVAL = 500;

Handlers::ValidationHandler::ValidationHandler(QObject *parent) : QObject(parent)
{
    m_timer = new QTimer(this);
    connect(m_timer, SIGNAL(timeout()), this, SLOT(timerUpdateHandler()));
    connect(Handlers::ConnectionHandler::instance(), SIGNAL(disconnected()), this, SLOT(resetNeed()));
    m_currentTimestampCounter = 0;
    setLastTimestamp();
    m_timer->start(INTERVAL);

}

int* Handlers::ValidationHandler::currentTimestamp()
{
    return &m_timestamps.last();
}

void Handlers::ValidationHandler::resetNeed()
{
    emit resetAllData();
}



void Handlers::ValidationHandler::timerUpdateHandler()
{
    setLastTimestamp();
    emit timestampChanged(currentTimestamp());
}

void Handlers::ValidationHandler::setLastTimestamp(){
    m_currentTimestampCounter += INTERVAL;
    m_timestamps.append(m_currentTimestampCounter);
}

void Handlers::ValidationHandler::reset()
{
    m_currentTimestampCounter = 0;
    emit statusChanged();
}
