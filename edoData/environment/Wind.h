#ifndef WIND_H
#define WIND_H

#include <QObject>
#include <QTimer>
#include <QTime>
#include "edoData/BaseEdoData.h"
#include "edoData/units/WindSpeed.h"
#include "edoData/units/Angle.h"
namespace EdoData{
     namespace Environment{
         class Wind : public BaseEdoData
         {
             Q_OBJECT
             Q_PROPERTY(EdoData::Units::Angle* angle READ angle NOTIFY angleChanged)
             Q_PROPERTY(EdoData::Units::WindSpeed* speed READ speed CONSTANT)
         public:
             Wind(QObject *parent = 0);
             Wind(QString displayName, QObject *parent = 0);
             EdoData::Units::Angle* angle() const;
             EdoData::Units::WindSpeed* speed() const;
         signals:
            void angleChanged();
            void speedChanged();
         public slots:
         private:
            EdoData::Units::Angle* m_angle;
            EdoData::Units::WindSpeed* m_speed;
         };
     }
}


#endif // WIND_H
