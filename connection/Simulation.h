#ifndef SIMULATION_H
#define SIMULATION_H

#include <QObject>
#include "AbstractConnection.h"
#include <QTimer>
#include <QFile>
#include <QTextStream>
namespace Connection{
    class Simulation : public AbstractConnection
    {
        Q_OBJECT
    public:
        Simulation(QObject *parent = 0);
        void connectToHost();
        void disconnectFromHost();
    signals:

    public slots:
    private slots:
        void timerUpdateHandler();
    private:
        QTimer* m_timer;
        QFile* m_file;
        QTextStream* m_in;
        bool isFileOpen;
    };
}

#endif // SIMULATION_H
