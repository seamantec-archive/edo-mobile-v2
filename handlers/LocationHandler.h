#ifndef LOCATIONHANDLER_H
#define LOCATIONHANDLER_H

#include <QObject>
#include <QGeoCoordinate>
#include <QGeoPositionInfoSource>
#include <QSensor>
#include <QCompass>
#include <QTimer>
#include "handlers/DataHandler.h"

namespace Handlers{
        class LocationHandler  : public QObject
        {
            Q_OBJECT
        public:
            LocationHandler(QObject *parent = 0);
        public slots:
            void positionUpdated(const QGeoPositionInfo &info);
        private slots:
            void compassUpdateHandler();
        private:
            QGeoPositionInfoSource *source;
            QCompass* m_compass;
            QTimer* m_timer;
        };

}

#endif // LOCATIONHANDLER_H
