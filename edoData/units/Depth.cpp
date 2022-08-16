#include "Depth.h"
#include "handlers/UnitHandler.h"

UnitDO EdoData::Units::Depth::METER(0,1,"m");
UnitDO EdoData::Units::Depth::FATHOM(1,0.546806649,"fa");
UnitDO EdoData::Units::Depth::FEET(2,3.2808399,"f");

UnitDO* EdoData::Units::Depth::currentUnit = &EdoData::Units::Depth::METER;

bool EdoData::Units::Depth::setUnit(short unitIndex)
{
    if(unitIndex == EdoData::Units::Depth::currentUnit->index()){
        return false;
    }
    switch(unitIndex){
     case 0:
        EdoData::Units::Depth::currentUnit = &EdoData::Units::Depth::METER;
        break;
    case 1:
        EdoData::Units::Depth::currentUnit = &EdoData::Units::Depth::FATHOM;
        break;
    case 2:
        EdoData::Units::Depth::currentUnit = &EdoData::Units::Depth::FEET;
        break;

    }
    return true;
}

float EdoData::Units::Depth::calculateValueForUnit(float value)
{
    return value * EdoData::Units::Depth::currentUnit->modifier();
}

EdoData::Units::Depth::Depth(QObject *parent): EdoData::Units::Unit("", parent)
{
    initialize();
}

EdoData::Units::Depth::Depth(QString displayName, QObject *parent) : EdoData::Units::Unit(displayName, parent)
{
    initialize();
}



EdoData::MinMax *EdoData::Units::Depth::minMax() const
{
    return m_minMax;
}

void EdoData::Units::Depth::unitChandedSlot()
{
    //TODO ez igy nem biztos hogy jo
    m_shortUnit =&EdoData::Units::Depth::currentUnit->shortString();
    EdoData::Units::Unit::unitChandedSlot();
}

void EdoData::Units::Depth::calculateValue()
{
    m_minMax->setMinMax(m_value);
    m_stringValue = QString::number(m_value);
    EdoData::Units::Unit::calculateValue();
}

void EdoData::Units::Depth::initialize()
{
    EdoData::Units::Depth::setUnit(0);
    m_shortUnit =&EdoData::Units::Depth::currentUnit->shortString();
    m_minMax = new MinMax(EdoData::Units::Depth::calculateValueForUnit,this);
    connect(Handlers::UnitHandler::instance(), SIGNAL(depthUnitChanged()),
            this, SLOT(unitChandedSlot()));
}
