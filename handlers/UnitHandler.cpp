#include "UnitHandler.h"

Handlers::UnitHandler* Handlers::UnitHandler::p_instance = NULL;


Handlers::UnitHandler::UnitHandler(QObject *parent):QObject(parent){
    initWindSpeedUnitsList();
    initDepthUnitsList();
    initSpeedUnitsList();
}

const QList<QObject *> &Handlers::UnitHandler::windSpeedUnitsList()
{
    return m_windSpeedUnitsList;
}

const QList<QObject *> &Handlers::UnitHandler::depthUnitsList()
{
    return m_depthUnitsList;
}

const QList<QObject *> &Handlers::UnitHandler::speedUnitsList()
{
    return m_speedUnitsList;
}

void Handlers::UnitHandler::changeWindSpeedUnit(short unitIndex)
{
    if(EdoData::Units::WindSpeed::setUnit(unitIndex)){
        emit windSpeedUnitChanged();
    }

}

void Handlers::UnitHandler::changeDepthUnit(short unitIndex)
{
    if(EdoData::Units::Depth::setUnit(unitIndex)){
        emit depthUnitChanged();
    }
}

void Handlers::UnitHandler::changeSpeedUnit(short unitIndex)
{
    if(EdoData::Units::Speed::setUnit(unitIndex)){
        emit speedUnitChanged();
    }
}

void Handlers::UnitHandler::initWindSpeedUnitsList()
{
   m_windSpeedUnitsList.append(&EdoData::Units::WindSpeed::MS);
   m_windSpeedUnitsList.append(&EdoData::Units::WindSpeed::KMH);
   m_windSpeedUnitsList.append(&EdoData::Units::WindSpeed::MPH);
   m_windSpeedUnitsList.append(&EdoData::Units::WindSpeed::KTS);
   m_windSpeedUnitsList.append(&EdoData::Units::WindSpeed::FTS);
   m_windSpeedUnitsList.append(&EdoData::Units::WindSpeed::BF);
}

void Handlers::UnitHandler::initDepthUnitsList()
{
    m_depthUnitsList.append(&EdoData::Units::Depth::METER);
    m_depthUnitsList.append(&EdoData::Units::Depth::FATHOM);
    m_depthUnitsList.append(&EdoData::Units::Depth::FEET);
}

void Handlers::UnitHandler::initSpeedUnitsList()
{
    m_speedUnitsList.append(&EdoData::Units::Speed::MS);
    m_speedUnitsList.append(&EdoData::Units::Speed::KMH);
    m_speedUnitsList.append(&EdoData::Units::Speed::MPH);
    m_speedUnitsList.append(&EdoData::Units::Speed::KTS);
    m_speedUnitsList.append(&EdoData::Units::Speed::FTS);
}
