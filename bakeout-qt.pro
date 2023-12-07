QT       += core gui uitools xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
TARGET = $$(HOME)/bin/bakeout-qt

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    heaters1to8.cpp \
    heaters9to16.cpp \
    main.cpp \
    mainwindow.cpp \
    tempgraphs1to8.cpp \
    tempgraphs9to16.cpp

HEADERS += \
    heaters1to8.h \
    heaters9to16.h \
    mainwindow.h \
    tempgraphs1to8.h \
    tempgraphs9to16.h

FORMS += \
    heaters1to8.ui \
    heaters9to16.ui \
    mainwindow.ui \
    tempgraphs1to8.ui \
    tempgraphs9to16.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

unix:!macx: LIBS += \
    -L$$(QE_TARGET_DIR)/lib/linux-x86_64/ \
    -L$$(QE_TARGET_DIR)/lib/linux-x86_64/designer \
    -L$$(QWT_ROOT)/lib/ \
    -L$$(EPICS_BASE)/lib/linux-x86_64/ \
    -lca -lCom -lqwt -lQEFramework -lQEPlugin

INCLUDEPATH += \
    $$(QE_TARGET_DIR)/include \
    $$(QWT_ROOT)/include \
    $$(EPICS_BASE)/include \
    $$(EPICS_BASE)/include/os/Linux \
    $$(EPICS_BASE)/include/compiler/gcc/

DEPENDPATH += \
    $$(QE_TARGET_DIR)/include \
    $$(QWT_ROOT)/include \
    $$(EPICS_BASE)/include \
    $$(EPICS_BASE)/include/os/Linux
