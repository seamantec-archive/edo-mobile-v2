#ifndef NMEAMWVMESSAGE_H
#define NMEAMWVMESSAGE_H

#include <QObject>
#include "AbstractNmeaMessage.h"
#include "handlers/DataHandler.h"

namespace Parser{
    namespace Nmea0183{


        class NmeaMwvMessage : public AbstractNmeaMessage
        {
            Q_OBJECT
        public:
            explicit NmeaMwvMessage(QObject *parent = 0);
            void process(QStringList *values);
        signals:

        public slots:

        private:
            void setValues(EdoData::Environment::Wind* wind, QStringList *values);
        };

    }
}

#endif // NMEAMWVMESSAGE_H
