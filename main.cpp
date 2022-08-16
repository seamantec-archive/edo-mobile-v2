#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QScreen>
#include <QDebug>

#include "edoData/DataModel.h"
#include "edoData/MinMax.h"
#include "edoData/units/Unit.h"
#include "handlers/UnitHandler.h"
#include "handlers/ConnectionHandler.h"
#include "handlers/DataHandler.h"
#include "connection/TcpConnection.h"
#include "connection/UdpConnection.h"
#include "handlers/LocationHandler.h"
#include "ios/PreventLock.h"
QString Orientation(Qt::ScreenOrientation orientation)
{
    switch (orientation) {
        case Qt::PrimaryOrientation           : return "Primary";
        case Qt::LandscapeOrientation         : return "Landscape";
        case Qt::PortraitOrientation          : return "Portrait";
        case Qt::InvertedLandscapeOrientation : return "Inverted landscape";
        case Qt::InvertedPortraitOrientation  : return "Inverted portrait";
        default                               : return "Unknown";
    }
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    qmlRegisterType<EdoData::BaseEdoData>("com.seamantec.data.baseEdoData", 1,0,"BaseEdoData");
    qmlRegisterType<EdoData::Units::Unit>("com.seamantec.data.units.unit", 1,0,"Unit");
    qmlRegisterType<EdoData::Units::WindSpeed>("com.seamantec.data.units.windSpeed", 1,0,"WindSpeed");
    qmlRegisterType<EdoData::Units::Angle>("com.seamantec.data.units.angle", 1,0,"Angle");
    qmlRegisterType<EdoData::Units::Speed>("com.seamantec.data.units.speeed", 1,0,"Speed");
    qmlRegisterType<EdoData::Units::Direction>("com.seamantec.data.units.direction", 1,0,"Direction");
    qmlRegisterType<EdoData::Units::Distance>("com.seamantec.data.units.distance", 1,0,"Distance");
    qmlRegisterType<EdoData::Environment::Environment>("com.seamantec.data.environment", 1,0,"Environment");
    qmlRegisterType<EdoData::Environment::Wind>("com.seamantec.data.wind", 1,0,"Wind");
    qmlRegisterType<EdoData::Environment::Water>("com.seamantec.data.water", 1,0,"Water");
    qmlRegisterType<EdoData::Environment::Air>("com.seamantec.data.air", 1,0,"Air");
    qmlRegisterType<EdoData::Navigation::Navigation>("com.seamantec.data.navigation", 1,0,"Navigation");
    qmlRegisterType<EdoData::Navigation::Boat>("com.seamantec.data.boat", 1,0,"boat");
    qmlRegisterType<EdoData::ListModel>("com.seamantec.data.listModel", 1,0,"ListModel");
    qmlRegisterType<EdoData::DataModel>("com.seamantec.data.dataModel", 1,0,"d");
    qmlRegisterType<Handlers::UnitHandler>("com.seamantec.handlers.unitHandler", 1,0,"UnitHandler");
    qmlRegisterType<Handlers::ConnectionHandler>("com.seamantec.handlers.ConnectionHandler", 1,0,"ConnectionHandler");
    qmlRegisterType<Connection::TcpConnection>("com.seamantec.connection.tcpConnection", 1,0,"TCPConnection");
    qmlRegisterType<Connection::UdpConnection>("com.seamantec.connection.udpConnection", 1,0,"UDPConnection");
    qmlRegisterType<Connection::Simulation>("com.seamantec.connection.simulation", 1,0,"Simulation");
    qmlRegisterType<UnitDO>("com.seamantec.unitDO", 1,0,"UnitDO");
    qmlRegisterType<EdoData::MinMax>("com.seamantec.data.minMax", 1,0,"MinMax");
    //qmlRegisterSingletonType<Handlers::UnitHandler>("com.seamantec.handlers.unitHandler", 1, 0, "UnitHandler", Handlers::UnitHandler::example_qobject_singletontype_provider);

    Handlers::UnitHandler* unitHandler = Handlers::UnitHandler::instance(); //= Handlers::UnitHandler::instance();
    Handlers::ConnectionHandler* connectionHandler = Handlers::ConnectionHandler::instance();
    Handlers::DataHandler* dataHandler = Handlers::DataHandler::instance();

    Handlers::LocationHandler* locationHandler = new Handlers::LocationHandler();
    //QList<QObject*> dataList;
    //dataList.append(dataModel.environment()->trueWind());
    //dataModel.environment().hello();
    #if defined(Q_OS_IOS)
        PreventLock::setTimerDisabled();
    //#elsif defined(Q_OS_ANDROID)
       //Android stuff ...
    //#else
      //Other stuff ...
    #endif
    qDebug() << "Number of screens:" << QGuiApplication::screens().size();

        qDebug() << "Primary screen:" << QGuiApplication::primaryScreen()->name();
        int dpi;
        int screenWidth;
        int screenHeight;
        foreach (QScreen *screen, QGuiApplication::screens()) {
            qDebug() << "Information for screen:" << screen->name();
            qDebug() << "  Available geometry:" << screen->availableGeometry().x() << screen->availableGeometry().y() << screen->availableGeometry().width() << "x" << screen->availableGeometry().height();
            qDebug() << "  Available size:" << screen->availableSize().width() << "x" << screen->availableSize().height();
            qDebug() << "  Available virtual geometry:" << screen->availableVirtualGeometry().x() << screen->availableVirtualGeometry().y() << screen->availableVirtualGeometry().width() << "x" << screen->availableVirtualGeometry().height();
            qDebug() << "  Available virtual size:" << screen->availableVirtualSize().width() << "x" << screen->availableVirtualSize().height();
            qDebug() << "  Depth:" << screen->depth() << "bits";
            qDebug() << "  Geometry:" << screen->geometry().x() << screen->geometry().y() << screen->geometry().width() << "x" << screen->geometry().height();
            qDebug() << "  Logical DPI:" << screen->logicalDotsPerInch();
            qDebug() << "  Logical DPI X:" << screen->logicalDotsPerInchX();
            qDebug() << "  Logical DPI Y:" << screen->logicalDotsPerInchY();
            qDebug() << "  Orientation:" << Orientation(screen->orientation());
            qDebug() << "  Physical DPI:" << screen->physicalDotsPerInch();
            dpi = screen->physicalDotsPerInch();
            qDebug() << "  Physical DPI X:" << screen->physicalDotsPerInchX();
            qDebug() << "  Physical DPI Y:" << screen->physicalDotsPerInchY();
            qDebug() << "  Physical size:" << screen->physicalSize().width() << "x" << screen->physicalSize().height() << "mm";
            qDebug() << "  Primary orientation:" << Orientation(screen->primaryOrientation());
            qDebug() << "  Refresh rate:" << screen->refreshRate() << "Hz";
            qDebug() << "  Size:" << screen->size().width() << "x" << screen->size().height();
            qDebug() << "  Virtual geometry:" << screen->virtualGeometry().x() << screen->virtualGeometry().y() << screen->virtualGeometry().width() << "x" << screen->virtualGeometry().height();
            qDebug() << "  Virtual size:" << screen->virtualSize().width() << "x" << screen->virtualSize().height();
            screenWidth = screen->virtualSize().width();
            screenHeight = screen->virtualSize().height();

        }
        qDebug() << "App device pixel ratio" << app.devicePixelRatio();

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("screenDpi", dpi*app.devicePixelRatio());
    engine.rootContext()->setContextProperty("screenWidth", screenWidth);
    engine.rootContext()->setContextProperty("screenHeight", screenHeight);
    engine.rootContext()->setContextProperty("dataModel", dynamic_cast<QObject*>(dataHandler->dataModel()));
    engine.rootContext()->setContextProperty("unitHandler", dynamic_cast<QObject*>(unitHandler));
    engine.rootContext()->setContextProperty("connectionHandler", dynamic_cast<QObject*>(connectionHandler));
    //engine.rootContext()->setContextProperty("listModel", QVariant::fromValue(dataList));
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}



