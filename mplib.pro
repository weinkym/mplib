#-------------------------------------------------
#
# Project created by QtCreator 2014-05-21T09:55:31
#
#-------------------------------------------------
TARGET_NAME = mplib
DEFINES_NAME = MPLIB_LIBRARY
###############################################################################
#CONFIG += static
TARGET = $${TARGET_NAME}
###############################################################################
QT       += network
###############################################################################
DEFINES += $${DEFINES_NAME}
###############################################################################
contains(DEFINES, $${DEFINES_NAME}) {
message(DEFINES_NAME)
TEMPLATE = lib
DESTDIR  = ../../../lib
message($${DESTDIR})
}else{
message(TTTTTT)
}
###############################################################################
win32 {
CONFIG(debug, debug|release): OBJECTS_DIR = ../../../TEMP/$${TARGET}/debug
CONFIG(release, debug|release): OBJECTS_DIR = ../../../TEMP/$${TARGET}/release
CONFIG(debug, debug|release) : TARGET = $${TARGET_NAME}d
} else {
OBJECTS_DIR = ../../../TEMP/$${TARGET}
}
###############################################################################
UI_DIR      = $${OBJECTS_DIR}/uic
MOC_DIR     = $${OBJECTS_DIR}/moc
RCC_DIR     = $${OBJECTS_DIR}/rcc
INCLUDEPATH += $${OBJECTS_DIR}/uic

#VERSION########################################################################
# VERSION>4.7 即4.8以上
greaterThan(QT_MAJOR_VERSION, 4) {
QT += widgets
DEFINES += NEED_VERSION_4_8
} else {
greaterThan(QT_MAJOR_VERSION, 3) {
greaterThan(QT_MINOR_VERSION, 7) {
#4.8.4貌似不支持
#DEFINES += NEED_VERSION_4_8
}}}
contains(DEFINES,NEED_VERSION_4_8){
message(WHEEL)
HEADERS += include/zwheelwidget.h
SOURCES += src/zwheelwidget.cpp
}
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
#QMAKE_CC##############################################################################
message(QMAKE_CC is $${QMAKE_CC})
message(QMAKESPEC is $${QMAKESPEC})
contains(QMAKE_CC,cl){
LIBS += -lwinspool
}
contains(QMAKE_CC,gcc){
}
###################################################################INCLUDEPATH
INCLUDEPATH += ./include
#HEADERS################################################################
HEADERS += \
    include/mplib_global.h \
    include/ztextcodec.h \
    include/zrecieveprogressbar.h \
    include/zchatmessagewidget.h \
    include/mplib.h \
    include/zscreenshot.h \
    include/zswitchbutton.h
#SOURCES#####################################################################
SOURCES += \
    src/ztextcodec.cpp \
    src/zrecieveprogressbar.cpp \
    src/zchatmessagewidget.cpp \
    src/mplib.cpp \
    src/zscreenshot.cpp \
    src/zswitchbutton.cpp
#FORMS#####################################################################
FORMS += \
    ./ui/zrecieveprogressbar.ui

RESOURCES += \
    source.qrc
