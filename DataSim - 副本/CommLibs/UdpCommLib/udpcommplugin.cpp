#include "udpcommplugin.h"
#include "udpinterface.h"
#include <QDebug>

UdpCommPlugin::UdpCommPlugin(QObject *parent)
    : QGenericPlugin(parent)
{
}

QObject *UdpCommPlugin::create(const QString &name, const QString &spec)
{
    return new UdpInterface;
}
