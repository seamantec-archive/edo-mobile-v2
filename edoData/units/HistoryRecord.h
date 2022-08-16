#ifndef HISTORYRECORD_H
#define HISTORYRECORD_H

#include <QObject>
namespace EdoData {
    namespace Units{
        class HistoryRecord : public QObject
        {
            Q_OBJECT
            Q_PROPERTY(int timestamp READ timestamp CONSTANT)
            Q_PROPERTY(float value READ value CONSTANT)
            Q_PROPERTY(bool isValid READ isValid CONSTANT)
        public:
            HistoryRecord(QObject *parent = 0);
            HistoryRecord(int* timestamp, float value,bool isValid, QObject *parent = 0);
            int* timestamp() const;
            const float &value();
            const bool &isValid();
        signals:

        public slots:
        private:
            int* m_timestamp;
            float m_value;
            bool m_isValid;
        };

    }

}

#endif // HISTORYRECORD_H
