#include "WindSpeed.h"
#include "handlers/UnitHandler.h"

UnitDO EdoData::Units::WindSpeed::KTS(0,1,"kts");
UnitDO EdoData::Units::WindSpeed::KMH(1,1.852,"km/h");
UnitDO EdoData::Units::WindSpeed::MPH(2,1.150779,"mph");
UnitDO EdoData::Units::WindSpeed::MS(3,0.514444, "m/s");
UnitDO EdoData::Units::WindSpeed::FTS(4,1.687810,"ft/s");
UnitDO EdoData::Units::WindSpeed::BF(5,-1, "bf");

UnitDO* EdoData::Units::WindSpeed::currentUnit = &EdoData::Units::WindSpeed::KTS;

bool EdoData::Units::WindSpeed::setUnit(short unitIndex)
{
   if(unitIndex == EdoData::Units::WindSpeed::currentUnit->index()){
       return false;
   }
   switch(unitIndex){
    case 0:
       EdoData::Units::WindSpeed::currentUnit = &EdoData::Units::WindSpeed::KTS;
       break;
   case 1:
       EdoData::Units::WindSpeed::currentUnit = &EdoData::Units::WindSpeed::KMH;
       break;
   case 2:
       EdoData::Units::WindSpeed::currentUnit = &EdoData::Units::WindSpeed::MPH;
       break;
   case 3:
       EdoData::Units::WindSpeed::currentUnit = &EdoData::Units::WindSpeed::MS;
       break;
   case 4:
       EdoData::Units::WindSpeed::currentUnit = &EdoData::Units::WindSpeed::FTS;
       break;
   case 5:
       EdoData::Units::WindSpeed::currentUnit = &EdoData::Units::WindSpeed::BF;
       break;
   }
   return true;
}

float EdoData::Units::WindSpeed::calculateValueForUnit(float value)
{
    if(EdoData::Units::WindSpeed::currentUnit != &EdoData::Units::WindSpeed::BF){
          return value * EdoData::Units::WindSpeed::currentUnit->modifier();
    }else{
          if(value < 1){
            return 0;
          }else if(value >= 1 && value <= 3){
              return 1;
          }else if(value > 3 && value <= 6){
              return 2;
          }else if(value > 6 && value <= 10.3){
              return 3;
          }else if(value > 10.3 && value <= 15.1){
              return 4;
          }else if(value > 15.1 && value <= 21){
              return 5;
          }else if(value > 21 && value <= 27){
              return 6;
          }else if(value > 27 && value <= 33){
              return 7;
          }else if(value > 33 && value <= 40){
              return 8;
          }else if(value > 40 && value <= 47){
              return 9;
          }else if(value > 47 && value <= 55){
              return 10;
          }else if(value > 55 && value <= 63){
              return 11;
          }else if(value > 63){
              return 12;
          }
    }
}

float EdoData::Units::WindSpeed::knotsFromMeterPerSec(float value)
{
   return value / EdoData::Units::WindSpeed::MS.modifier();
}

float EdoData::Units::WindSpeed::knotsFromMile(float value)
{
    return  value / EdoData::Units::WindSpeed::MPH.modifier();
}

float EdoData::Units::WindSpeed::knotsFromKm(float value)
{
    return  value / EdoData::Units::WindSpeed::KMH.modifier();
}

EdoData::Units::WindSpeed::WindSpeed(QObject *parent) : Unit("", parent)
{
    initialize();
}


EdoData::Units::WindSpeed::WindSpeed(QString displayName, QObject *parent) : EdoData::Units::Unit(displayName, parent)
{
    initialize();
}

EdoData::MinMax *EdoData::Units::WindSpeed::minMax() const
{
    return m_minMax;
}



void EdoData::Units::WindSpeed::unitChandedSlot()
{
    m_shortUnit = &EdoData::Units::WindSpeed::currentUnit->shortString();
    EdoData::Units::Unit::unitChandedSlot();
}

void EdoData::Units::WindSpeed::calculateValue()
{

    m_minMax->setMinMax(m_value);
    m_stringValue = QString::number(EdoData::Units::WindSpeed::calculateValueForUnit(m_value));
   EdoData::Units::Unit::calculateValue();
}

void EdoData::Units::WindSpeed::initialize()
{
    EdoData::Units::WindSpeed::setUnit(0);
    m_shortUnit =&EdoData::Units::WindSpeed::currentUnit->shortString();
    m_minMax = new MinMax(EdoData::Units::WindSpeed::calculateValueForUnit,this);
    connect(Handlers::UnitHandler::instance(), SIGNAL(windSpeedUnitChanged()),
            this, SLOT(unitChandedSlot()));
}






