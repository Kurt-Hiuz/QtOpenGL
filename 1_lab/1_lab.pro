QT       += core gui openglwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    appMenu/appmenu.cpp \
    main.cpp \
    mainwindow.cpp \
    oglpainter/oglpainter.cpp \
    dialogWindows/addNewFigureDialogWindow/addnewfiguredialogwindow.cpp \
    dialogWindows/i_dialogwindow.cpp \
    testFolder/oglsquare.cpp \
    testFolder2/nooglsquare2.cpp

HEADERS += \
    appMenu/appmenu.h \
    mainwindow.h \
    oglpainter/oglpainter.h \
    dialogWindows/addNewFigureDialogWindow/addnewfiguredialogwindow.h \
    dialogWindows/i_dialogwindow.h \
    testFolder/oglsquare.h \
    testFolder2/nooglsquare2.h

FORMS += \
    mainwindow.ui

LIBS += -lopengl32

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
