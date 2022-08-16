#include "NmeaMwvMessage.h"
#include <QDebug>

Parser::Nmea0183::NmeaMwvMessage::NmeaMwvMessage(QObject *parent) : Parser::Nmea0183::AbstractNmeaMessage(parent)
{

}


/*
 MWV - Wind Speed and Angle

 1   2 3   4 5
 |   | |   | |
 $--MWV,x.x,a,x.x,a*hh<CR><LF>
 $WIMWV,5.6,R,7.4,S,A*3E
 Field Number:
 1) Wind Angle, 0 to 360 degrees
 2) Reference, R = Relative, T = True
 3) Wind Speed
 4) Wind Speed Units, K/M/N
 5) Status, A = Data Valid
 6) Checksum
 */
void Parser::Nmea0183::NmeaMwvMessage::process(QStringList *values)
{
    Handlers::DataHandler* dataHandler = Handlers::DataHandler::instance();
    EdoData::Environment::Wind* trueWind = dataHandler->dataModel()->environment()->trueWind();
    EdoData::Environment::Wind* apparentWind = dataHandler->dataModel()->environment()->apparentWind();
    if(values->at(5) == "A"){
        if(values->at(2) == "T"){
            //True wind
            setValues(trueWind, values);

        }else if(values->at(2) == "R"){
            //Apparent
            setValues(apparentWind, values);
        }
    }
}

void Parser::Nmea0183::NmeaMwvMessage::setValues(EdoData::Environment::Wind *wind, QStringList *values)
{
    if(values->at(1).length() > 0){
        wind->angle()->setValue(values->at(1).toFloat(), EdoData::Units::Unit::DataSources::NETWORK, 3);
    }
    Handlers::DataHandler* dataHandler = Handlers::DataHandler::instance();
    dataHandler->dataModel()->navigation()->boat()->headingTrue()->setValue(values->at(1).toFloat(), EdoData::Units::Unit::DataSources::NETWORK, 0);
    if(values->at(3).length() > 0){
        float speed = values->at(3).toFloat();
        QString unitString = values->at(4);
        if( unitString == "N" || unitString == "n"){
          wind->speed()->setValue(speed, EdoData::Units::Unit::DataSources::NETWORK, 3);
        }else if(unitString == "M" || unitString == "m"){
          wind->speed()->setValue(EdoData::Units::WindSpeed::knotsFromMeterPerSec(speed), EdoData::Units::Unit::DataSources::NETWORK, 3);
        }else if(unitString == "K" || unitString == "k"){
          wind->speed()->setValue(EdoData::Units::WindSpeed::knotsFromKm(speed), EdoData::Units::Unit::DataSources::NETWORK, 3);
        }
    }
}
