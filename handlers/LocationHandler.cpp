#include "LocationHandler.h"
#include <QDebug>


Handlers::LocationHandler::LocationHandler(QObject *parent) : QObject(parent)
{

    #if defined(Q_OS_IOS)
        m_compass = new QCompass(this);
        m_compass->start();

        source = QGeoPositionInfoSource::createDefaultSource(0);
              if (source) {

                  source->setUpdateInterval(500);// 1 second
                  connect(source, SIGNAL(positionUpdated(QGeoPositionInfo)),
                          this, SLOT(positionUpdated(QGeoPositionInfo)));

                  source->startUpdates();
               }
    #endif
              m_timer = new QTimer(this);
              connect(m_timer, SIGNAL(timeout()), this, SLOT(compassUpdateHandler()));
               m_timer->start(500);
}

void Handlers::LocationHandler::positionUpdated(const QGeoPositionInfo &info)
{
  Handlers::DataHandler* dataHandler = Handlers::DataHandler::instance();
    float speed = info.attribute(QGeoPositionInfo::GroundSpeed);
    float direction = info.attribute(QGeoPositionInfo::Direction);
    //NaN validation
    if(speed == speed){
        dataHandler->dataModel()->navigation()->boat()->speedOverGround()->setValue(EdoData::Units::Speed::knotsFromMeterPerSec(speed),
                                                                                    EdoData::Units::Unit::DataSources::SENSOR,0);
    }
    if(direction == direction){
        dataHandler->dataModel()->navigation()->boat()->courseOverGroundTrue()->setValue(direction,
                                                                                     EdoData::Units::Unit::DataSources::SENSOR, 0);
    }
    
    
}

void Handlers::LocationHandler::compassUpdateHandler()
{
    Handlers::DataHandler* dataHandler = Handlers::DataHandler::instance();
    #if defined(Q_OS_IOS)

    if(m_compass && m_compass->isActive()){
        dataHandler->dataModel()->navigation()->boat()->headingTrue()->setValue(m_compass->reading()->azimuth(), EdoData::Units::Unit::DataSources::SENSOR, 0);
    }
    #else
        int rand = (qrand() % ((359 + 1) - 0));
        //qDebug() << "RANDOM HEADING: " << rand;
        dataHandler->dataModel()->navigation()->boat()->headingTrue()->setValue(rand, EdoData::Units::Unit::DataSources::SENSOR, 0);
    #endif
}



