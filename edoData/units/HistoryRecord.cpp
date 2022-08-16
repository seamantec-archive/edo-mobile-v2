#include "HistoryRecord.h"

EdoData::Units::HistoryRecord::HistoryRecord(QObject *parent) : QObject(parent)
{

}

EdoData::Units::HistoryRecord::HistoryRecord(int *timestamp, float value, bool isValid, QObject *parent) : QObject(parent),
    m_timestamp(timestamp), m_value(value), m_isValid(isValid)
{

}

int *EdoData::Units::HistoryRecord::timestamp() const
{
    return m_timestamp;
}

const float &EdoData::Units::HistoryRecord::value()
{
    return m_value;

}

const bool &EdoData::Units::HistoryRecord::isValid()
{
    return m_isValid;
}
