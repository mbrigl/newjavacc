/* Generated By:JavaCC: Do not edit this line. Expression.cc Version 8.0.0 */
#include "Expression.h"
#include "ExpressionTree.h"

#include "TokenMgrError.h"
  unsigned int jj_la1_0[] = {
0x3000,0x200,0x400,0x83880,0x180000,};

  /** Constructor with user supplied TokenManager. */



void Expression::parseNull() {

    SimpleNode *jjtn001 = new SimpleNode(JJTNIL);
    bool jjtc001 = true;
    jjtree.openNodeScope(jjtn001);
    jjtreeOpenNodeScope(jjtn001);



                                 
  
    try {
      jj_consume_token(NULL_TOKEN);
    } catch (...) {      
        
        if (jjtc001) {
          jjtree.clearNodeScope(jjtn001);
          jjtc001 = false;
        } else {
          jjtree.popNode();
        }
    
    
    
    
    
         
      
    }

    if (jjtc001) {
      jjtree.closeNodeScope(jjtn001, true);
      if (jjtree.nodeCreated()) {
       jjtreeCloseNodeScope(jjtn001);
      }
    }





     
  
}


void Expression::parseNumber() {

    SimpleNode *jjtn001 = new SimpleNode(JJTDECIMAL);
    bool jjtc001 = true;
    jjtree.openNodeScope(jjtn001);
    jjtreeOpenNodeScope(jjtn001);



                                 
  
    try {
      jj_consume_token(DECIMAL_TOKEN);
    } catch (...) {      
        
        if (jjtc001) {
          jjtree.clearNodeScope(jjtn001);
          jjtc001 = false;
        } else {
          jjtree.popNode();
        }
    
    
    
    
    
         
      
    }

    if (jjtc001) {
      jjtree.closeNodeScope(jjtn001, true);
      if (jjtree.nodeCreated()) {
       jjtreeCloseNodeScope(jjtn001);
      }
    }





     
  
}


void Expression::parseString() {

    SimpleNode *jjtn001 = new SimpleNode(JJTSTRING);
    bool jjtc001 = true;
    jjtree.openNodeScope(jjtn001);
    jjtreeOpenNodeScope(jjtn001);



                                 
  
    try {
      jj_consume_token(STRING_TOKEN);
    } catch (...) {      
        
        if (jjtc001) {
          jjtree.clearNodeScope(jjtn001);
          jjtc001 = false;
        } else {
          jjtree.popNode();
        }
    
    
    
    
    
         
      
    }

    if (jjtc001) {
      jjtree.closeNodeScope(jjtn001, true);
      if (jjtree.nodeCreated()) {
       jjtreeCloseNodeScope(jjtn001);
      }
    }





     
  
}


void Expression::parseIdentifier() {
    switch (jj_nt->kind) {
    case IDENTIFIER_TOKEN:{

    SimpleNode *jjtn001 = new SimpleNode(JJTIDENTIFIER);
    bool jjtc001 = true;
    jjtree.openNodeScope(jjtn001);
    jjtreeOpenNodeScope(jjtn001);



                                 
  
      try {
        jj_consume_token(IDENTIFIER_TOKEN);
      } catch (...) {      
          
          if (jjtc001) {
            jjtree.clearNodeScope(jjtn001);
            jjtc001 = false;
          } else {
            jjtree.popNode();
          }
      
      
      
      
      
           
        
      }

    if (jjtc001) {
      jjtree.closeNodeScope(jjtn001, true);
      if (jjtree.nodeCreated()) {
       jjtreeCloseNodeScope(jjtn001);
      }
    }





     
  
      break;
      }
    case IDENTIFIER_QUOTED_TOKEN:{

    SimpleNode *jjtn002 = new SimpleNode(JJTIDENTIFIER_QUOTED);
    bool jjtc002 = true;
    jjtree.openNodeScope(jjtn002);
    jjtreeOpenNodeScope(jjtn002);



                                 
  
      try {
        jj_consume_token(IDENTIFIER_QUOTED_TOKEN);
      } catch (...) {      
          
          if (jjtc002) {
            jjtree.clearNodeScope(jjtn002);
            jjtc002 = false;
          } else {
            jjtree.popNode();
          }
      
      
      
      
      
           
        
      }

    if (jjtc002) {
      jjtree.closeNodeScope(jjtn002, true);
      if (jjtree.nodeCreated()) {
       jjtreeCloseNodeScope(jjtn002);
      }
    }





     
  
      break;
      }
    default:
      jj_la1[0] = jj_gen;
      jj_consume_token(-1);
      errorHandler->handleParseError(token, getToken(1), __FUNCTION__, this), hasError = true;
    }
}


void Expression::parseName() {/*@bgen(jjtree) NAME */
  SimpleNode *jjtn000 = new SimpleNode(JJTNAME);
  bool jjtc000 = true;
  jjtree.openNodeScope(jjtn000);
  jjtreeOpenNodeScope(jjtn000);



                               
/*@egen*/

    try {
      parseLocalName();
      switch (jj_nt->kind) {
      case DOT:{
        jj_consume_token(DOT);
        parseName();
        break;
        }
      default:
        jj_la1[1] = jj_gen;
        ;
      }
    } catch (...) {      
        
        if (jjtc000) {
          jjtree.clearNodeScope(jjtn000);
          jjtc000 = false;
        } else {
          jjtree.popNode();
        }
    
    
    
    
    
         
      
    }

    if (jjtc000) {
      jjtree.closeNodeScope(jjtn000, true);
      if (jjtree.nodeCreated()) {
       jjtreeCloseNodeScope(jjtn000);
      }
    }





     
  
}


void Expression::parseLocalName() {/*@bgen(jjtree) LOCALNAME */
  SimpleNode *jjtn000 = new SimpleNode(JJTLOCALNAME);
  bool jjtc000 = true;
  jjtree.openNodeScope(jjtn000);
  jjtreeOpenNodeScope(jjtn000);



                               
/*@egen*/

    try {
      parseIdentifier();
    } catch (...) {      
        
        if (jjtc000) {
          jjtree.clearNodeScope(jjtn000);
          jjtc000 = false;
        } else {
          jjtree.popNode();
        }
    
    
    
    
    
         
      
    }

    if (jjtc000) {
      jjtree.closeNodeScope(jjtn000, true);
      if (jjtree.nodeCreated()) {
       jjtreeCloseNodeScope(jjtn000);
      }
    }





     
  
}


Node* Expression::compile() {
    compileExpression();
 return jjtree.rootNode();                           
assert(false);
}


void Expression::compileExpression() {
    parseExpressionList();
    jj_consume_token(0);
}


void Expression::parseExpressionList() {/*@bgen(jjtree) EXPRESSIONLIST */
  SimpleNode *jjtn000 = new SimpleNode(JJTEXPRESSIONLIST);
  bool jjtc000 = true;
  jjtree.openNodeScope(jjtn000);
  jjtreeOpenNodeScope(jjtn000);



                               
/*@egen*/

    try {
      parsePredicate();
      while (!hasError) {
        switch (jj_nt->kind) {
        case COMMA:{
          ;
          break;
          }
        default:
          jj_la1[2] = jj_gen;
          goto end_label_1;
        }
        jj_consume_token(COMMA);
        parsePredicate();
      }
      end_label_1: ;
    } catch (...) {      
        
        if (jjtc000) {
          jjtree.clearNodeScope(jjtn000);
          jjtc000 = false;
        } else {
          jjtree.popNode();
        }
    
    
    
    
    
         
      
    }

    if (jjtc000) {
      jjtree.closeNodeScope(jjtn000, true);
      if (jjtree.nodeCreated()) {
       jjtreeCloseNodeScope(jjtn000);
      }
    }





     
  
}


void Expression::parseExpression() {
    switch (jj_nt->kind) {
    case NULL_TOKEN:{
      parseNull();
      break;
      }
    case STRING_TOKEN:{
      parseLiteral();
      break;
      }
    case IDENTIFIER_TOKEN:
    case IDENTIFIER_QUOTED_TOKEN:{
      parseAttribute();
      break;
      }
    case LP:{
      jj_consume_token(LP);
      parsePredicate();
      jj_consume_token(RP);
      break;
      }
    default:
      jj_la1[3] = jj_gen;
      jj_consume_token(-1);
      errorHandler->handleParseError(token, getToken(1), __FUNCTION__, this), hasError = true;
    }
}


void Expression::parseLiteral() {/*@bgen(jjtree) LITERAL */
  SimpleNode *jjtn000 = new SimpleNode(JJTLITERAL);
  bool jjtc000 = true;
  jjtree.openNodeScope(jjtn000);
  jjtreeOpenNodeScope(jjtn000);



                               
/*@egen*/

    try {
      parseString();
    } catch (...) {      
        
        if (jjtc000) {
          jjtree.clearNodeScope(jjtn000);
          jjtc000 = false;
        } else {
          jjtree.popNode();
        }
    
    
    
    
    
         
      
    }

    if (jjtc000) {
      jjtree.closeNodeScope(jjtn000, true);
      if (jjtree.nodeCreated()) {
       jjtreeCloseNodeScope(jjtn000);
      }
    }





     
  
}


void Expression::parseAttribute() {/*@bgen(jjtree) ATTRIBUTE */
  SimpleNode *jjtn000 = new SimpleNode(JJTATTRIBUTE);
  bool jjtc000 = true;
  jjtree.openNodeScope(jjtn000);
  jjtreeOpenNodeScope(jjtn000);



                               
/*@egen*/

    try {
      parseName();
    } catch (...) {      
        
        if (jjtc000) {
          jjtree.clearNodeScope(jjtn000);
          jjtc000 = false;
        } else {
          jjtree.popNode();
        }
    
    
    
    
    
         
      
    }

    if (jjtc000) {
      jjtree.closeNodeScope(jjtn000, true);
      if (jjtree.nodeCreated()) {
       jjtreeCloseNodeScope(jjtn000);
      }
    }





     
  
}


void Expression::compileFilter() {
    parsePredicate();
    jj_consume_token(0);
}


void Expression::parsePredicate() {
    parseExpression();
}


void Expression::parseRelationalPredicate() {/*@bgen(jjtree) RELATIONAL_PREDICATE */
  SimpleNode *jjtn000 = new SimpleNode(JJTRELATIONAL_PREDICATE);
  bool jjtc000 = true;
  jjtree.openNodeScope(jjtn000);
  jjtreeOpenNodeScope(jjtn000);



                               
/*@egen*/

    try {
      parseExpression();
      parseRelationalPredicatePart();
    } catch (...) {      
        
        if (jjtc000) {
          jjtree.clearNodeScope(jjtn000);
          jjtc000 = false;
        } else {
          jjtree.popNode();
        }
    
    
    
    
    
         
      
    }

    if (jjtc000) {
      jjtree.closeNodeScope(jjtn000, true);
      if (jjtree.nodeCreated()) {
       jjtreeCloseNodeScope(jjtn000);
      }
    }





     
  
}


void Expression::parseRelationalPredicatePart() {
    jj_consume_token(IS);
    parseIsNullOperator();
}


void Expression::parseIsNullOperator() {
    switch (jj_nt->kind) {
    case NULL_TOKEN:{

    SimpleNode *jjtn001 = new SimpleNode(JJTISNULL_OPERATOR);
    bool jjtc001 = true;
    jjtree.openNodeScope(jjtn001);
    jjtreeOpenNodeScope(jjtn001);



                                 
  
      try {
        jj_consume_token(NULL_TOKEN);
      } catch (...) {      
          
          if (jjtc001) {
            jjtree.clearNodeScope(jjtn001);
            jjtc001 = false;
          } else {
            jjtree.popNode();
          }
      
      
      
      
      
           
        
      }

    if (jjtc001) {
      jjtree.closeNodeScope(jjtn001, true);
      if (jjtree.nodeCreated()) {
       jjtreeCloseNodeScope(jjtn001);
      }
    }





     
  
      break;
      }
    case NOT:{
      jj_consume_token(NOT);

            SimpleNode *jjtn002 = new SimpleNode(JJTISNOTNULL_OPERATOR);
            bool jjtc002 = true;
            jjtree.openNodeScope(jjtn002);
            jjtreeOpenNodeScope(jjtn002);



                                         
          
      try {
        jj_consume_token(NULL_TOKEN);
      } catch (...) {      
                  
                  if (jjtc002) {
                    jjtree.clearNodeScope(jjtn002);
                    jjtc002 = false;
                  } else {
                    jjtree.popNode();
                  }
      
      
      
      
      
                   
                
      }

            if (jjtc002) {
              jjtree.closeNodeScope(jjtn002, true);
              if (jjtree.nodeCreated()) {
               jjtreeCloseNodeScope(jjtn002);
              }
            }





             
          
      break;
      }
    default:
      jj_la1[4] = jj_gen;
      jj_consume_token(-1);
      errorHandler->handleParseError(token, getToken(1), __FUNCTION__, this), hasError = true;
    }
}


  Expression::Expression(TokenManager *tokenManager){
    head = nullptr;
    ReInit(tokenManager);
}
Expression::~Expression()
{
  clear();
}

void Expression::ReInit(TokenManager* tokenManager){
    clear();
    errorHandler = new ErrorHandler();
    delete_eh = true;
    hasError = false;
    token_source = tokenManager;
    head = token = new Token();
    token->kind = 0;
    token->next = nullptr;
    jj_lookingAhead = false;
    jj_rescan = false;
    jj_done = false;
    jj_scanpos = jj_lastpos = nullptr;
    jj_gc = 0;
    jj_kind = -1;
    indent = 0;
    trace = false;
    token->next = jj_nt = token_source->getNextToken();
    jjtree.reset();
    jj_gen = 0;
    for (int i = 0; i < 5; i++) jj_la1[i] = -1;
  }


void Expression::clear(){
  //Since token manager was generate from outside,
  //parser should not take care of deleting
  //if (token_source) delete token_source;
  if (delete_tokens && head) {
    Token *next, *t = head;
    while (t) {
      next = t->next;
      delete t;
      t = next;
    }
  }
  if (delete_eh) {
    delete errorHandler, errorHandler = nullptr;
    delete_eh = false;
  }
}


Token * Expression::jj_consume_token(int kind)  {
    Token *oldToken = token;
    if ((token = jj_nt)->next != nullptr) jj_nt = jj_nt->next;
    else jj_nt = jj_nt->next = token_source->getNextToken();
    if (token->kind == kind) {
      jj_gen++;
      return token;
    }
    jj_nt = token;
    token = oldToken;
    jj_kind = kind;
    JJString image = kind >= 0 ? tokenImage[kind] : tokenImage[0];
    errorHandler->handleUnexpectedToken(kind, image.substr(1, image.size() - 2), getToken(1), this);
    hasError = true;
    return token;
  }


/** Get the next Token. */

Token * Expression::getNextToken(){
    if ((token = jj_nt)->next != nullptr) jj_nt = jj_nt->next;
    else jj_nt = jj_nt->next = token_source->getNextToken();
    jj_gen++;
    return token;
  }

/** Get the specific Token. */

Token * Expression::getToken(int index){
    Token *t = token;
    for (int i = 0; i < index; i++) {
      if (t->next != nullptr) t = t->next;
      else t = t->next = token_source->getNextToken();
    }
    return t;
  }


 void  Expression::parseError()   {
      std::cerr << "Parse error at : " << token->beginLine << ":" << token->beginColumn << " after token: " << addUnicodeEscapes(token->image) << " encountered: " << addUnicodeEscapes(getToken(1)->image) << std::endl;
   }


  bool Expression::trace_enabled()  {
    return trace;
  }


  void Expression::enable_tracing()  {
  }

  void Expression::disable_tracing()  {
  }


/* JavaCC - OriginalChecksum=de276267e71da24e73532043b12e0ba0 (do not edit this line) */
