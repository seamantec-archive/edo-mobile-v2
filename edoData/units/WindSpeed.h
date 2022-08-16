#ifndef WINDSPEED_H
#define WINDSPEED_H

#include <QObject>
#include "Unit.h"
#include "UnitDO.h"
namespace EdoData{
    namespace Units{
        class WindSpeed : public Unit
        {

            Q_OBJECT
            Q_PROPERTY(EdoData::MinMax* minMax READ minMax CONSTANT)
        public:
            //these should be const too,
            //but when I would use this fields from QList static doesn't work
            //maybe in the future i should create different type of list
            static UnitDO MS  ;
            static UnitDO KMH ;
            static UnitDO MPH ;
            static UnitDO KTS ;
            static UnitDO FTS ;
            static UnitDO BF  ;


            //static functions
            static bool setUnit(short unitIndex);
            static float calculateValueForUnit(float value);
            static float knotsFromMeterPerSec(float value);
            static float knotsFromMile(float value);
            static float knotsFromKm(float value);
            //instance functions
            WindSpeed(QObject* parent=0);
            WindSpeed(QString displayName, QObject* parent=0);
            MinMax* minMax() const;

             //void setValue(short value);


        signals:

        public slots:
            void unitChandedSlot();
        protected:
            void calculateValue();
        private:
            //static variables
            static UnitDO*  currentUnit;

            MinMax* m_minMax;


            void initialize();




        };
    }
}

#endif // WINDSPEED_H
