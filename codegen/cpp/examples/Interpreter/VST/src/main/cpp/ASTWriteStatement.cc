/* Generated By:JJTree: Do not edit this line. ASTWriteStatement.cc Version 7.0 */
/* JavaCCOptions:MULTI=true,NODE_USES_PARSER=false,VISITOR=true,TRACK_TOKENS=true,NODE_PREFIX=AST,NODE_EXTENDS=,NODE_FACTORY=,SUPPORT_CLASS_VISIBILITY_PUBLIC=true */
#include "ASTWriteStatement.h"
#include "SPLParserVisitor.h"

  
  ASTWriteStatement::ASTWriteStatement(int id) : Node(id) {
  }
  ASTWriteStatement::ASTWriteStatement(SPLParser *parser, int id) : Node(parser, id) {
  }
  ASTWriteStatement::~ASTWriteStatement() {
  }

  /** Accept the visitor. **/
  void ASTWriteStatement::jjtAccept(SPLParserVisitor *visitor, void* data) const {
    visitor->visit(this, data);
  }

