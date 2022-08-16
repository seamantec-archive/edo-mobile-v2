#ifndef MINMAX_H
#define MINMAX_H

#include <QObject>

namespace EdoData{
    class MinMax : public QObject
    {
        Q_OBJECT
        Q_PROPERTY(QString min READ min NOTIFY minChanged)
        Q_PROPERTY(QString max READ max NOTIFY maxChanged)
    public:
        MinMax(QObject *parent = 0);
        MinMax(float(*unitConverter)(float), QObject *parent = 0);
        void setMinMax(short value);
        const QString& min();
        const QString& max();
    signals:
        void minChanged();
        void maxChanged();
    public slots:
        void unitChandedSlot();
    private:
        //TODO set unit value
        float m_min;
        float m_max;
        QString m_minUnit;
        QString m_maxUnit;
        bool m_minValid;
        bool m_maxValid;

        void initialize();
        void setMin(float value);
        void setMax(float value);

        float(*m_unitConverter)(float);
        static float dummyCoverter(float value);

    };
}

#endif // MINMAX_H
