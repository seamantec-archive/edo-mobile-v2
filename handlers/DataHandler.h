#ifndef DATAHANDLER_H
#define DATAHANDLER_H

#include <QObject>
#include "parser/AbstractParser.h"
#include "parser/NMEA0183Parser.h"
#include "ValidationHandler.h"
#include "edoData/DataModel.h"

namespace Handlers{
    class DataHandler : public QObject
    {
        Q_OBJECT
    public:
        DataHandler(QObject *parent = 0);
        static DataHandler* instance(){
            if(p_instance == NULL){
                p_instance = new DataHandler();
                p_instance->initialize();
            }
            return p_instance;
        }

        void handleMessage(QString message);
        EdoData::DataModel* dataModel();
        ValidationHandler *validationHandler() const;

    signals:

    public slots:

    private:
       static DataHandler* p_instance;
       void initialize();
       Parser::AbstractParser* m_currentParser;
       Parser::NMEA0183Parser m_nmea0183Parser;
       ValidationHandler* m_validationHandler;
       EdoData::DataModel* m_dataModel;
    };
}

#endif // DATAHANDLER_H
