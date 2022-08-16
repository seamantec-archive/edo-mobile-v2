#include "NMEA0183Parser.h"
#include "nmea0183/NmeaMwvMessage.h"

const QString Parser::NMEA0183Parser::NMEA_START1 = "$";
const QString Parser::NMEA0183Parser::NMEA_START2 = "!";
const QString Parser::NMEA0183Parser::NMEA_CHKS = "*";

Parser::NMEA0183Parser::NMEA0183Parser(QObject *parent) : AbstractParser(parent)
{
    interpreters.insert("mwv", new Parser::Nmea0183::NmeaMwvMessage(this));
}

void Parser::NMEA0183Parser::handleMessage(QString message)
{
   m_buffer += message;
   m_buffer.replace(QRegExp("(\\r\\n)+"), "\n");
   QStringList messages = m_buffer.split("\n");
   int messagesSize = messages.size();
   QString currentMessage;
   QStringList values;
   for (int i = 0; i < messagesSize; i++) {
        currentMessage = messages[i];
        if(!currentMessage.startsWith(NMEA_START1) && !currentMessage.startsWith(NMEA_START2)){
            //qDebug() << "Broken message: " << currentMessage;
            if(messagesSize >1 && i==0){
                //drop first broken message
                m_buffer.replace(currentMessage+"\n", "");
                continue;
            }
        }

        if((currentMessage.startsWith(NMEA_START1) || currentMessage.startsWith(NMEA_START2)) &&
                currentMessage.at(currentMessage.length()-3) == NMEA_CHKS){
            //qDebug()<<currentMessage;
            if(validateChecksum(currentMessage)){
                values = currentMessage.right(currentMessage.size()-3).left(currentMessage.size()-6).split(",");
                interpret(&values);
            }else{
             //   qDebug() << "Checksum invalid";
            }


            m_buffer.replace(currentMessage+"\n", "");
        }

   }
   //qDebug() << messages.size();
   //qDebug() << "BUFFER:" << m_buffer;
}

bool Parser::NMEA0183Parser::validateChecksum(QString message)
{
    int checksum = 0;
    int messageLength = message.length();
    QString originalChecksum = message.right(2);
    for (int i = 1; i < messageLength-3; i++) {
        checksum ^= message.at(i).unicode();
    }
    if (originalChecksum.at(0) == '0') {
            originalChecksum = originalChecksum.right(1);
       }
    if((originalChecksum.toLower() !=  QString::number(checksum, 16).toLower())){
      //qDebug()<<"checksum: "  << originalChecksum.toLower() << "||" << QString::number(checksum, 16).toLower();
    }

    return (originalChecksum.toLower() ==  QString::number(checksum, 16).toLower());
}

void Parser::NMEA0183Parser::interpret(QStringList* values)
{
    QString key = values->at(0).toLower();
    Parser::Nmea0183::AbstractNmeaMessage* interpreter = interpreters[key];
    if(interpreter != NULL){
        interpreter->process(values);
    }
}

