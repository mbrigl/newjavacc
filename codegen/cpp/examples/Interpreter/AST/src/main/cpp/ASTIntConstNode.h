/* Generated By:JJTree: Do not edit this line. ASTIntConstNode.h Version 8.0 */
/* JavaCCOptions:MULTI=true,NODE_USES_PARSER=false,VISITOR=false,TRACK_TOKENS=true,NODE_PREFIX=AST,NODE_EXTENDS=MyNode,NODE_FACTORY=,SUPPORT_CLASS_VISIBILITY_PUBLIC=true */
#pragma once

#include "Node.h"


class ASTIntConstNode : public Node {
public: 
  ASTIntConstNode(int id);
  virtual ~ASTIntConstNode();
  virtual void interpret();
  friend class SPLParser;

private:
	int val;
};

/* JavaCC - OriginalChecksum=02fc6f491cf73dfde5fe4d03796de1ec (do not edit this line) */
