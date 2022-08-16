#ifndef ANGLE_H
#define ANGLE_H

#include <QObject>
#include "Unit.h"
namespace EdoData{
    namespace Units{
        class Angle : public Unit
        {
            Q_OBJECT
            Q_PROPERTY(EdoData::MinMax* minMax READ minMax CONSTANT)
        public:
            Angle(QObject *parent = 0);
            Angle(QString displayName, QObject* parent=0);
            MinMax* minMax() const;
        signals:

        public slots:
        protected:
            void calculateValue();
        private:
            MinMax* m_minMax;
             void initialize();
        };
    }
}

#endif // ANGLE_H
