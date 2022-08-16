#include "Speed.h"
#include "handlers/UnitHandler.h"

UnitDO EdoData::Units::Speed::KTS(0,1,"kts");
UnitDO EdoData::Units::Speed::KMH(1,1.852,"km/h");
UnitDO EdoData::Units::Speed::MPH(2,1.150779,"mph");
UnitDO EdoData::Units::Speed::MS(3,0.514444, "m/s");
UnitDO EdoData::Units::Speed::FTS(4,1.687810,"ft/s");

UnitDO* EdoData::Units::Speed::currentUnit = &EdoData::Units::Speed::KMH;

bool EdoData::Units::Speed::setUnit(short unitIndex)
{
   if(unitIndex == EdoData::Units::Speed::currentUnit->index()){
       return false;
   }
   switch(unitIndex){
    case 0:
       EdoData::Units::Speed::currentUnit = &EdoData::Units::Speed::KTS;
       break;
   case 1:
       EdoData::Units::Speed::currentUnit = &EdoData::Units::Speed::KMH;
       break;
   case 2:
       EdoData::Units::Speed::currentUnit = &EdoData::Units::Speed::MPH;
       break;
   case 3:
       EdoData::Units::Speed::currentUnit = &EdoData::Units::Speed::MS;
       break;
   case 4:
       EdoData::Units::Speed::currentUnit = &EdoData::Units::Speed::FTS;
       break;
   }
   return true;
}

float EdoData::Units::Speed::calculateValueForUnit(float value)
{
    return value * EdoData::Units::Speed::currentUnit->modifier();
}

float EdoData::Units::Speed::knotsFromMeterPerSec(float value)
{
   return value / EdoData::Units::Speed::MS.modifier();
}

float EdoData::Units::Speed::knotsFromMile(float value)
{
    return  value / EdoData::Units::Speed::MPH.modifier();
}

float EdoData::Units::Speed::knotsFromKm(float value)
{
    return  value / EdoData::Units::Speed::KMH.modifier();
}

EdoData::Units::Speed::Speed(QObject *parent) : Unit("", parent)
{
    initialize();
}


EdoData::Units::Speed::Speed(QString displayName, QObject *parent) : EdoData::Units::Unit(displayName, parent)
{
    initialize();
}

EdoData::MinMax *EdoData::Units::Speed::minMax() const
{
    return m_minMax;
}



void EdoData::Units::Speed::unitChandedSlot()
{
    m_shortUnit = &EdoData::Units::Speed::currentUnit->shortString();
    EdoData::Units::Unit::unitChandedSlot();
}

void EdoData::Units::Speed::calculateValue()
{

    m_minMax->setMinMax(m_value);
    m_stringValue = QString::number(EdoData::Units::Speed::calculateValueForUnit(m_value));
   EdoData::Units::Unit::calculateValue();
}

void EdoData::Units::Speed::initialize()
{
    EdoData::Units::Speed::setUnit(1);
    m_shortUnit =&EdoData::Units::Speed::currentUnit->shortString();
    m_minMax = new MinMax(EdoData::Units::Speed::calculateValueForUnit,this);
    connect(Handlers::UnitHandler::instance(), SIGNAL(speedUnitChanged()),
            this, SLOT(unitChandedSlot()));
}
