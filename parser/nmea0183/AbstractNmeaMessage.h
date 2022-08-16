#ifndef ABSTRACTNMEAMESSAGE_H
#define ABSTRACTNMEAMESSAGE_H

#include <QObject>
namespace Parser{
    namespace Nmea0183{


        class AbstractNmeaMessage : public QObject
        {
            Q_OBJECT
        public:
            explicit AbstractNmeaMessage(QObject *parent = 0);
            virtual void process(QStringList* values)=0;
        signals:

        public slots:
        };

    }
}

#endif // ABSTRACTNMEAMESSAGE_H
