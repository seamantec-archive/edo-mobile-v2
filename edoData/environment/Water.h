#ifndef WATER_H
#define WATER_H

#include <QObject>
#include "edoData/BaseEdoData.h"
namespace EdoData{
   namespace Environment{
        class Water : public BaseEdoData
        {
            Q_OBJECT
            Q_PROPERTY(short depthBelowKeel READ depthBelowKeel NOTIFY depthBelowKeelChanged);
            Q_PROPERTY(short depthBelowTransducer READ depthBelowTransducer NOTIFY depthBelowTransducerChanged);
            Q_PROPERTY(short depthBelowSurface READ depthBelowSurface NOTIFY depthBelowSurfaceChanged);
            Q_PROPERTY(short depthTransducerToKeel READ depthTransducerToKeel NOTIFY depthtransducerToKeelChanged);
            Q_PROPERTY(short surfaceToTransducer READ surfaceToTransducer NOTIFY surfaceToTransducerChanged);
            Q_PROPERTY(short waterTemp READ waterTemp NOTIFY waterTempChanged);
            Q_PROPERTY(short tide READ tide NOTIFY tideChanged);
            Q_PROPERTY(short salinity READ salinity NOTIFY salinityChanged);
        public:
            Water(QObject *parent = 0);
            Water(QString displayName, QObject *parent = 0);
            const short& depthBelowKeel();
            const short& depthBelowTransducer();
            const short& depthBelowSurface();
            const short& depthTransducerToKeel();
            const short& surfaceToTransducer();
            const short& waterTemp();
            const short& tide();
            const short& salinity();
        signals:
            void depthBelowKeelChanged();
            void depthBelowTransducerChanged();
            void depthBelowSurfaceChanged();
            void depthtransducerToKeelChanged();
            void surfaceToTransducerChanged();
            void waterTempChanged();
            void tideChanged();
            void salinityChanged();
        public slots:

        private:
            short m_depthBelowKeel;
            short m_depthBelowTransducer;
            short m_depthBelowSurface;
            short m_depthTransducerToKeel;
            short m_surfaceToTransducer;
            short m_waterTemp;
            short m_tide;
            short m_salinity;

        };
   }
}

#endif // WATER_H
