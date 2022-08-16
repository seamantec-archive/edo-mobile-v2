#include "Wind.h"

EdoData::Environment::Wind::Wind(QObject *parent) : BaseEdoData("", parent)
{

}

EdoData::Environment::Wind::Wind(QString displayName, QObject *parent) : BaseEdoData(displayName, parent)
{
    m_speed = new EdoData::Units::WindSpeed("Speed", this);
    m_angle = new EdoData::Units::Angle("Angle", this);
   //m_speed->setValue(30);
   //m_angle->setValue(10);

    m_propertyList.append(m_speed);
    m_propertyList.append(m_angle);
//    QTimer *timer = new QTimer(this);
//        connect(timer, SIGNAL(timeout()), this, SLOT(update()));
//        timer->start(2000);
}


EdoData::Units::Angle* EdoData::Environment::Wind::angle() const
{
    return m_angle;
}



EdoData::Units::WindSpeed *EdoData::Environment::Wind::speed() const
{
  return m_speed;
}



