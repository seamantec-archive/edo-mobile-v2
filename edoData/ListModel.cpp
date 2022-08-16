#include "ListModel.h"



EdoData::ListModel::ListModel(QObject *parent) : QObject(parent)
{
    //m_model << "One" << "Two" << "Three" << "Four" << "Five";
}

const QList<QObject *> &EdoData::ListModel::model()
{
    return m_model;
}

void EdoData::ListModel::append(QObject *object)
{
    m_model.append(object);
    emit modelChanged();
}




