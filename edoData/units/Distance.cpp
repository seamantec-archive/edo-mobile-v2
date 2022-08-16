#include "Distance.h"
#include "handlers/UnitHandler.h"

UnitDO EdoData::Units::Distance::NM(0,1,"nm");
UnitDO EdoData::Units::Distance::MILE(1,1.150779,"mi");
UnitDO EdoData::Units::Distance::KM(2,1.852,"km");
UnitDO EdoData::Units::Distance::METER(3,1852,"m");
UnitDO EdoData::Units::Distance::YARD(4,2025.372,"yd");
UnitDO EdoData::Units::Distance::FEET(5,6076.1155,"ft");

UnitDO* EdoData::Units::Distance::currentUnit = &EdoData::Units::Distance::NM;

bool EdoData::Units::Distance::setUnit(short unitIndex)
{
    if(unitIndex == EdoData::Units::Distance::currentUnit->index()){
        return false;
    }
    switch(unitIndex){
        case 0:
            EdoData::Units::Distance::currentUnit = &EdoData::Units::Distance::NM;
            break;
        case 1:
            EdoData::Units::Distance::currentUnit = &EdoData::Units::Distance::MILE;
            break;
        case 2:
            EdoData::Units::Distance::currentUnit = &EdoData::Units::Distance::KM;
            break;
        case 3:
            EdoData::Units::Distance::currentUnit = &EdoData::Units::Distance::METER;
            break;
        case 4:
            EdoData::Units::Distance::currentUnit = &EdoData::Units::Distance::YARD;
            break;
        case 5:
            EdoData::Units::Distance::currentUnit = &EdoData::Units::Distance::FEET;
            break;
    }
    return true;

}

float EdoData::Units::Distance::calculateValueForUnit(float value)
{
        return value * EdoData::Units::Distance::currentUnit->modifier();
}

EdoData::Units::Distance::Distance(QObject *parent) : Unit("", parent)
{
  initialize();
}

EdoData::Units::Distance::Distance(QString displayName, QObject *parent) : EdoData::Units::Unit(displayName, parent)
{
    initialize();
}

EdoData::MinMax *EdoData::Units::Distance::minMax() const
{
    return m_minMax;
}

void EdoData::Units::Distance::unitChangedSlot()
{
    m_shortUnit =&EdoData::Units::Distance::currentUnit->shortString();
    EdoData::Units::Unit::unitChandedSlot();
}

void EdoData::Units::Distance::calculateValue()
{
    m_minMax->setMinMax(m_value);
    m_stringValue = QString::number(EdoData::Units::Distance::calculateValueForUnit(m_value));
    EdoData::Units::Unit::calculateValue();
}

void EdoData::Units::Distance::initialize()
{
    EdoData::Units::Distance::setUnit(0);
    m_shortUnit =&EdoData::Units::Distance::currentUnit->shortString();
    m_minMax = new MinMax(EdoData::Units::Distance::calculateValueForUnit,this);
    connect(Handlers::UnitHandler::instance(), SIGNAL(distanceUnitChanged()),
            this, SLOT(unitChandedSlot()));
}
