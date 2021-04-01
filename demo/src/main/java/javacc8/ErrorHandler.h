/* Generated By:JavaCC: Do not edit this line. ErrorHandler.h Version 8.0.0 */
/* JavaCCOptions:STATIC=true,SUPPORT_CLASS_VISIBILITY_PUBLIC=true,BUILD_PARSER=true,BUILD_TOKEN_MANAGER=true */
#pragma once

#include <string>
#include "JavaCC.h"
#include "Token.h"


JJSimpleString addUnicodeEscapes(const JJString& str);

  class SPLParser;
  class ErrorHandler {
    friend class SPLParserTokenManager;
    friend class SPLParser;
    protected:
      int error_count;
    public:
      // Called when the parser encounters a different token when expecting to
      // consume a specific kind of token.
      // expectedKind - token kind that the parser was trying to consume.
      // expectedToken - the image of the token - tokenImages[expectedKind].
      // actual - the actual token that the parser got instead.
      virtual void handleUnexpectedToken(int /*expectedKind*/, const JJString & expectedToken, Token *actual, SPLParser * /*parser*/) {
        error_count++;
        std::cerr << "Expecting " << addUnicodeEscapes(expectedToken) << " at: " << actual->beginLine << ":" << actual->beginColumn << "but got " << addUnicodeEscapes(actual->image) << std::endl;
      }
      // Called when the parser cannot continue parsing.
      // last - the last token successfully parsed.
      // unexpected - the token at which the error occurs.
      // production - the production in which this error occurrs.
      virtual void handleParseError(Token * /*last*/, Token *unexpected, const JJSimpleString & production, SPLParser * /*parser*/) {
        error_count++;
        std::cerr << "Encountered: " << addUnicodeEscapes(unexpected->image) << " at: " << unexpected->beginLine << ":" << unexpected->beginColumn << "while parsing: " << production << std::endl;
      }
      virtual int getErrorCount() {
        return error_count;
      }
      virtual void handleOtherError(const JJString & message, SPLParser * /*parser*/) {
        std::cerr << "Error: " << message << std::endl;
      }
      virtual ~ErrorHandler() {}
      ErrorHandler() { error_count = 0; }
  };

  class SPLParserTokenManager;
  class TokenManagerErrorHandler {
    friend class SPLParserTokenManager;
    protected:
      int error_count;
    public:
      // Returns a detailed message for the Error when it is thrown by the
      // token manager to indicate a lexical error.
      // Parameters :
      //    EOFSeen     : indicates if EOF caused the lexical error
      //    curLexState : lexical state in which this error occurred
      //    errorLine   : line number when the error occurred
      //    errorColumn : column number when the error occurred
      //    errorAfter  : prefix that was seen before this error occurred
      //    curchar     : the offending character
      //
      virtual void lexicalError(bool /*EOFSeen*/, int /*lexState*/, int errorLine, int errorColumn, JJString errorAfter, JJChar curChar, SPLParserTokenManager* /*token_manager*/) {
        // by default, we just print an error message and return.
        std::cerr << "Lexical error at: " << errorLine << ":" << errorColumn << ". Encountered: " << curChar << " after: " << errorAfter << "." << std::endl;
      }
      virtual void lexicalError(const JJString & errorMessage, SPLParserTokenManager* /*token_manager*/) {
        std::cerr << errorMessage << std::endl;
      }
      virtual ~TokenManagerErrorHandler() {}
  };

/* JavaCC - OriginalChecksum=e8ccfea14e671608d60be47024302c36 (do not edit this line) */
