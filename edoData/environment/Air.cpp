#include "Air.h"

EdoData::Environment::Air::Air(QObject *parent)
{

}

EdoData::Environment::Air::Air(QString displayName, QObject *parent) : BaseEdoData(displayName, parent)
{

}

const short &EdoData::Environment::Air::pressure()
{
    return m_pressure;
}

const short &EdoData::Environment::Air::temperature()
{
    return m_temperature;
}

const short &EdoData::Environment::Air::humidity()
{
    return m_humidity;
}

