#ifndef ABSTRACTCONNECTION_H
#define ABSTRACTCONNECTION_H

#include <QObject>
namespace Connection{
    class AbstractConnection : public QObject
    {
        Q_OBJECT
    public:
        enum ConnectionStatus{
            Connected,
            NotConnected
        };
        Q_ENUM(ConnectionStatus)

        AbstractConnection(QObject *parent = 0) : QObject(parent), m_status(NotConnected){};
        virtual void connectToHost() = 0;
        virtual void disconnectFromHost() = 0;
        const ConnectionStatus& status(){
            return m_status;
        }

        bool isConnected(){
            return m_status == Connected;
        }


    signals:
        void statusChanged();
    public slots:
    protected:
        ConnectionStatus m_status;
        void setStatus(ConnectionStatus status){
            m_status = status;
            emit statusChanged();
        }

    private:
        // Q_DECLARE_PRIVATE(AbstractConnection)
        Q_DISABLE_COPY(AbstractConnection)
    };
}

#endif // ABSTRACTCONNECTION_H
