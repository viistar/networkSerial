#include "newudpdialog.h"
#include "ui_newudpdialog.h"

NewUdpDialog::NewUdpDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewUdpDialog)
{
    ui->setupUi(this);
}

NewUdpDialog::~NewUdpDialog()
{
    delete ui;
}

std::shared_ptr<UdpComm> NewUdpDialog::getUdp()
{
    auto comm = std::make_shared<UdpComm>();
    comm->setName(ui->lineEditName->text());
    comm->m_localAddress = QHostAddress(ui->lineEditIp->text());
    comm->m_localPort = ui->spinBoxPort->value();
    comm->m_bDisplayRecv = ui->checkBoxDisplayData->isChecked();
    return comm;
}


void NewUdpDialog::setUdp(std::shared_ptr<UdpComm> udp)
{
    ui->lineEditName->setText(udp->getName());
    ui->lineEditIp->setText(udp->m_localAddress.toString());
    ui->spinBoxPort->setValue(udp->m_localPort);
    ui->checkBoxDisplayData->setChecked(udp->m_bDisplayRecv);
}


void NewUdpDialog::on_pushButtonConfirm_clicked()
{
    this->accept();
}


void NewUdpDialog::on_pushButtonCancel_clicked()
{
    this->reject();
}

