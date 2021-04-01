/* Generated By:JavaCC: Do not edit this line. TokenManager.h Version 8.0.0 */
/* JavaCCOptions:STATIC=true,SUPPORT_CLASS_VISIBILITY_PUBLIC=true */
#pragma once

#include <iostream>
#include "JavaCC.h"
#include "Token.h"

namespace EG1 {

/**
 * An implementation for this interface is generated by
 * JavaCCParser.  The user is free to use any implementation
 * of their choice.
 */

class TokenManager {
public:
  /** This gets the next token from the input stream.
   *  A token of kind 0 (<EOF>) should be returned on EOF.
   */
  virtual       ~TokenManager() { }
  virtual Token *getNextToken() = 0;
  virtual void   setParser(void* parser) {};
  virtual void   lexicalError() {
  	std::cerr << "Lexical error encountered." << std::endl;
  }

};

}
/* JavaCC - OriginalChecksum=c45792985f2838141b3c1b6453942e89 (do not edit this line) */
