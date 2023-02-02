#ifndef COMMINTERFACE_H
#define COMMINTERFACE_H

#include "mtypes.h"

#include <QObject>
#include <QXmlStreamWriter>
#include <QDomElement>

struct CommData{
    QString st_name;
    QByteArray st_data;
};

class CommInterface : public QObject
{
    Q_OBJECT
public:
    explicit CommInterface(QObject *parent = nullptr);
    virtual ~CommInterface();

    virtual bool init() = 0;
    virtual qint32 sendData(const QByteArray& data) = 0;
    virtual bool start() = 0;
    virtual bool stop() = 0;


    virtual QString getInfo(){return QString();}

    virtual void save(QXmlStreamWriter& xml);
    virtual void load(QDomElement& dom);

    void setName(const QString& name);
    QString getName();

    void setPara(const QString& para);

signals:
    void sig_data(CommData);
    void sig_showData(SHOW_DATA sd);
    void sig_showStatus(QString info);

protected:
    QString m_name;
    QString m_para;

    bool m_bDisplayRecv = true;
};



#endif // COMMINTERFACE_H
