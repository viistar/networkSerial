#ifndef NEWUDPDIALOG_H
#define NEWUDPDIALOG_H

#include <QDialog>
#include "udpcomm.h"

namespace Ui {
class NewUdpDialog;
}

class NewUdpDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewUdpDialog(QWidget *parent = nullptr);
    ~NewUdpDialog();
    std::shared_ptr<UdpComm> getUdp();
    void setUdp(std::shared_ptr<UdpComm> udp);


private slots:
    void on_pushButtonConfirm_clicked();

    void on_pushButtonCancel_clicked();

private:
    Ui::NewUdpDialog *ui;
};

#endif // NEWUDPDIALOG_H
