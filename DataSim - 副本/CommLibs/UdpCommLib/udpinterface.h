#ifndef UDPINTERFACE_H
#define UDPINTERFACE_H

#include "commlibinterface.h"

class UdpInterface : public CommLibInterface
{
    Q_OBJECT
public:
    UdpInterface(QObject* parent = nullptr);

    void init() override;
    QString name() override;
    QString className() override;

    std::optional<std::shared_ptr<CommInterface>> create() override;
    std::optional<std::shared_ptr<CommInterface>> edit(std::shared_ptr<CommInterface> old) override;
};

#endif // UDPINTERFACE_H
