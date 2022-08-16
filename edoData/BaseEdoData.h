#ifndef BASEEDODATA_H
#define BASEEDODATA_H

#include <QObject>
#include <QList>
namespace EdoData{
    class BaseEdoData : public QObject
    {
        Q_OBJECT
        Q_PROPERTY(QString displayName READ displayName  NOTIFY displayNameChanged)
        Q_PROPERTY(QList<QObject*> propertyList READ propertyList  NOTIFY propertyListChanged)
    public:
        explicit BaseEdoData(QString displayName = "",QObject *parent = 0);
        const QString& displayName();
        const QList<QObject*>& propertyList();
    signals:
        void displayNameChanged();
        void propertyListChanged();
    public slots:

    protected:
        QString m_displayName;
        QList<QObject *> m_propertyList;
    };
}

#endif // BASEEDODATA_H
