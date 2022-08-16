#ifndef DATAMODEL_H
#define DATAMODEL_H
#include <QObject>
#include "./environment/Environment.h"
#include "./navigation/Navigation.h"
#include "ListModel.h"
namespace EdoData
{
    class DataModel : public QObject
    {
        Q_OBJECT
        Q_PROPERTY(EdoData::Environment::Environment* environment READ environment CONSTANT)
        Q_PROPERTY(EdoData::Navigation::Navigation* navigation READ navigation CONSTANT)
        Q_PROPERTY(ListModel* listModel READ listModel CONSTANT)

    public:
        explicit DataModel(QObject* parent = 0);
        ~DataModel();
        Environment::Environment* environment() const;
        Navigation::Navigation* navigation() const;
        ListModel *listModel() const;
        void hello();
    signals:
        void listModelChanged();
    public slots:

    private:
        Environment::Environment* m_environment;
        Navigation::Navigation* m_navigation;
        ListModel* m_listModel;
        //communication uuid, mmsi, stb
        //environment(wind, water, air)
        //navigation
        //steering
        //performance

        //TBD
        //propulsion(engine data)
        //electrical
        //alarms from source
        //tanks
        //design
        //sensors
    };

}



#endif // DATAMODEL_H
