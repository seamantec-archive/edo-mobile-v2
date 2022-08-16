#ifndef DISTANCE_H
#define DISTANCE_H

#include <QObject>
#include "Unit.h"
#include "UnitDO.h"
namespace EdoData{
    namespace Units{
        class Distance : public Unit
        {
            Q_OBJECT
             Q_PROPERTY(EdoData::MinMax* minMax READ minMax CONSTANT)
        public:
            static UnitDO NM;
            static UnitDO MILE;
            static UnitDO KM;
            static UnitDO METER;
            static UnitDO YARD;
            static UnitDO FEET;

            static bool setUnit(short unitIndex);
            static float calculateValueForUnit(float value);

            Distance(QObject *parent = 0);
            Distance(QString displayName, QObject* parent=0);
            MinMax* minMax() const;
        signals:

        public slots:
            void unitChangedSlot();
        protected:
            void calculateValue();
        private:
            static UnitDO* currentUnit;
            MinMax* m_minMax;
            void initialize();

        };
    }
}
#endif // DISTANCE_H
