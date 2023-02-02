QT += gui widgets

TEMPLATE = lib
CONFIG += plugin

CONFIG += c++17

include(../../Common/common.pri)
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    newudpdialog.cpp \
    udpcomm.cpp \
    udpcommplugin.cpp \
    udpinterface.cpp

HEADERS += \
    newudpdialog.h \
    udpcomm.h \
    udpcommplugin.h \
    udpinterface.h

DISTFILES += UdpCommLib.json

INCLUDEPATH += $$PWD/../../Common
# Default rules for deployment.
unix {
    target.path = $$[QT_INSTALL_PLUGINS]/generic
}
!isEmpty(target.path): INSTALLS += target

DESTDIR = $$OUT_PWD/../../simData/commplugin

FORMS += \
    newudpdialog.ui
