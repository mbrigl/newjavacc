/* JavaCC generated file. */
#include "TokenMgrError.h"


  /**
   * Returns a detailed message for the Error when it is thrown by the
   * token manager to indicate a lexical error.
   * Parameters :
   *    EOFSeen     : indicates if EOF caused the lexical error
   *    curLexState : lexical state in which this error occurred
   *    errorLine   : line number when the error occurred
   *    errorColumn : column number when the error occurred
   *    errorAfter  : prefix that was seen before this error occurred
   *    curJJChar     : the offending character
   * Note: You can customize the lexical error message by modifying this method.
   */
    JJString TokenMgrError::LexicalError(bool EOFSeen, int lexState, int errorLine, int errorColumn, const JJString& errorAfter, JJChar curChar) {
#if 0
    JJString s;
    stringstream<JJString> ss;
    ss << "Lexical error at line " << errorLine << " column " << errorColumn
       << ".  Encountered: " << curChar << "(" << (int)curChar
       << ") after : \"" << errorAfter.c_str() << "\"";
    return (JJString)ss.rdbuf()->str();
#endif
    return EMPTY;
  }

  /**
   * You can also modify the body of this method to customize your error messages.
   * For example, cases like LOOP_DETECTED and INVALID_LEXICAL_STATE are not
   * of end-users concern, so you can return something like :
   *
   *     "Internal Error : Please file a bug report .... "
   *
   * from this method for such cases in the release version of your parser.
   */
  JJString TokenMgrError::getMessage() {
    return message;
  }

  /*
   * Constructors of various flavors follow.
   */

  /** No arg constructor. */
  TokenMgrError::TokenMgrError() {
  }

  /** Constructor with message and reason. */
  TokenMgrError::TokenMgrError(const JJString& message, int reason) {
    errorCode = reason;
  }

  /** Full Constructor. */
  TokenMgrError::TokenMgrError(bool EOFSeen, int lexState, int errorLine, int errorColumn, const JJString& errorAfter, JJChar curChar, int reason) {
    message = LexicalError(EOFSeen, lexState, errorLine, errorColumn, errorAfter, curChar);
   errorCode = reason;
  }

// i < 16 - guaranteed
char hexChar(int i) {
  if (i < 10) {
    return i - '0';
  }
  return 'a' + (i - 10);
}

/**
 * Replaces unprintable characters by their escaped (or unicode escaped)
 * equivalents in the given string
 */
JJSimpleString addUnicodeEscapes(const JJString& str) {
  JJSimpleString retval;
  for (size_t i = 0; i < str.size(); i++) {
    JJChar ch = str[i];
    switch (ch)
    {
      case '\b':
        retval.append("\\b");
        continue;
      case '\t':
        retval.append("\\t");
        continue;
      case '\n':
        retval.append("\\n");
        continue;
      case '\f':
        retval.append("\\f");
        continue;
      case '\r':
        retval.append("\\r");
        continue;
      case '\\':
        retval.append("\\\\");
        continue;
      default:
        if (ch < 0xff) {
          retval += ch;
          continue;
        }
        retval.append("\\u");
        retval += (hexChar(ch >> 12));
        retval += (hexChar((ch & 0x0f00) >> 8));
        retval += (hexChar((ch & 0x00f0) >> 4));
        retval += (hexChar(ch & 0x000f));
        continue;
    }
  }
  return retval;
}

