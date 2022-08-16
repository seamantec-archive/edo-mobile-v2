#include "Environment.h"
#include <QDebug>
#include "edoData/DataModel.h"
EdoData::Environment::Environment::Environment(QObject* parent, ListModel* listModel) : QObject(parent),
    m_trueWind(new EdoData::Environment::Wind("True Wind", this)),
    m_apparentWind(new EdoData::Environment::Wind("Apparent Wind",this)),
    m_water(new EdoData::Environment::Water("Water",this)),
    m_air(new EdoData::Environment::Air("Air",this))
{
    //listModel->append("hello from list");
    listModel->append(this->m_trueWind);
    listModel->append(this->m_apparentWind);
    listModel->append(this->m_water);
    listModel->append(this->m_air);
    //EdoData::DataModel* obj = qobject_cast< EdoData::DataModel*>(parent);
    //obj->hello();
}

EdoData::Environment::Environment::~Environment()
{
  delete m_trueWind;
  delete m_apparentWind;
  delete m_water;
  delete m_air;
}

EdoData::Environment::Wind *EdoData::Environment::Environment::trueWind() const
{
    return m_trueWind;
}

EdoData::Environment::Wind *EdoData::Environment::Environment::apparentWind() const
{
    return m_apparentWind;
}

EdoData::Environment::Water *EdoData::Environment::Environment::water() const
{
    return m_water;
}

EdoData::Environment::Air *EdoData::Environment::Environment::air() const
{
    return m_air;
}
