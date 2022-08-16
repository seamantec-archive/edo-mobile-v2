#include "Direction.h"


EdoData::Units::Direction::Direction(QObject *parent) : Unit("", parent)
{
    initialize();
}

EdoData::Units::Direction::Direction(QString displayName, QObject *parent) : Unit(displayName, parent)
{
    initialize();
}

EdoData::MinMax *EdoData::Units::Direction::minMax() const
{
    return m_minMax;
}
void EdoData::Units::Direction::initialize()
{
  m_shortUnit =  new QString("°");
  m_minMax = new MinMax(this);
}

void EdoData::Units::Direction::calculateValue()
{

    m_minMax->setMinMax(m_value);
    EdoData::Units::Unit::calculateValue();
}
