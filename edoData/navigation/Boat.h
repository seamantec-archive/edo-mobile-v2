#ifndef BOAT_SPEED_H
#define BOAT_SPEED_H

#include <QObject>
#include "edoData/BaseEdoData.h"
#include "edoData/units/Speed.h"
#include "edoData/units/Direction.h"
#include "edoData/units/Unit.h"
namespace EdoData{
    namespace Navigation{
        class Boat :  public BaseEdoData
        {
            Q_OBJECT
            Q_PROPERTY(EdoData::Units::Speed* speedOverGround READ speedOverGround CONSTANT)
            Q_PROPERTY(EdoData::Units::Speed* speedThroughWater READ speedThroughWater CONSTANT)
            Q_PROPERTY(EdoData::Units::Direction* courseOverGroundTrue READ courseOverGroundTrue CONSTANT)
            Q_PROPERTY(EdoData::Units::Direction* courseOverGroundMagnetic READ courseOverGroundMagnetic CONSTANT)
            Q_PROPERTY(EdoData::Units::Unit* magneticVariation READ magneticVariation CONSTANT)
            Q_PROPERTY(EdoData::Units::Direction* headingTrue READ headingTrue CONSTANT)
            Q_PROPERTY(EdoData::Units::Direction* headingMagnetic READ headingMagnetic CONSTANT)
            Q_PROPERTY(EdoData::Units::Unit* lat READ lat CONSTANT)
            Q_PROPERTY(EdoData::Units::Unit* lon READ lon CONSTANT)
        public:
            Boat(QObject *parent = 0);
            Boat(QString displayName, QObject *parent = 0);
            EdoData::Units::Speed *speedOverGround() const;
            EdoData::Units::Speed *speedThroughWater() const;
            EdoData::Units::Direction *courseOverGroundTrue() const;
            EdoData::Units::Direction *courseOverGroundMagnetic() const;
            EdoData::Units::Unit *magneticVariation() const;
            EdoData::Units::Direction *headingTrue() const;
            EdoData::Units::Direction *headingMagnetic() const;
            EdoData::Units::Unit *lat() const;
            EdoData::Units::Unit *lon() const;

        signals:

        public slots:

        private:
          EdoData::Units::Speed* m_speedOverGround;
          EdoData::Units::Speed* m_speedThroughWater;
          EdoData::Units::Direction* m_courseOverGroundTrue;
          EdoData::Units::Direction* m_courseOverGroundMagnetic;
          EdoData::Units::Unit* m_magneticVariation;

          EdoData::Units::Direction* m_headingTrue;
          EdoData::Units::Direction* m_headingMagnetic;

          EdoData::Units::Unit* m_lat;
          EdoData::Units::Unit* m_lon;




        };

    }
}

#endif // SPEED_H
