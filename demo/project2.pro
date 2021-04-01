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
    src/main/java/javacc7/ASTAddNode.cc \
    src/main/java/javacc7/ASTAndNode.cc \
    src/main/java/javacc7/ASTAssignment.cc \
    src/main/java/javacc7/ASTBitwiseAndNode.cc \
    src/main/java/javacc7/ASTBitwiseComplNode.cc \
    src/main/java/javacc7/ASTBitwiseOrNode.cc \
    src/main/java/javacc7/ASTBitwiseXorNode.cc \
    src/main/java/javacc7/ASTCompilationUnit.cc \
    src/main/java/javacc7/ASTDivNode.cc \
    src/main/java/javacc7/ASTEQNode.cc \
    src/main/java/javacc7/ASTFalseNode.cc \
    src/main/java/javacc7/ASTGENode.cc \
    src/main/java/javacc7/ASTGTNode.cc \
    src/main/java/javacc7/ASTId.cc \
    src/main/java/javacc7/ASTIntConstNode.cc \
    src/main/java/javacc7/ASTLENode.cc \
    src/main/java/javacc7/ASTLTNode.cc \
    src/main/java/javacc7/ASTModNode.cc \
    src/main/java/javacc7/ASTMulNode.cc \
    src/main/java/javacc7/ASTNENode.cc \
    src/main/java/javacc7/ASTNotNode.cc \
    src/main/java/javacc7/ASTOrNode.cc \
    src/main/java/javacc7/ASTReadStatement.cc \
    src/main/java/javacc7/ASTSubtractNode.cc \
    src/main/java/javacc7/ASTTrueNode.cc \
    src/main/java/javacc7/ASTVarDeclaration.cc \
    src/main/java/javacc7/ASTWriteStatement.cc \
    src/main/java/javacc7/Boolean.cpp \
    src/main/java/javacc7/CharStream.cc \
    src/main/java/javacc7/DumpVisitor.cpp \
    src/main/java/javacc7/Integer.cpp \
    src/main/java/javacc7/Interpret.cpp \
    src/main/java/javacc7/JJTSPLParserState.cc \
    src/main/java/javacc7/Object.cpp \
    src/main/java/javacc7/ParseException.cc \
    src/main/java/javacc7/SPLC.cpp \
    src/main/java/javacc7/SPLParser.cc \
    src/main/java/javacc7/SPLParserTokenManager.cc \
    src/main/java/javacc7/SimpleNode.cc \
    src/main/java/javacc7/Token.cc \
    src/main/java/javacc7/TokenMgrError.cc \
    src/main/java/javacc7/Variable.cpp \
    src/main/java/javacc7/getopt.c

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    src/main/java/javacc7/ASTAddNode.h \
    src/main/java/javacc7/ASTAndNode.h \
    src/main/java/javacc7/ASTAssignment.h \
    src/main/java/javacc7/ASTBitwiseAndNode.h \
    src/main/java/javacc7/ASTBitwiseComplNode.h \
    src/main/java/javacc7/ASTBitwiseOrNode.h \
    src/main/java/javacc7/ASTBitwiseXorNode.h \
    src/main/java/javacc7/ASTCompilationUnit.h \
    src/main/java/javacc7/ASTDivNode.h \
    src/main/java/javacc7/ASTEQNode.h \
    src/main/java/javacc7/ASTFalseNode.h \
    src/main/java/javacc7/ASTGENode.h \
    src/main/java/javacc7/ASTGTNode.h \
    src/main/java/javacc7/ASTId.h \
    src/main/java/javacc7/ASTIntConstNode.h \
    src/main/java/javacc7/ASTLENode.h \
    src/main/java/javacc7/ASTLTNode.h \
    src/main/java/javacc7/ASTModNode.h \
    src/main/java/javacc7/ASTMulNode.h \
    src/main/java/javacc7/ASTNENode.h \
    src/main/java/javacc7/ASTNotNode.h \
    src/main/java/javacc7/ASTOrNode.h \
    src/main/java/javacc7/ASTReadStatement.h \
    src/main/java/javacc7/ASTSubtractNode.h \
    src/main/java/javacc7/ASTTrueNode.h \
    src/main/java/javacc7/ASTVarDeclaration.h \
    src/main/java/javacc7/ASTWriteStatement.h \
    src/main/java/javacc7/Boolean.h \
    src/main/java/javacc7/CharStream.h \
    src/main/java/javacc7/DumpVisitor.h \
    src/main/java/javacc7/ErrorHandler.h \
    src/main/java/javacc7/Integer.h \
    src/main/java/javacc7/Interpret.h \
    src/main/java/javacc7/JJTSPLParserState.h \
    src/main/java/javacc7/JavaCC.h \
    src/main/java/javacc7/Node.h \
    src/main/java/javacc7/Object.h \
    src/main/java/javacc7/ParseException.h \
    src/main/java/javacc7/SPLParser.h \
    src/main/java/javacc7/SPLParserConstants.h \
    src/main/java/javacc7/SPLParserTokenManager.h \
    src/main/java/javacc7/SPLParserTree.h \
    src/main/java/javacc7/SPLParserTreeConstants.h \
    src/main/java/javacc7/SPLParserVisitor.h \
    src/main/java/javacc7/SimpleNode.h \
    src/main/java/javacc7/Token.h \
    src/main/java/javacc7/TokenManager.h \
    src/main/java/javacc7/TokenMgrError.h \
    src/main/java/javacc7/Variable.h \
    src/main/java/javacc7/getopt.h

DISTFILES += \
    src/main/java/javacc7/SPL.jj
