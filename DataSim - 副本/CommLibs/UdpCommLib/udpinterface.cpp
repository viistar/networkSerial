#include "udpinterface.h"
#include "newudpdialog.h"

UdpInterface::UdpInterface(QObject *parent)
    :CommLibInterface(parent)
{

}

void UdpInterface::init()
{
    qRegisterMetaType<UdpComm>();
}

QString UdpInterface::name()
{
    return "UDP";
}

QString UdpInterface::className()
{
    return "UdpComm";
}

std::optional<std::shared_ptr<CommInterface> > UdpInterface::create()
{
    NewUdpDialog dialog;

    if(QDialog::Accepted == dialog.exec())
    {
        return dialog.getUdp();
    }

    return std::nullopt;
}

std::optional<std::shared_ptr<CommInterface> > UdpInterface::edit(std::shared_ptr<CommInterface> old)
{
    NewUdpDialog dialog;
    dialog.setUdp(std::dynamic_pointer_cast<UdpComm>(old));

    if(QDialog::Accepted == dialog.exec())
    {
        return dialog.getUdp();
    }

    return std::nullopt;
}
