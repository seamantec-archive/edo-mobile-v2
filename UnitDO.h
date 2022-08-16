#ifndef BASESTRUCTS_H
#define BASESTRUCTS_H

#include <QString>
#include <QObject>
class UnitDO : public QObject
{
    Q_OBJECT
    Q_PROPERTY(short index READ index CONSTANT)
    Q_PROPERTY(float modifier READ modifier CONSTANT)
    Q_PROPERTY(QString shortString READ shortString CONSTANT)
public:

    UnitDO(QObject*parent=0) : QObject(parent){  }
    ~UnitDO(){}
    UnitDO(short index, float modifier, QString shortString,QObject*parent=0);
     const short& index();
     const float& modifier();
     const QString& shortString();

signals:
public slots:

private:
    short m_index;
    float m_modifier;
    QString m_shortString;
};

#endif // BASESTRUCTS_H
