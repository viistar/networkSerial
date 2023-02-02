#ifndef UDPCOMMPLUGIN_H
#define UDPCOMMPLUGIN_H

#include <QGenericPlugin>

class UdpCommPlugin : public QGenericPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID QGenericPluginFactoryInterface_iid FILE "UdpCommLib.json")

public:
    explicit UdpCommPlugin(QObject *parent = nullptr);

private:
    QObject *create(const QString &name, const QString &spec) override;
};

#endif // UDPCOMMPLUGIN_H
