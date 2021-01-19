QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

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
    src/test/java/special/special8/Main.cpp \
    src/test/java/special/special8/StreamReader.cpp \
    src/test/java/special/special8/DefaultCharStream.cc \
    src/test/java/special/special8/DefaultToken.cc \
    src/test/java/special/special8/ParseException.cc \
    src/test/java/special/special8/SpecialToken.cc \
    src/test/java/special/special8/SpecialTokenTokenManager.cc \
    src/test/java/special/special8/TokenManagerError.cc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    src/test/java/special/special8/StreamReader.h \
    src/test/java/special/special8/CharStream.h \
    src/test/java/special/special8/DefaultCharStream.h \
    src/test/java/special/special8/DefaultToken.h \
    src/test/java/special/special8/ErrorHandler.h \
    src/test/java/special/special8/JavaCC.h \
    src/test/java/special/special8/ParseException.h \
    src/test/java/special/special8/SpecialToken.h \
    src/test/java/special/special8/SpecialTokenConstants.h \
    src/test/java/special/special8/SpecialTokenTokenManager.h \
    src/test/java/special/special8/Token.h \
    src/test/java/special/special8/TokenManager.h \
    src/test/java/special/special8/TokenManagerError.h
