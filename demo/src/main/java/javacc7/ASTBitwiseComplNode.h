/* Generated By:JJTree: Do not edit this line. ASTBitwiseComplNode.h Version 8.0 */
/* JavaCCOptions:MULTI=true,NODE_USES_PARSER=false,VISITOR=true,TRACK_TOKENS=true,NODE_PREFIX=AST,NODE_EXTENDS=,NODE_FACTORY=,SUPPORT_CLASS_VISIBILITY_PUBLIC=true */
#pragma once

#include "SimpleNode.h"

class SPLParser;

class ASTBitwiseComplNode : public SimpleNode {
public: 
  ASTBitwiseComplNode(int id);
  ASTBitwiseComplNode(SPLParser *parser, int id);
  virtual ~ASTBitwiseComplNode();

  /** Accept the visitor. **/
  virtual void jjtAccept(SPLParserVisitor *visitor, void* data) const ;
};

/* JavaCC - OriginalChecksum=97bbc4fa47703af271f9a41e64c6f84a (do not edit this line) */
