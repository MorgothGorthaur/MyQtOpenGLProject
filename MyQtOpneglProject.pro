QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    cube.cpp \
    dialog.cpp \
    figure.cpp \
    line.cpp \
    main.cpp \
    mainwindow.cpp \
    squarepyramid.cpp \
    test.cpp \
    trianglepyramid.cpp \
    workGL.cpp

HEADERS += \
    cube.h \
    dialog.h \
    figure.h \
    line.h \
    mainwindow.h \
    squarepyramid.h \
    test.h \
    trianglepyramid.h \
    workGL.h

FORMS += \
    dialog.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
