#include "Navigation.h"



EdoData::Navigation::Navigation::Navigation(QObject *parent, EdoData::ListModel *dataList) : QObject(parent),
    m_boat(new EdoData::Navigation::Boat("Navigation", this))
{
    dataList->append(this->m_boat);
}

EdoData::Navigation::Navigation::~Navigation()
{

}

EdoData::Navigation::Boat *EdoData::Navigation::Navigation::boat() const
{
    return m_boat;
}

