#ifndef POSITION_H
#define POSITION_H

#include <QObject>
#include "edoData/BaseEdoData.h"
#include "edoData/units/Unit.h"
namespace EdoData{
    namespace Navigation {


        class Position : public BaseEdoData
        {
            Q_OBJECT
        public:
            explicit Position(QObject *parent = 0);
            explicit Position(QString displayName, QObject *parent = 0);

        signals:
            void latChanged();
            void lonChanged();
            void altitudeChanged();
        public slots:

        private:
            EdoData::Units::Unit* m_lat;
            EdoData::Units::Unit* m_lon;
            EdoData::Units::Unit* altitude;
        };

    }
}

#endif // POSITION_H
