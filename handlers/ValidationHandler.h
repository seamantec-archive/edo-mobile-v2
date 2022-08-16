#ifndef VALIDATIONHANDLER_H
#define VALIDATIONHANDLER_H

#include <QObject>
#include <QVector>
#include <QTimer>

namespace Handlers{
    class ValidationHandler : public QObject
    {
        Q_OBJECT
    public:
        static const short INTERVAL;

        explicit ValidationHandler(QObject *parent = 0);
        int* currentTimestamp();
    signals:
        void timestampChanged(int* currentTimestamp);
        void statusChanged();
        void resetAllData();
    public slots:
        void resetNeed();
    private slots:
        void timerUpdateHandler();
    private:
        QVector<int> m_timestamps;
        QTimer* m_timer;
        int m_currentTimestampCounter;
        void reset();
        void setLastTimestamp();
    };
}

#endif // VALIDATIONHANDLER_H
