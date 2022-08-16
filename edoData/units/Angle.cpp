#include "Angle.h"



EdoData::Units::Angle::Angle(QObject *parent) : Unit("", parent)
{
    initialize();
}

EdoData::Units::Angle::Angle(QString displayName, QObject *parent) : Unit(displayName, parent)
{
    initialize();
}

EdoData::MinMax *EdoData::Units::Angle::minMax() const
{
    return m_minMax;
}

void EdoData::Units::Angle::calculateValue()
{
    m_minMax->setMinMax(m_value);
    m_stringValue = QString::number(m_value);
    EdoData::Units::Unit::calculateValue();
}

void EdoData::Units::Angle::initialize()
{
  m_shortUnit =  new QString("°");
  m_minMax = new MinMax(this);
}

