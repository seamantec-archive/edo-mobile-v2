#include "DataModel.h"
#include <QDebug>

EdoData::DataModel::DataModel(QObject *parent) : QObject(parent)
{
    m_listModel = new ListModel(this);    
    m_environment= new EdoData::Environment::Environment(this, m_listModel);
    m_navigation = new EdoData::Navigation::Navigation(this, m_listModel);
    //m_dataList.append(new Data::Environment::Wind());
}

EdoData::DataModel::~DataModel()
{
  delete m_environment;
  delete m_navigation;
}

EdoData::Environment::Environment* EdoData::DataModel::environment() const
{
    return m_environment;
}

EdoData::Navigation::Navigation *EdoData::DataModel::navigation() const
{
    return m_navigation;
}

EdoData::ListModel *EdoData::DataModel::listModel() const
{
 return m_listModel;
}


void EdoData::DataModel::hello()
{
    emit listModelChanged();
}





