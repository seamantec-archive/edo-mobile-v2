#include "Unit.h"
#include "edoData/units/WindSpeed.h"
#include "handlers/DataHandler.h"
#include <QDebug>
const QString EdoData::Units::Unit::invalidString = "---";
const QString EdoData::Units::Unit::invalidDecimal = "-";
const QString EdoData::Units::Unit::emptyString = "";
const int EdoData::Units::Unit::PENDING_LIMIT = 30000;
const int EdoData::Units::Unit::INVALID_LIMIT = 60000;
const float EdoData::Units::Unit::ZERO_VALUE = 0.0;
const int EdoData::Units::Unit::MAX_HISTORY = 60;


EdoData::Units::Unit::Unit(QString displayName,QObject *parent) : QObject(parent),
    m_displayName(displayName), m_valid(NOT_VALID)
{   
    m_currentDataLevel = -1;
    m_currentSourceLevel = -1;
    connect(Handlers::DataHandler::instance()->validationHandler(), SIGNAL(timestampChanged(int*)),
            this, SLOT(timestampChanged(int*)));    
    connect(Handlers::DataHandler::instance()->validationHandler(), SIGNAL(resetAllData()),
            this, SLOT(resetHandler()));
}

const QString &EdoData::Units::Unit::displayName()
{
    return m_displayName;
}

const QString &EdoData::Units::Unit::fullValueString()
{
    if(m_valid == NOT_VALID){
        return EdoData::Units::Unit::invalidString;
    }else{
        return m_stringValue;
    }
}

const float& EdoData::Units::Unit::value()
{
    if(m_valid != NOT_VALID){
        return m_value;
    }
    return ZERO_VALUE;
}

const QString& EdoData::Units::Unit::decimal()
{
    if(m_valid == NOT_VALID){
        return EdoData::Units::Unit::invalidDecimal;
    }else{
        return m_decimal;
    }
}

const QString& EdoData::Units::Unit::whole()
{
    if(m_valid == NOT_VALID){
        return EdoData::Units::Unit::invalidString;
    }else{
        return m_whole;
    }
}

void EdoData::Units::Unit::setValue(float value, DataSources sourceLevel, short dataLevel)
{
    //if value NaN
   if(value != value){
       return;
   }

    if(sourceLevel < m_currentSourceLevel || (sourceLevel == m_currentSourceLevel && dataLevel < m_currentDataLevel)){
       return;
    }

   //change source to higher prio source
   if(sourceLevel > m_currentSourceLevel){
       m_currentSourceLevel = sourceLevel;
       m_currentDataLevel = dataLevel;
   }else if(sourceLevel == m_currentSourceLevel && dataLevel > m_currentDataLevel){ //change data level higher but the source stay the same
       m_currentDataLevel = dataLevel;
   }
   if(m_value != value){
        m_value = value;       
        m_stringValue = QString::number(value);
        if(fmodf(m_value,1) != 0){
            QStringList splitted = m_stringValue.split(".");
            if(splitted.length() > 1){
                m_whole = splitted.at(0);
                m_decimal = splitted.at(1).at(0);
                }
        }else{
            m_decimal = "0";
            m_whole = m_stringValue;
        }
        setStatus(VALID);
        calculateValue();
    }
    m_timestamp = Handlers::DataHandler::instance()->validationHandler()->currentTimestamp();

}


const QString &EdoData::Units::Unit::shortUnit()
{
    return *m_shortUnit;
}

bool EdoData::Units::Unit::isValid()
{
    return m_valid != NOT_VALID;
}

bool EdoData::Units::Unit::isPending()
{
    return m_valid == PENDING;
}

 const QList<QObject *>& EdoData::Units::Unit::history()
{
     return m_history;
 }

 const int &EdoData::Units::Unit::max_history()
 {
     return MAX_HISTORY;
 }





void EdoData::Units::Unit::unitChandedSlot()
{
    calculateValue();
    emit shortUnitChanged();
}

void EdoData::Units::Unit::resetHandler()
{
    m_currentSourceLevel = SENSOR;
    m_currentDataLevel = -1;
    setStatus(NOT_VALID);

}

void EdoData::Units::Unit::timestampChanged(int *lastTimestamp)
{
    if(isValid() && m_timestamp != NULL && lastTimestamp != NULL){
        int diff = *lastTimestamp - *m_timestamp;
        if(diff > INVALID_LIMIT){
            setStatus(NOT_VALID);
        }else if(diff > PENDING_LIMIT){
            setStatus(PENDING);
        }
    }
    addRecordToHistory();
}

void EdoData::Units::Unit::calculateValue()
{
    emit valueChanged();
}

void EdoData::Units::Unit::setStatus(EdoData::Units::Unit::ValidStatus status)
{
    if(status != m_valid){
        m_valid = status;
        emit valueChanged();
        emit statusChanged();
    }
}

void EdoData::Units::Unit::addRecordToHistory()
{
    if(m_history.length() == MAX_HISTORY){
       QObject* last = m_history.takeLast();
       delete last;
    }
    bool isValueValid = isPending() || isValid();
    m_history.prepend(new EdoData::Units::HistoryRecord(m_timestamp, m_value,isValueValid, this));
    emit historyChanged();
}
