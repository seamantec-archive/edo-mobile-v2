#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <QObject>
#include <QtQml>
#include "Wind.h"
#include "Water.h"
#include "Air.h"
#include "edoData/ListModel.h"
namespace EdoData{
    namespace Environment{    

        class Environment : public QObject
        {
            Q_OBJECT
            Q_PROPERTY(EdoData::Environment::Wind* trueWind READ trueWind CONSTANT)
            Q_PROPERTY(EdoData::Environment::Wind* apparentWind READ apparentWind CONSTANT)
            Q_PROPERTY(EdoData::Environment::Water* water READ water CONSTANT)
            Q_PROPERTY(EdoData::Environment::Air* air READ air CONSTANT)
        public:
            explicit Environment(QObject* parent=0, ListModel* dataList=NULL);
            ~Environment();
            Wind* trueWind() const;
            Wind* apparentWind() const;
            Water* water() const;
            Air* air() const;

        signals:

        public slots:

        private:
            Wind* m_trueWind;
            Wind* m_apparentWind;
            Water* m_water;
            Air* m_air;

        };
    }
 }


#endif // ENVIRONMENT_H
