/* Generated By:JJTree: Do not edit this line. ASTNotNode.h Version 8.0 */
/* JavaCCOptions:MULTI=true,NODE_USES_PARSER=false,VISITOR=true,TRACK_TOKENS=true,NODE_PREFIX=AST,NODE_EXTENDS=,NODE_FACTORY=,SUPPORT_CLASS_VISIBILITY_PUBLIC=true */
#pragma once

#include "SimpleNode.h"

class SPLParser;

class ASTNotNode : public SimpleNode {
public: 
  ASTNotNode(int id);
  ASTNotNode(SPLParser *parser, int id);
  virtual ~ASTNotNode();

  /** Accept the visitor. **/
  virtual void jjtAccept(SPLParserVisitor *visitor, void* data) const ;
};

/* JavaCC - OriginalChecksum=1481cbc610cd70f5b20ad7f88136b797 (do not edit this line) */
