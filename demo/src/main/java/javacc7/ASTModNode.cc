/* Generated By:JJTree: Do not edit this line. ASTModNode.cc Version 8.0 */
/* JavaCCOptions:MULTI=true,NODE_USES_PARSER=false,VISITOR=true,TRACK_TOKENS=true,NODE_PREFIX=AST,NODE_EXTENDS=,NODE_FACTORY=,SUPPORT_CLASS_VISIBILITY_PUBLIC=true */
#include "ASTModNode.h"
#include "SPLParserVisitor.h"

  
  ASTModNode::ASTModNode(int id) : SimpleNode(id) {
  }
  ASTModNode::ASTModNode(SPLParser *parser, int id) : SimpleNode(parser, id) {
  }
  ASTModNode::~ASTModNode() {
  }

  /** Accept the visitor. **/
  void ASTModNode::jjtAccept(SPLParserVisitor *visitor, void* data) const {
    visitor->visit(this, data);
  }

/* JavaCC - OriginalChecksum=bdb3c5947db993f2f522b3f7a86063dd (do not edit this line) */
