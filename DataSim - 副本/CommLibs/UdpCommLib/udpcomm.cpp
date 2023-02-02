#include "udpcomm.h"


#include <QNetworkDatagram>
#include <QMutexLocker>
UdpComm::UdpComm(QObject *parent)
    : CommInterface{parent}
{

}

UdpComm::~UdpComm()
{

}

bool UdpComm::init()
{
    return m_socket.bind(m_localAddress, m_localPort);
}

qint32 UdpComm::sendData(const QByteArray &data)
{
    QMutexLocker locker(&m_mutex);
    auto para = m_para.split(":");
    //设置参数优先级高,其次默认
    if(para.size() < 2)
    {
        if(!m_defaultRemoteAddress.isNull())
        {
            setRemote(m_defaultRemoteAddress, m_defaultRemotePort);
        }
        else
        {
            return 0;
        }
    }
    else
    {
        auto strIp = para.at(0);
        auto strPort = para.at(1);

        setRemote(QHostAddress(strIp), strPort.toUInt());
    }


    return m_socket.writeDatagram(data, m_remoteAddress, m_remotePort);
}

void UdpComm::setLocal(const QHostAddress &address, quint16 port)
{
    m_localAddress = address;
    m_localPort = port;
}

void UdpComm::setRemote(const QHostAddress &address, quint16 port)
{
    m_remoteAddress = address;
    m_remotePort = port;
}

void UdpComm::save(QXmlStreamWriter &xml)
{
    xml.writeStartElement("UdpComm");
    xml.writeAttribute("localAddress", m_localAddress.toString());
    xml.writeAttribute("localPort", QString::number(m_localPort));
    xml.writeEndElement();

    CommInterface::save(xml);
}

void UdpComm::load(QDomElement &dom)
{
    auto ucEle = dom.firstChildElement("UdpComm");
    auto ip = ucEle.attribute("localAddress");
    m_localAddress = QHostAddress(ip);
    m_localPort = ucEle.attribute("localPort").toUInt();

    CommInterface::load(dom);
}

QString UdpComm::getInfo()
{
    if(m_remoteAddress.isNull())
    {
        if(m_defaultRemoteAddress.isNull())
        {
            return QString();
        }
        else
        {
            return m_defaultRemoteAddress.toString() + ":" + QString::number(m_defaultRemotePort);
        }
    }
    else
    {
        return m_remoteAddress.toString() + ":" + QString::number(m_remotePort);
    }
}

bool UdpComm::start()
{
    connect(&m_socket, &QUdpSocket::readyRead, this, [&](){


        while(m_socket.pendingDatagramSize() > 0)
        {
            CommData cd;
            cd.st_name = m_name;
            auto dg = m_socket.receiveDatagram();
            cd.st_data = dg.data();
            m_defaultRemoteAddress = dg.senderAddress();
            m_defaultRemotePort = dg.senderPort();
            if(m_bDisplayRecv)
            {
                SHOW_DATA sd;
                sd.info = cd.st_name+"<-(len:" + QString::number(cd.st_data.size()) + ")" ;
                sd.data = cd.st_data;

                qDebug() << 1234124;
                emit sig_showData(sd);
            }
            emit sig_data(cd);
        }
    });
    return true;
}

bool UdpComm::stop()
{
    m_socket.disconnectFromHost();
    m_socket.disconnect();
    return true;
}
