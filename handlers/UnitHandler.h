#ifndef UNITHANDLER_H
#define UNITHANDLER_H

#include <QObject>
#include <QDebug>
#include <assert.h>
#include <QList>
#include "edoData/units/WindSpeed.h"
#include "edoData/units/Depth.h"
#include "edoData/units/Speed.h"
#include "edoData/units/Direction.h"
#include "edoData/units/Distance.h"
#include "UnitDO.h"

namespace Handlers{
    class UnitHandler : public QObject
    {
        Q_OBJECT
        Q_PROPERTY(QList<QObject*> windSpeedUnitsList READ windSpeedUnitsList CONSTANT)
        Q_PROPERTY(QList<QObject*> depthUnitsList READ depthUnitsList CONSTANT)
        Q_PROPERTY(QList<QObject*> speedUnitsList READ speedUnitsList CONSTANT)
    public:
        UnitHandler(QObject *parent = 0);
        ~UnitHandler(){}
        static UnitHandler* instance(){
            if(p_instance==0){
                p_instance = new UnitHandler();
            }
            return p_instance;
        }


        const QList<QObject*>& windSpeedUnitsList();
        const QList<QObject*>& depthUnitsList();
        const QList<QObject*>& speedUnitsList();

        Q_INVOKABLE void changeWindSpeedUnit(short unitIndex);
        Q_INVOKABLE void changeDepthUnit(short unitIndex);
        Q_INVOKABLE void changeSpeedUnit(short unitIndex);


    signals:
        void windSpeedUnitChanged();
        void depthUnitChanged();
        void speedUnitChanged();
        void distanceUnitChanged();
    public slots:

    private:
        static UnitHandler* p_instance;
        QList<QObject*> m_windSpeedUnitsList;
        QList<QObject*> m_depthUnitsList;
        QList<QObject*> m_speedUnitsList;
        //functions
        void initWindSpeedUnitsList();
        void initDepthUnitsList();
        void initSpeedUnitsList();
    };
}

#endif // UNITHANDLER_H

