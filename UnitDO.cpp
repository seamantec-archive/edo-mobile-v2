#include "UnitDO.h"

UnitDO::UnitDO(short index, float modifier, QString shortString, QObject *parent) : QObject(parent),
    m_index(index), m_modifier(modifier), m_shortString(shortString){

}

const short &UnitDO::index()
{
    return m_index;
}

const float &UnitDO::modifier()
{
    return m_modifier;
}

const QString &UnitDO::shortString()
{
    return m_shortString;
}
