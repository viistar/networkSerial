#ifndef COMMLIBINTERFACE_H
#define COMMLIBINTERFACE_H

#include "comminterface.h"

#include <QObject>
#include <optional>

class CommLibInterface : public QObject
{
    Q_OBJECT
public:
    CommLibInterface(QObject* parent = nullptr):QObject(parent){}
    virtual ~CommLibInterface(){}

    virtual void init() = 0;
    /*!
     * \brief name 接口对应的名称
     * \return
     */
    virtual QString name() = 0;
    /*!
     * \brief className .必须返回接口类对应的类名
     * \return
     */
    virtual QString className() = 0;

    virtual std::optional<std::shared_ptr<CommInterface>> create() = 0;

    /*!
     * \brief 传入要修改的接口，返回修改后的接口
     * \param old
     * \return
     */
    virtual std::optional<std::shared_ptr<CommInterface>> edit(std::shared_ptr<CommInterface> old) = 0;
signals:

};


#endif // COMMLIBINTERFACE_H
