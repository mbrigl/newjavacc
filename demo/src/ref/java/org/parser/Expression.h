/* Generated By:JavaCC: Do not edit this line. Expression.h Version 8.0.0 */
#pragma once

#include "JavaCC.h"
#include "CharStream.h"
#include "Token.h"
#include "TokenManager.h"
#include "ExpressionConstants.h"
#include "JJTExpressionState.h"
#include "ErrorHandler.h"
#include "ExpressionTree.h"
  struct JJCalls {
    int        gen;
    int        arg;
    JJCalls*   next;
    Token*     first;
    ~JJCalls() { if (next) delete next; }
     JJCalls() { next = nullptr; arg = 0; gen = -1; first = nullptr; }
  };

class Expression {
public:
void parseNull();
void parseNumber();
void parseString();
void parseIdentifier();
void parseName();
void parseLocalName();
void compileExpression();
void parseExpressionList();
void parseExpression();
void parseLiteral();
void parseAttribute();
void compileFilter();
void parsePredicate();
void parseRelationalPredicate();
void parseRelationalPredicatePart();
void parseIsNullOperator();

virtual void jjtreeOpenNodeScope(SimpleNode * node) = 0;
virtual void jjtreeCloseNodeScope(SimpleNode * node) = 0;
public: 
  void setErrorHandler(ErrorHandler *eh) {
    if (delete_eh) delete errorHandler;
    errorHandler = eh;
    delete_eh = false;
  }

  TokenManager *token_source = nullptr;
  CharStream   *jj_input_stream = nullptr;
  /** Current token. */
  Token        *token = nullptr;
  /** Next token. */
  Token        *jj_nt = nullptr;

private: 
  int           jj_ntk;
  JJCalls       jj_2_rtns[1];
  bool          jj_rescan;
  int           jj_gc;
  Token        *jj_scanpos, *jj_lastpos;
  int           jj_la;
  /** Whether we are looking ahead. */
  bool          jj_lookingAhead;
  bool          jj_semLA;
  int           jj_gen;
  int           jj_la1[6];
  ErrorHandler *errorHandler = nullptr;

protected: 
  bool          delete_eh     = false;
  bool          delete_tokens = true;
  bool          hasError;

  Token        *head;

public: 
  Expression(TokenManager *tokenManager);
  virtual ~Expression();
void ReInit(TokenManager* tokenManager);
void clear();
Token * jj_consume_token(int kind);
Token * getNextToken();
Token * getToken(int index);
private:
  int jj_kind;
  int **jj_expentries;
  int *jj_expentry;

protected:
  /** Generate ParseException. */
  virtual void  parseError();
private:
  int  indent; // trace indentation
  bool trace = false; // trace enabled if true

public:
  bool trace_enabled();
  void enable_tracing();
  void disable_tracing();


  JJTExpressionState jjtree;
private:
  bool jj_done;
};
/* JavaCC - OriginalChecksum=c7e401762c92325b61f262027b604873 (do not edit this line) */
