#ifndef NAVIGATION_H
#define NAVIGATION_H

#include <QObject>
#include "edoData/ListModel.h"
#include "edoData/units/Speed.h"
#include "edoData/units/Direction.h"
#include "Boat.h"
namespace EdoData {
    namespace Navigation{
        class Navigation : public QObject
        {
            Q_OBJECT
            Q_PROPERTY(EdoData::Navigation::Boat* boat READ boat CONSTANT)
        public:
            explicit Navigation(QObject *parent = 0, ListModel* dataList=NULL);
            ~Navigation();
            Boat* boat() const;

        signals:

        public slots:

        private:
            Boat* m_boat;

        };

    }

}

#endif // NAVIGATION_H
