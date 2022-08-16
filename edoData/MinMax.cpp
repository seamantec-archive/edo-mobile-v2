#include "MinMax.h"
#include "handlers/UnitHandler.h"
#include <QDebug>
EdoData::MinMax::MinMax(QObject *parent) : QObject(parent),
    m_minValid(false), m_maxValid(false), m_unitConverter(dummyCoverter)
{
   initialize();
}

EdoData::MinMax::MinMax(float (*unitConverter)(float), QObject *parent) : QObject(parent),
                m_minValid(false), m_maxValid(false), m_unitConverter(unitConverter)
{
    initialize();
}

void EdoData::MinMax::setMinMax(short value)
{
    if(!m_minValid){
       setMin(value);
       m_minValid = true;

    }else if(value < m_min){
       setMin(value);
    }

    if(!m_maxValid){
        setMax(value);
        m_maxValid = true;
    }else if(value > m_max){
        setMax(value);
    }
}

const QString &EdoData::MinMax::min()
{
    return m_minUnit;
}

const QString &EdoData::MinMax::max()
{
    return m_maxUnit;
}

void EdoData::MinMax::unitChandedSlot()
{
    m_minUnit = QString::number(m_unitConverter(m_min));
    m_maxUnit = QString::number(m_unitConverter(m_max));
    emit minChanged();
    emit maxChanged();
}

void EdoData::MinMax::initialize()
{
    connect(Handlers::UnitHandler::instance(), SIGNAL(windSpeedUnitChanged()),
            this, SLOT(unitChandedSlot()));
}



void EdoData::MinMax::setMin(float value)
{
    m_min = value;
    m_minUnit = QString::number(m_unitConverter(m_min));
    emit minChanged();
}

void EdoData::MinMax::setMax(float value)
{
    m_max = value;
    m_maxUnit = QString::number(m_unitConverter(m_max));
    emit maxChanged();
}

float EdoData::MinMax::dummyCoverter(float value)
{
    return value;
}

