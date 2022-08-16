#ifndef AIR_H
#define AIR_H

#include <QObject>
#include "edoData/BaseEdoData.h"
namespace EdoData{
   namespace Environment{
       class Air : public BaseEdoData
       {
           Q_OBJECT
           Q_PROPERTY(short pressure READ pressure NOTIFY pressureChanged);
           Q_PROPERTY(short temperature READ temperature NOTIFY temperatureChanged);
           Q_PROPERTY(short humidity READ humidity NOTIFY humidityChanged);

       public:
           Air(QObject *parent = 0);
           Air(QString displayName, QObject *parent = 0);
           const short& pressure();
           const short& temperature();
           const short& humidity();
       signals:
            void pressureChanged();
            void temperatureChanged();
            void humidityChanged();
       public slots:

       private:
           short m_pressure;
           short m_temperature;
           short m_humidity;
       };

   }
}

#endif // AIR_H
