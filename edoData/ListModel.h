#ifndef LISTMODEL_H
#define LISTMODEL_H
#include <QObject>
#include <QList>
#include "edoData/BaseEdoData.h"
namespace EdoData{
    class ListModel : public QObject
    {

        Q_OBJECT
        Q_PROPERTY(QList<QObject*> model READ model NOTIFY modelChanged)
    public:
       explicit ListModel(QObject* parent = 0);
        const QList<QObject*>& model();
        void append(QObject* object);
    signals:
        void modelChanged();
    public slots:

    private:
       QList<QObject*> m_model;
    };
}

#endif // LISTMODEL_H
