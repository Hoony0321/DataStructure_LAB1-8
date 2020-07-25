QT       += core gui sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    adminmainwindow.cpp \
    alertwindow.cpp \
    inputwindow.cpp \
    jobofferermainwindow.cpp \
    jobseekermainwindow.cpp \
    listwindow.cpp \
    loginfailedwindow.cpp \
    loginwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    offerer_searchbycondition.cpp \
    offerer_searchresult.cpp \
    searchresultlist.cpp \
    seeker_searchbycondition.cpp \
    signupwindow.cpp \
    surveywindow.cpp

HEADERS += \
    adminmainwindow.h \
    alertwindow.h \
    inputwindow.h \
    jobofferermainwindow.h \
    jobseekermainwindow.h \
    listwindow.h \
    loginfailedwindow.h \
    loginwindow.h \
    mainwindow.h \
    offerer_searchbycondition.h \
    offerer_searchresult.h \
    searchresultlist.h \
    seeker_searchbycondition.h \
    signupwindow.h \
    surveywindow.h

FORMS += \
    adminmainwindow.ui \
    alertwindow.ui \
    inputwindow.ui \
    jobofferermainwindow.ui \
    jobseekermainwindow.ui \
    listwindow.ui \
    loginfailedwindow.ui \
    loginwindow.ui \
    mainwindow.ui \
    offerer_searchbycondition.ui \
    offerer_searchresult.ui \
    searchresultlist.ui \
    seeker_searchbycondition.ui \
    signupwindow.ui \
    surveywindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
