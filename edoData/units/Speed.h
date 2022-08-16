#ifndef SPEED_H
#define SPEED_H

#include <QObject>
#include "Unit.h"
#include "UnitDO.h"
namespace EdoData{
    namespace Units{
            class Speed : public Unit
            {
                Q_OBJECT
                Q_PROPERTY(EdoData::MinMax* minMax READ minMax CONSTANT)

            public:
                static UnitDO MS  ;
                static UnitDO KMH ;
                static UnitDO MPH ;
                static UnitDO KTS ;
                static UnitDO FTS ;

                //static functions
                static bool setUnit(short unitString);
                static float calculateValueForUnit(float value);
                static float knotsFromMeterPerSec(float value);
                static float knotsFromMile(float value);
                static float knotsFromKm(float value);

                Speed(QObject *parent = 0);
                Speed(QString displayName, QObject *parent = 0);
                MinMax* minMax() const;

            signals:

            public slots:
                void unitChandedSlot();

            protected:
                void calculateValue();

            private:
                static UnitDO*  currentUnit;

                MinMax* m_minMax;


                void initialize();

            };

    }
}
#endif // SPEED_H
