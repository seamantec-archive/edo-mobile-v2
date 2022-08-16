#include "Water.h"

EdoData::Environment::Water::Water(QObject *parent)
{

}

EdoData::Environment::Water::Water(QString displayName, QObject *parent) : BaseEdoData(displayName, parent)
{

}


const short &EdoData::Environment::Water::depthBelowKeel()
{
    return m_depthBelowKeel;
}

const short &EdoData::Environment::Water::depthBelowTransducer()
{
    return m_depthBelowTransducer;
}

const short &EdoData::Environment::Water::depthBelowSurface()
{
    return m_depthBelowSurface;
}

const short &EdoData::Environment::Water::depthTransducerToKeel()
{
    return m_depthTransducerToKeel;
}

const short &EdoData::Environment::Water::surfaceToTransducer()
{
   return m_surfaceToTransducer;
}

const short &EdoData::Environment::Water::waterTemp()
{
    return m_waterTemp;
}

const short &EdoData::Environment::Water::tide()
{
    return m_tide;
}

const short &EdoData::Environment::Water::salinity()
{
    return m_salinity;
}
