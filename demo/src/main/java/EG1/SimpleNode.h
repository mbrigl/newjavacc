/* Generated By:JJTree: Do not edit this line. SimpleNode.h Version 8.0 */
/* JavaCCOptions:MULTI=false,NODE_USES_PARSER=false,VISITOR=false,TRACK_TOKENS=false,NODE_PREFIX=AST,NODE_EXTENDS=,NODE_FACTORY=,SUPPORT_CLASS_VISIBILITY_PUBLIC=true */
#pragma once

#include <vector>
#include "JavaCC.h"
#include "Token.h"
#include "Node.h"
#include "ParserTreeConstants.h"

namespace EG1 {

class Parser;

class SimpleNode : public Node {
protected: 
  std::vector<Node*> children;
  Node*              parent = nullptr;
  void*              value  = nullptr;
//int                numChildren;
  Parser*    parser = nullptr;
  int                id = 0;

public: 
           SimpleNode(int id);
           SimpleNode(Parser* parser, int id);
  virtual ~SimpleNode();

//#if !NODE_FACTORY
//\#define jjtCreate(id) new SimpleNode(id)
//\#define jjtCreate(p, id) new SimpleNode(p, id)
//#fi

  virtual void           jjtOpen() const;
  virtual void           jjtClose() const;
  virtual void           jjtSetParent(Node *n);
  virtual Node*          jjtGetParent() const;
  virtual void           jjtAddChild(Node *n, int i);
  virtual Node*          jjtGetChild(int i) const;
  virtual int            jjtGetNumChildren() const;
  virtual void           jjtSetValue(void * value);
  virtual void*          jjtGetValue() const;


  /* You can override these two methods in subclasses of SimpleNode to
     customize the way the node appears when the tree is dumped.  If
     your output uses more than one line you should override
     toString(string), otherwise overriding toString() is probably all
     you need to do. */
     
  virtual JJString toString() const;
  virtual JJString toString(const JJString& prefix) const;

  /* Override this method if you want to customize how the node dumps
     out its children. */
  virtual void          dump(const JJString& prefix) const;
  virtual void          dumpToBuffer(const JJString& prefix, const JJString& separator, JJString *sb) const;
  virtual int           getId() const { return id;  }
};
}
/* JavaCC - OriginalChecksum=c8cc775f0d011b2bdfc58d66466da276 (do not edit this line) */
