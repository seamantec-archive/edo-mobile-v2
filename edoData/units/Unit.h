
#ifndef UNIT_H
#define UNIT_H

#include <QObject>
#include <QDebug>
#include <QList>
#include "edoData/MinMax.h"
#include "HistoryRecord.h"
namespace EdoData{
    namespace Units{
        class Unit : public QObject
        {
            Q_OBJECT
            Q_PROPERTY(QString displayName READ displayName CONSTANT)
            Q_PROPERTY(float value READ value NOTIFY valueChanged)
            Q_PROPERTY(QString fullValueString READ fullValueString NOTIFY valueChanged)
            Q_PROPERTY(QString decimal READ decimal NOTIFY valueChanged)
            Q_PROPERTY(QString whole READ whole NOTIFY valueChanged)
            Q_PROPERTY(QString shortUnit READ shortUnit NOTIFY shortUnitChanged)
            Q_PROPERTY(bool isValid READ isValid  NOTIFY statusChanged)
            Q_PROPERTY(bool isPending READ isPending  NOTIFY statusChanged)
            Q_PROPERTY(QList<QObject*> history READ history NOTIFY historyChanged)
            Q_PROPERTY(int max_history READ max_history CONSTANT)


        public:
            enum DataSources{SENSOR, BT, NETWORK};


            static const QString invalidString;
            static const QString invalidDecimal;
            static const QString emptyString;
            static const int PENDING_LIMIT;
            static const int INVALID_LIMIT;
            static const float ZERO_VALUE;
            static const int MAX_HISTORY;
            explicit Unit(QString displayName="",QObject *parent = 0);
            const QString& displayName();
            const QString& fullValueString();
            const float& value();
            const QString& decimal();
            const QString& whole();
            void setValue(float value, DataSources sourceLevel, short dataLevel);
            const QString& shortUnit();
            bool isValid();
            bool isPending();
            const QList<QObject*>& history();
            const int& max_history();
        signals:
            void valueChanged();
            void statusChanged();
            void shortUnitChanged();
            void historyChanged();
        public slots:
            void unitChandedSlot();
            void resetHandler();
        private slots:
            void timestampChanged(int* lastTimestamp);
        protected:
            enum ValidStatus{NOT_VALID, VALID, PENDING};
            QList<QObject*> m_history;
            QString m_displayName;
            float m_value;
            QString m_stringValue;
            QString m_whole;
            QString m_decimal;
            ValidStatus m_valid;
            const QString* m_shortUnit;
            int* m_timestamp;
            virtual void calculateValue();
            void setStatus(ValidStatus status);
            void addRecordToHistory();
            short m_currentDataLevel;
            short m_currentSourceLevel;

        };
    }
}
#endif // UNIT_H
