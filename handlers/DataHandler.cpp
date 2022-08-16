#include "DataHandler.h"

Handlers::DataHandler* Handlers::DataHandler::p_instance = NULL;

Handlers::DataHandler::DataHandler(QObject *parent) : QObject(parent)
{
      qDebug() << "DataHandler constructor";

}

void Handlers::DataHandler::handleMessage(QString message)
{
    if(m_currentParser != NULL){
        m_currentParser->handleMessage(message);
    }
}

EdoData::DataModel* Handlers::DataHandler::dataModel()
{
    return m_dataModel;
}

Handlers::ValidationHandler *Handlers::DataHandler::validationHandler() const
{
    return m_validationHandler;
}

void Handlers::DataHandler::initialize()
{
    m_validationHandler = new Handlers::ValidationHandler(this);
    m_dataModel = new EdoData::DataModel(this);
    m_currentParser = &m_nmea0183Parser;
}
