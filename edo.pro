TEMPLATE = app

QT += qml quick widgets network
QT += positioning sensors
CONFIG(release, debug|release): DEFINES += QT_NO_DEBUG_OUTPUT
SOURCES += main.cpp \
    edoData/units/WindSpeed.cpp \
    edoData/environment/Air.cpp \
    edoData/environment/Environment.cpp \
    edoData/environment/Water.cpp \
    edoData/environment/Wind.cpp \
    edoData/units/Unit.cpp \
    edoData/BaseEdoData.cpp \
    edoData/DataModel.cpp \
    edoData/ListModel.cpp \
    edoData/units/Angle.cpp \
    handlers/UnitHandler.cpp \
    UnitDO.cpp \
    edoData/MinMax.cpp \
    edoData/units/Depth.cpp \
    handlers/ConnectionHandler.cpp \
    connection/TcpConnection.cpp \
    connection/UdpConnection.cpp \
    handlers/DataHandler.cpp \
    parser/AbstractParser.cpp \
    parser/NMEA0183Parser.cpp \
    parser/nmea0183/AbstractNmeaMessage.cpp \
    parser/nmea0183/NmeaMwvMessage.cpp \
    handlers/ValidationHandler.cpp \
    handlers/LocationHandler.cpp \
    edoData/units/Direction.cpp \
    edoData/navigation/Navigation.cpp \
    edoData/navigation/Position.cpp \
    edoData/units/Speed.cpp \
    edoData/navigation/Boat.cpp \
    edoData/units/HistoryRecord.cpp \
    connection/Simulation.cpp \
    edoData/units/Distance.cpp

RESOURCES += qml.qrc \
    InstrumentAssets.qrc \
    fonts.qrc \
    images.qrc \
    Statics.qrc


# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    edoData/units/WindSpeed.h \
    edoData/environment/Air.h \
    edoData/environment/Environment.h \
    edoData/environment/Water.h \
    edoData/environment/Wind.h \
    edoData/units/Unit.h \
    edoData/BaseEdoData.h \
    edoData/DataModel.h \
    edoData/ListModel.h \
    edoData/units/Angle.h \
    handlers/UnitHandler.h \
    UnitDO.h \
    edoData/MinMax.h \
    edoData/units/Depth.h \
    handlers/ConnectionHandler.h \
    connection/AbstractConnection.h \
    connection/TcpConnection.h \
    connection/UdpConnection.h \
    handlers/DataHandler.h \
    parser/AbstractParser.h \
    parser/NMEA0183Parser.h \
    parser/nmea0183/AbstractNmeaMessage.h \
    parser/nmea0183/NmeaMwvMessage.h \
    handlers/ValidationHandler.h \
    handlers/LocationHandler.h \
    edoData/units/Direction.h \
    edoData/navigation/Navigation.h \
    edoData/navigation/Position.h \
    edoData/units/Speed.h \
    edoData/navigation/Boat.h \
    ios/PreventLock.h \
    edoData/units/HistoryRecord.h \
    connection/Simulation.h \
    edoData/units/Distance.h

ios {
    QMAKE_INFO_PLIST = ios/Info.plist    
    OBJECTIVE_SOURCES += \
        ios/PreventLock.mm
}

DISTFILES +=


