#include "comminterface.h"

CommInterface::CommInterface(QObject *parent)
    : QObject{parent}
{

}

CommInterface::~CommInterface()
{
    this->disconnect();
}

void CommInterface::save(QXmlStreamWriter &xml)
{
    xml.writeStartElement("CommInterface");
    xml.writeAttribute("name", m_name);
    xml.writeAttribute("para", m_para);
    xml.writeAttribute("display", QString::number(m_bDisplayRecv));
    xml.writeEndElement();
}

void CommInterface::load(QDomElement &dom)
{
    auto ciEle = dom.firstChildElement("CommInterface");

    m_name = ciEle.attribute("name");
    m_para = ciEle.attribute("para");
    m_bDisplayRecv = ciEle.attribute("display").toInt();

}

void CommInterface::setName(const QString &name)
{
    m_name = name;
}

QString CommInterface::getName()
{
    return m_name;
}

void CommInterface::setPara(const QString &para)
{
    m_para = para;
}
