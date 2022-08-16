#ifndef DIRECTION_H
#define DIRECTION_H

#include <QObject>
#include "Unit.h"
namespace EdoData{
    namespace Units{
        class Direction : public Unit
        {
            Q_OBJECT
            Q_PROPERTY(EdoData::MinMax* minMax READ minMax CONSTANT)
        public:
            Direction(QObject *parent = 0);
            Direction(QString displayName, QObject* parent=0);
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

#endif // DIRECTION_H
