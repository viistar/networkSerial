#ifndef UDPCOMM_H
#define UDPCOMM_H

#include "comminterface.h"
#include <QObject>
#include <QHostAddress>
#include <QUdpSocket>
#include <QMutex>
class UdpComm : public CommInterface
{
    Q_OBJECT
public:
    Q_INVOKABLE explicit UdpComm(QObject *parent = nullptr);
    virtual ~UdpComm();

    bool init() override;
    qint32 sendData(const QByteArray& data) override;

    void setLocal(const QHostAddress& address, quint16 port);
    void setRemote(const QHostAddress& address, quint16 port);

    void save(QXmlStreamWriter& xml) override;
    void load(QDomElement& dom) override;

    QString getInfo() override;

    bool start() override;
    bool stop() override;
private:
    friend class NewUdpDialog;
    QMutex m_mutex;
    QHostAddress m_localAddress;
    quint16 m_localPort;

    QHostAddress m_remoteAddress;
    quint16 m_remotePort;
    QHostAddress m_defaultRemoteAddress;
    quint16 m_defaultRemotePort;

    QUdpSocket m_socket;

};

Q_DECLARE_METATYPE(UdpComm)

#endif // UDPCOMM_H
