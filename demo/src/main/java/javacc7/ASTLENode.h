/* Generated By:JJTree: Do not edit this line. ASTLENode.h Version 8.0 */
/* JavaCCOptions:MULTI=true,NODE_USES_PARSER=false,VISITOR=true,TRACK_TOKENS=true,NODE_PREFIX=AST,NODE_EXTENDS=,NODE_FACTORY=,SUPPORT_CLASS_VISIBILITY_PUBLIC=true */
#pragma once

#include "SimpleNode.h"

class SPLParser;

class ASTLENode : public SimpleNode {
public: 
  ASTLENode(int id);
  ASTLENode(SPLParser *parser, int id);
  virtual ~ASTLENode();

  /** Accept the visitor. **/
  virtual void jjtAccept(SPLParserVisitor *visitor, void* data) const ;
};

/* JavaCC - OriginalChecksum=fbf316f8c8c2b998696afa2061b0d137 (do not edit this line) */
