/* Generated By:JavaCC: Do not edit this line. ParseException.h Version 7.0 */
/* JavaCCOptions:STATIC=true,SUPPORT_CLASS_VISIBILITY_PUBLIC=true */
#ifndef JAVACC_PARSE_EXCEPTION_H
#define JAVACC_PARSE_EXCEPTION_H

#include "JavaCC.h"
#include "Token.h"


/**
 * This exception is thrown when parse errors are encountered.
 * You can explicitly create objects of this exception type by
 * calling the method generateParseException in the generated
 * parser.
 *
 * You can modify this class to customize your error reporting
 * mechanisms so long as you retain the fields.
 */
class ParseException {
  public:

  /**
   * This constructor is used by the method "generateParseException"
   * in the generated parser.  Calling this constructor generates
   * a new object of this type with the fields "currentToken",
   * "expectedTokenSequences", and "tokenImage" set.
   */
  ParseException(Token currentTokenVal,
                        int** expectedTokenSequencesVal,
                        JJString* tokenImageVal
                       );

  /**
   * The following constructors are for use by you for whatever
   * purpose you can think of.  Constructing the exception in this
   * manner makes the exception behave in the normal way - i.e., as
   * documented in the class "Throwable".  The fields "errorToken",
   * "expectedTokenSequences", and "tokenImage" do not contain
   * relevant information.  The JavaCC generated code does not use
   * these constructors.
   */

  ParseException();

  /** Constructor with message. */
  ParseException(const JJString& message);


  /**
   * This is the last token that has been consumed successfully.  If
   * this object has been created due to a parse error, the token
   * following this token will (therefore) be the first error token.
   */
  Token currentToken;

  /**
   * Each entry in this array is an array of integers.  Each array
   * of integers represents a sequence of tokens (by their ordinal
   * values) that is expected at this point of the parse.
   */
  int** expectedTokenSequences = 0;

  /**
   * This is a reference to the "tokenImage" array of the generated
   * parser within which the parse error occurred.  This array is
   * defined in the generated ...Constants class.
   */
  JJString* tokenImage = 0;

  /**
   * It uses "currentToken" and "expectedTokenSequences" to generate a parse
   * error message and returns it.  If this object has been created
   * due to a parse error, and you do not catch it (it gets thrown
   * from the parser) the correct error message
   * gets displayed.
   */
  private:  JJString initialise(Token currentToken,
                           int** expectedTokenSequences,
                           JJString* tokenImage);

  /**
   * The end of line string for this machine.
   */
#define eol "\n"

  /**
   * Used to convert raw characters to their escaped version
   * when these raw version cannot be used as part of an ASCII
   * string literal.
   */
   JJString add_escapes(const JJString& str);

};


#endif
/* JavaCC - OriginalChecksum=eda17ef5cbd0641b2ca5efaf9211442b (do not edit this line) */
