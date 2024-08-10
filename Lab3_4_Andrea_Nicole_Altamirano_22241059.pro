QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Alimento.cpp \
    Circulo.cpp \
    ComandoFormato.cpp \
    Electronico.cpp \
    Figura.cpp \
    Producto.cpp \
    Rectangulo.cpp \
    Ropa.cpp \
    Tarea.cpp \
    TareaDiaria.cpp \
    TareaSemanal.cpp \
    Triangulo.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Alimento.h \
    Circulo.h \
    ComandoFormato.h \
    Electronico.h \
    Figura.h \
    Producto.h \
    Rectangulo.h \
    Ropa.h \
    Tarea.h \
    TareaDiaria.h \
    TareaSemanal.h \
    Triangulo.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
