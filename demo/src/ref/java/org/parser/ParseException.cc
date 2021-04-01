/* JavaCC generated file. */
#include "ParseException.h"


/**
 * This exception is thrown when parse errors are encountered.
 * You can explicitly create objects of this exception type by
 * calling the method generate_ParseException in the generated
 * parser.
 *
 * You can modify this class to customize your error reporting
 * mechanisms so long as you retain the fields.
 */

  /**
   * This constructor is used by the method "generate_ParseException"
   * in the generated parser.  Calling this constructor generates
   * a new object of this type with the fields "currentToken",
   * "expectedTokenSequences", and "tokenImage" set.
   */
  ParseException::ParseException(Token currentTokenVal,
                        int** expectedTokenSequencesVal,
                        JJString* tokenImageVal
                       )
  {
    initialise(currentTokenVal, expectedTokenSequencesVal, tokenImageVal);
    currentToken = currentTokenVal;
    expectedTokenSequences = expectedTokenSequencesVal;
    tokenImage = tokenImageVal;
  }

  /**
   * The following constructors are for use by you for whatever
   * purpose you can think of.  Constructing the exception in this
   * manner makes the exception behave in the normal way - i.e., as
   * documented in the class "Throwable".  The fields "errorToken",
   * "expectedTokenSequences", and "tokenImage" do not contain
   * relevant information.  The JavaCC generated code does not use
   * these constructors.
   */

  ParseException::ParseException() {
  }

  /** Constructor with message. */
  ParseException::ParseException(const JJString& message) {
  }


  /**
   * This is the last token that has been consumed successfully.  If
   * this object has been created due to a parse error, the token
   * followng this token will (therefore) be the first error token.
   */
  Token currentToken;

  /**
   * Each entry in this array is an array of integers.  Each array
   * of integers represents a sequence of tokens (by their ordinal
   * values) that is expected at this point of the parse.
   */
  int** expectedTokenSequences;

  /**
   * This is a reference to the "tokenImage" array of the generated
   * parser within which the parse error occurred.  This array is
   * defined in the generated ...Constants class.
   */
  JJString* tokenImage;

  /**
   * It uses "currentToken" and "expectedTokenSequences" to generate a parse
   * error message and returns it.  If this object has been created
   * due to a parse error, and you do not catch it (it gets thrown
   * from the parser) the correct error message
   * gets displayed.
   */
  JJString ParseException::initialise(Token currentToken,
                           int** expectedTokenSequences,
                           JJString* tokenImage) {
#if 0
    //JJString eol = System.getProperty("line.separator", "\n");
     expected = new JJString();
    int maxSize = 0;
    for (int i = 0; i < expectedTokenSequences.length; i++) {
      if (maxSize < expectedTokenSequences[i].length) {
        maxSize = expectedTokenSequences[i].length;
      }
      for (int j = 0; j < expectedTokenSequences[i].length; j++) {
        expected.append(tokenImage[expectedTokenSequences[i][j]]).append(' ');
      }
      if (expectedTokenSequences[i][expectedTokenSequences[i].length - 1] != 0) {
        expected.append((JJChar*)"...");
      }
      expected.append(eol).append("    ");
    }
    JJString retval = (JJChar*)"Encountered \"";
    Token tok = currentToken.next;
    for (int i = 0; i < maxSize; i++) {
      if (i != 0) retval += (JJChar*)" ";
      if (tok.kind == 0) {
        retval += tokenImage[0];
        break;
      }
      retval += (JJChar*)" " + tokenImage[tok.kind];
      retval += (JJChar*)" \"";
      retval += add_escapes(tok.image);
      retval += (JJChar*)" \"";
      tok = tok.next;
    }
    retval += (JJChar*)"\" at line " + currentToken.next.beginLine + (JJChar*)", column " + currentToken.next.beginColumn;
    retval += (JJChar*)"." + eol;
    if (expectedTokenSequences.length == 1) {
      retval += (JJChar*)"Was expecting:" + eol + (JJChar*)"    ";
    } else {
      retval += (JJChar*)"Was expecting one of:" + eol + (JJChar*)"    ";
    }
    retval += expected.toString();
    return retval;
#endif
    return (JJChar*)"Parse exception";
  }

  /**
   * The end of line JJString for this machine.
   */
#define eol "\n"

  /**
   * Used to convert raw characters to their escaped version
   * when these raw version cannot be used as part of an ASCII
   * string literal.
   */
   JJString ParseException::add_escapes(const JJString& str) {
/*
      JJString *retval = new JJString();
      JJChar ch;
      for (int i = 0; i < str.length(); i++) {
        switch (str.charAt(i))
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
           case '\"':
              retval.append("\\\"");
              continue;
           case '\'':
              retval.append("\\\'");
              continue;
           case '\\':
              retval.append("\\\\");
              continue;
           default:
              if ((ch = str.charAt(i)) < 0x20 || ch > 0x7e) {
                 JJString s = "0000" + Integer.toString(ch, 16);
                 retval.append("\\u" + s.substring(s.length() - 4, s.length()));
              } else {
                 retval.append(ch);
              }
              continue;
        }
      }
      return retval.toString();
*/ return str;
   }

