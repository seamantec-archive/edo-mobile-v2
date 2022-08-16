#ifndef DEPTH_H
#define DEPTH_H

#include <QObject>

#include "Unit.h"
#include "UnitDO.h"
namespace EdoData{
    namespace Units{
        class Depth : public Unit
        {
            Q_OBJECT
            Q_PROPERTY(EdoData::MinMax* minMax READ minMax CONSTANT)
        public:
            static UnitDO METER;
            static UnitDO FATHOM;
            static UnitDO FEET;

            //static functions
            static bool setUnit(short unitIndex);
            static float calculateValueForUnit(float value);

            Depth(QObject *parent = 0);
            Depth(QString displayName, QObject* parent=0);

            MinMax* minMax() const;
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

#endif // DEPTH_H
