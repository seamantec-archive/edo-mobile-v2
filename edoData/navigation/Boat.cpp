#include "Boat.h"



EdoData::Navigation::Boat::Boat(QObject *parent) : BaseEdoData("", parent)
{

}

EdoData::Navigation::Boat::Boat(QString displayName, QObject *parent) : BaseEdoData(displayName, parent)
{
    m_speedOverGround = new EdoData::Units::Speed("Speed over ground", this);
    m_speedThroughWater = new EdoData::Units::Speed("Speed through water", this);
    m_courseOverGroundTrue = new EdoData::Units::Direction("Course over ground(True)", this);
    m_courseOverGroundMagnetic = new EdoData::Units::Direction("Course over ground(Magnetic)", this);
    m_headingTrue = new EdoData::Units::Direction("Heading(True)", this);
    m_headingMagnetic = new EdoData::Units::Direction("Heading(Magnetic)", this);
    m_magneticVariation = new EdoData::Units::Unit("Magnetic variation", this);
    m_lat = new EdoData::Units::Unit("Position Lattitude", this);
    m_lon = new EdoData::Units::Unit("Position Longitude", this);
    m_propertyList.append(m_speedOverGround);
    m_propertyList.append(m_speedThroughWater);
    m_propertyList.append(m_courseOverGroundTrue);
    m_propertyList.append(m_courseOverGroundMagnetic);
    m_propertyList.append(m_headingTrue);
    m_propertyList.append(m_headingMagnetic);
    //m_propertyList.append(m_magneticVariation);
    //m_propertyList.append(m_lat);
    //m_propertyList.append(m_lon);

}

EdoData::Units::Speed *EdoData::Navigation::Boat::speedOverGround() const
{
    return m_speedOverGround;
}

EdoData::Units::Speed *EdoData::Navigation::Boat::speedThroughWater() const
{
    return m_speedThroughWater;
}

EdoData::Units::Direction *EdoData::Navigation::Boat::courseOverGroundTrue() const
{
    return m_courseOverGroundTrue;
}

EdoData::Units::Direction *EdoData::Navigation::Boat::courseOverGroundMagnetic() const
{
    return m_courseOverGroundMagnetic;
}

EdoData::Units::Unit *EdoData::Navigation::Boat::magneticVariation() const
{
    return m_magneticVariation;
}

EdoData::Units::Direction *EdoData::Navigation::Boat::headingTrue() const
{
    return m_headingTrue;
}

EdoData::Units::Direction *EdoData::Navigation::Boat::headingMagnetic() const
{
    return m_headingMagnetic;
}

EdoData::Units::Unit *EdoData::Navigation::Boat::lat() const
{
    return m_lat;
}

EdoData::Units::Unit *EdoData::Navigation::Boat::lon() const
{
    return m_lon;
}
