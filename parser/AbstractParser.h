#ifndef ABSTRACTPARSER_H
#define ABSTRACTPARSER_H

#include <QObject>
#include <QDebug>

namespace Parser{
    class AbstractParser : public QObject
    {
        Q_OBJECT
    public:
        explicit AbstractParser(QObject *parent = 0);
        virtual void handleMessage(QString message) = 0;
    signals:

    public slots:
    };
}

#endif // ABSTRACTPARSER_H
