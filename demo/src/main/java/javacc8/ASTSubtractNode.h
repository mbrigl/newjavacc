/* Generated By:JJTree: Do not edit this line. ASTSubtractNode.h Version 8.0 */
/* JavaCCOptions:MULTI=true,NODE_USES_PARSER=false,VISITOR=true,TRACK_TOKENS=true,NODE_PREFIX=AST,NODE_EXTENDS=,NODE_FACTORY=,SUPPORT_CLASS_VISIBILITY_PUBLIC=true */
#pragma once

#include "SimpleNode.h"

class SPLParser;

class ASTSubtractNode : public SimpleNode {
public: 
  ASTSubtractNode(int id);
  ASTSubtractNode(SPLParser *parser, int id);
  virtual ~ASTSubtractNode();

  /** Accept the visitor. **/
  virtual void jjtAccept(SPLParserVisitor *visitor, void* data) const ;
};

/* JavaCC - OriginalChecksum=e5dfa34232b452833caa78a44c9dc95d (do not edit this line) */
