/* Generated By:JavaCC: Do not edit this line. TokenMgrError.h Version 8.0.0 */
/* JavaCCOptions:STATIC=true,SUPPORT_CLASS_VISIBILITY_PUBLIC=true */
#pragma once


#include "JavaCC.h"


enum LexerErrors {
  /**
   * Lexical error occurred.
   */
  LEXICAL_ERROR = 0,

  /**
   * An attempt was made to create a second instance of a  token manager.
   */
  STATIC_LEXER_ERROR = 1,

  /**
   * Tried to change to an invalid lexical state.
   */
  INVALID_LEXICAL_STATE = 2,

  /**
   * Detected (and bailed out of) an infinite loop in the token manager.
   */
  LOOP_DETECTED = 3,
};

class TokenMgrError {
public:
  /*
   * Ordinals for various reasons why an Error of this type can be thrown.
   */

  /**
   * Indicates the reason why the exception is thrown. It will have
   * one of the above 4 values.
   */
  int errorCode = -1;

  /**
   * Returns a detailed message for the Error when it is thrown by the
   * token manager to indicate a lexical error.
   * Parameters :
   *    EOFSeen     : indicates if EOF caused the lexical error
   *    curLexState : lexical state in which this error occurred
   *    errorLine   : line number when the error occurred
   *    errorColumn : column number when the error occurred
   *    errorAfter  : prefix that was seen before this error occurred
   *    curchar     : the offending character
   * Note: You can customize the lexical error message by modifying this method.
   */
    JJString LexicalError(bool EOFSeen, int lexState, int errorLine, int errorColumn, const JJString& errorAfter, JJChar curChar);

private:
   JJString message;

  /**
   * You can also modify the body of this method to customize your error messages.
   * For example, cases like LOOP_DETECTED and INVALID_LEXICAL_STATE are not
   * of end-users concern, so you can return something like :
   *
   *     "Internal Error : Please file a bug report .... "
   *
   * from this method for such cases in the release version of your parser.
   */
public:
  JJString getMessage() ;

  /*
   * Constructors of various flavors follow.
   */

  /** No arg constructor. */
  TokenMgrError() ;

  /** Constructor with message and reason. */
  TokenMgrError(const JJString& message, int reason) ;

  /** Full Constructor. */
  TokenMgrError(bool EOFSeen, int lexState, int errorLine, int errorColumn, const JJString& errorAfter, JJChar curChar, int reason) ;
};

/* JavaCC - OriginalChecksum=1aefe13c5933c936c51e6e08d302a76c (do not edit this line) */
