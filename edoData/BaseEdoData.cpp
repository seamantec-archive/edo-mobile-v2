#include "BaseEdoData.h"

EdoData::BaseEdoData::BaseEdoData(QString displayName, QObject *parent) : QObject(parent)
{
    m_displayName = displayName;
}

const QString &EdoData::BaseEdoData::displayName()
{
    return m_displayName;
}

const QList<QObject *> &EdoData::BaseEdoData::propertyList()
{
    return m_propertyList;
}

