#ifndef NMEA0183PARSER_H
#define NMEA0183PARSER_H

#include <QObject>
#include "AbstractParser.h"
#include <QHash>
#include "nmea0183/AbstractNmeaMessage.h"

namespace Parser{
    class NMEA0183Parser : public AbstractParser
    {
        Q_OBJECT
    public:
        static const QString NMEA_START1;
        static const QString NMEA_START2;
        static const QString NMEA_CHKS;

        NMEA0183Parser(QObject *parent = 0);
        void handleMessage(QString message);
    signals:

    public slots:
    private:
        QString m_buffer;
        QHash<QString, Nmea0183::AbstractNmeaMessage*> interpreters;
        bool validateChecksum(QString message);
        void interpret(QStringList* values);

    };
}

#endif // NMEA0183PARSER_H
