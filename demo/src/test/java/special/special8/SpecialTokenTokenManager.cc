/* Generated By:JavaCC: Do not edit this line. SpecialTokenTokenManager.cc Version 8.0.0 */
#include "SpecialTokenTokenManager.h"
#include "TokenManagerError.h"

static const long long stringLiterals[] = {
1LL, 0, 32LL, 1LL, -1LL, 
1LL, 0, 9LL, 2LL, -1LL, 
1LL, 0, 10LL, 3LL, -1LL, 
2LL, 0, 42LL, 47LL, 7LL, -1LL, 
1LL, 0, 13LL, 4LL, -1LL, 
2LL, 0, 45LL, 45LL, 11LL, -1LL, 
2LL, 0, 47LL, 42LL, 6LL, -1LL, 
2LL, 0, 47LL, 42LL, 5LL, -1LL};

static const long long jjCharData[][5] = {
{4LL, 1LL, 0LL, 1LL, 576460743847706622LL},
{4LL, 1LL, 287948901175001088LL, 1LL, 576460743847706622LL},
{4LL, 1LL, -35184372098049LL, 3LL, -1LL},
{2LL, 1LL, 1024LL},
{2LL, 1LL, 8192LL},
{2LL, 1LL, 9216LL},
{2LL, 1LL, 35184372088832LL},
{2LL, 1LL, 8192LL},
{2LL, 1LL, 35184372088832LL},
{0LL}};

static const int jjcompositeState[][4] = {
{}, 
{}, 
{}, 
{}, 
{}, 
{}, 
{}, 
{}, 
{}, 
{2, 3, 4, 6}};

static const int jjmatchKinds[] = {
13, 
13, 
12, 
12, 
2147483647, 
12, 
2147483647, 
2147483647, 
12, 
2147483647};

static const int jjnextStateSet[][5] = {
{1, 1}, 
{1, 1}, 
{4, 2, 3, 4, 6}, 
{0}, 
{1, 1}, 
{0}, 
{4, 0, 5, 7, 8}, 
{1, 3}, 
{0}, 
{0}};

static const int jjInitStates[]  = {
0, -1, 9};

static const int canMatchAnyChar[] = {
2147483647, 8, 2147483647};

static const JJString jjstrLiteralImages[] = {
JJEMPTY, 
JAVACC_WIDE(\40), 
JAVACC_WIDE(\11), 
JAVACC_WIDE(\12), 
JAVACC_WIDE(\15), 
JAVACC_WIDE(\57\52), 
JAVACC_WIDE(\57\52), 
JAVACC_WIDE(\52\57), 
JJEMPTY, 
JJEMPTY, 
JJEMPTY, 
JAVACC_WIDE(\55\55), 
JJEMPTY, 
JJEMPTY
};

static const unsigned long long jjtoSkip[] = {
   33278ULL};
static const unsigned long long jjtoSpecial[] = {
   38912ULL};
static const unsigned long long jjtoMore[] = {
   32768ULL};
static const unsigned long long jjtoToken[] = {
   42497ULL};
static const int jjnewLexState[] = {
-1, -1, -1, -1, -1, 1, -1, -1, -1, -1, -1, 2, 0, -1};

static const JJChar lexStateNames_arr_0[] = 
{0x44, 0x45, 0x46, 0x41, 0x55, 0x4c, 0x54, 0};
static const JJChar lexStateNames_arr_1[] = 
{0x4c, 0x69, 0x6e, 0x65, 0x73, 0x43, 0x6f, 0x6d, 0x6d, 0x65, 0x6e, 0x74, 0};
static const JJChar lexStateNames_arr_2[] = 
{0x4c, 0x69, 0x6e, 0x65, 0x43, 0x6f, 0x6d, 0x6d, 0x65, 0x6e, 0x74, 0};
static const JJString lexStateNames[] = {
lexStateNames_arr_0, 
lexStateNames_arr_1, 
lexStateNames_arr_2
};


bool SpecialTokenTokenManager::moveToNextChar() {
  if(input_stream->endOfInput())
    return false;

  curChar = input_stream->readChar();
  return true;
}


  int linesCommentCount = 0;

/** Constructor. */
SpecialTokenTokenManager::SpecialTokenTokenManager(JAVACC_CHARSTREAM* stream, int lexState)
{
    ReInit(stream, lexState);
}

/** Reinitialise parser. */
void SpecialTokenTokenManager::ReInit(JAVACC_CHARSTREAM* stream, int lexState)
{
    defaultLexState = 0;
    curLexState = 0;
    moveIndex = 1;
    errorHandler = nullptr;
    delete_eh = false;

    for (int i = 0; i < 10; i++) {
      int ind = 0;
      // We originally generate something like RLE for the static arrays and
      // we actually expannd them here.
      for (int j = 0; j < (int) jjCharData[i][0]; j += 2) {
        for (int k = 0; k < (int) jjCharData[i][j + 1]; k++) {
          jjChars[i][ind++] = jjCharData[i][j + 2];
        }
      }
    }

    jjmatchedPos = 0;
    curLexState = defaultLexState;
    input_stream = stream;
    SwitchTo(lexState);
    errorHandler = new TokenManagerErrorHandler();
}

/** Switch to specified lex state. */
void SpecialTokenTokenManager::SwitchTo(int lexState)
{
    if (lexState > LineComment || lexState < DEFAULT) {
      JJString message;
      message += JAVACC_WIDE(Error: Ignoring invalid lexical state : );
      message += lexState; message += JAVACC_WIDE(. State unchanged.);
      throw new TokenManagerError(message, INVALID_LEXICAL_STATE);
    } else
      curLexState = lexState;
}

int SpecialTokenTokenManager::jjRunStringLiteralMatch() {
  int curPos = 0;
  int key = (int)curLexState << 16 | curChar;
  int startState = jjInitStates[curLexState];
  int index = getStartAndSize(key, 0);
  if (index != -1) {
    for (int i = 0; i < getStartAndSize(key, 1); i++) {
      int len = (int) stringLiterals[index++];
      int ignoreCase = (int) stringLiterals[index++];
      do {
        if (curChar != stringLiterals[index + curPos] &&
            (ignoreCase == 0 || curChar != stringLiterals[index + len + curPos])) break;
        if (++curPos == len) break;
        if (!moveToNextChar()) {
          --curPos;
          break;
        }
      } while(curPos < len);
      if (curPos == len) {
        jjmatchedKind = (int) stringLiterals[index + len + (ignoreCase * len)];
        jjmatchedPos = curPos;
        startState = (int) stringLiterals[index + len + (ignoreCase * len) + 1];
        if (!moveToNextChar()) {
          return curPos;
        }
        curPos++;
        break;
      } else {
        index += len + (ignoreCase * len) + 2;
        input_stream->backup(curPos + 1);
        curPos = 0;
        if (!moveToNextChar()) {
          assert(false);
        }
      }
    }
  } else {
  }
  return jjMoveNfa(startState, curPos);
}

int SpecialTokenTokenManager::jjMoveNfa(int startState, int curPos) {

  if (startState < 0) {
    return curPos;
  }

  // We have an array indexed by the NFA state number to roughly indicate
  // the input position so when the input reaches part 0x7fffffff (which
  // should be extremely rare), we need to reset them all back to zero.
  if (++moveIndex == 0x7fffffff) {
    for (int i = 0; i < 10; i++) moved[i] = 0;
    moveIndex = 1;
  }

  // We initialize the kind to MAX value so that when a match is found, we can
  // simply check if it's less than the current match and store it in that
  // case. This helps implement the 'first occurring' rule properly.
  int cnt = 0;
  stateSet[cnt++] = startState;
  moved[startState] = moveIndex;
 
  // Some NFA states have epsilon transitions (move on empty string). So we
  // just start with all of them. Note that the nextStates array already adds
  // the epsilon closure. Only the initial state needs to do this explicitly.
  for (int s : jjcompositeState[startState]) { 
    if (moved[s] != moveIndex) {
      stateSet[cnt++] = s;
      moved[s] = moveIndex;
    }
  }

  do {
    int newCnt = 0;
    int kind = 0x7fffffff;
    if (++moveIndex == 0x7fffffff) {
      for (int i = 0; i < 10; i++) moved[i] = 0;
      moveIndex = 1;
    }

    int vectorIndex = curChar >> 6;
    unsigned long long bitpattern = (1ULL << (curChar & 0x3f));
    // unsigned long long bitpattern = (1ULL << (curChar & 077)) & 0x7fffffe07fffffeULL;
    do {
      int state = stateSet[--cnt];
      if ((jjChars[state][vectorIndex] & bitpattern) != 0L) {
        // Current input character can move this NFA state. So add all the
        // next states of the current states for use with the next input char.
        for (int idx = 0; idx < jjnextStateSet[state][0]; idx++) {
          int newState = jjnextStateSet[state][idx + 1];
          if (moved[newState] != moveIndex) {
            // We add each state only once.
            newStateSet[newCnt++] = newState;
            moved[newState] = moveIndex;
          }
        }
        int newKind = jjmatchKinds[state];
        if (kind > newKind) {
          // It's a state so store the matched kind if it's smaller than
          // what's already matched.
          kind = newKind;
        }
      }
    } while (cnt > 0);

    if (kind != 0x7fffffff) {
      // We found a match. So remember the kind and position of the match.
      jjmatchedKind = kind;
      jjmatchedPos = curPos;
      // Reset the kind to max value so we can contine looking for a longer
      // match.
      kind = 0x7fffffff;
    }

    // Swap the current and next state sets.
    int tmp;
    for(int i = 0; i < 10; i++) {
      tmp = stateSet[i];
      stateSet[i] = newStateSet[i];
      newStateSet[i] = tmp;
    }
    // Reset the number of states.
    cnt = newCnt;
    if (newCnt == 0) {
      // There were no transitions from any of the current states on the
      // current input. So we are done.
      return curPos;
    }
    // Read the next character and try to continue running the NFA.
    if (!moveToNextChar()) {
      // EOF reached!
      return curPos;
    }
    ++curPos;
  } while (cnt > 0);

  throw "Interal error. Please submit a bug at:https://github.com/javacc/javacc/issues";
//  return curPos;
}

static bool isToken(int kind) {
  return (jjtoToken[kind >> 6] & (1ULL << (kind & 077))) != 0L;
}

static bool isSkip(int kind) {
  return (jjtoSkip[kind >> 6] & (1ULL << (kind & 077))) != 0L;
}

static bool isSpecial(int kind) {
  return (jjtoSpecial[kind >> 6] & (1ULL << (kind & 077))) != 0L;
}

static bool isMore(int kind) {
  return (jjtoMore[kind >> 6] & (1ULL << (kind & 077))) != 0L;
}

Token * SpecialTokenTokenManager::jjFillToken() {
  Token * t;
  JJString curTokenImage;
  int beginLine;
  int endLine;
  int beginColumn;
  int endColumn;
  if (jjmatchedPos < 0) {
    if (image.length() == 0) {
      curTokenImage = JJEMPTY;
    } else {
      curTokenImage = image;
    }
    beginLine = endLine = input_stream->getEndLine();
    beginColumn = endColumn = input_stream->getEndColumn();
  } else {
    JJString im = jjstrLiteralImages[jjmatchedKind];
    curTokenImage = (im.length() == 0) ? input_stream->getImage() : im;
    beginLine = input_stream->getBeginLine();
    beginColumn = input_stream->getBeginColumn();
    endLine = input_stream->getEndLine();
    endColumn = input_stream->getEndColumn();
  }

    t = DefaultToken::newToken(jjmatchedKind, curTokenImage);

   t->beginLine() = beginLine;
   t->endLine() = endLine;
   t->beginColumn() = beginColumn;
   t->endColumn() = endColumn;

   return t;
}

/** Get the next Token. */
Token * SpecialTokenTokenManager::getNextToken() {
  Token * specialToken = nullptr;
  Token * matchedToken;
  int lastReadPosition = 0;

  EOFLoop:
  for (;;) {
    if(input_stream->endOfInput()) {
      // No input. So return EOF token.
      jjmatchedKind = _EOF;
      jjmatchedPos = -1;
      matchedToken = jjFillToken();
      matchedToken->specialToken() = specialToken;
      return matchedToken;
    }

    // First see if we have any input at all.
    curChar = input_stream->beginToken();


    // Set matched kind to a MAX VALUE to implement largest, first occuring rule
    // i.e., smallest kind value matched should be used.
    image = jjimage;
    // image->setLength(0);
    jjimageLen = 0;

    for (;;) {
      jjmatchedKind = 0x7fffffff;
      jjmatchedPos = 0;
      lastReadPosition = jjRunStringLiteralMatch();
      if (jjmatchedPos == 0 && jjmatchedKind > canMatchAnyChar[curLexState]) {
        jjmatchedKind = canMatchAnyChar[curLexState];
      }

      if (jjmatchedKind != 0x7fffffff) {
        // We have a match!
  
        // Put back any characters looked ahead.
        input_stream->backup(lastReadPosition - jjmatchedPos);
        if (isToken(jjmatchedKind)) {
          // Matched kind is a real TOKEN.
          matchedToken = jjFillToken();
          matchedToken->specialToken() = specialToken;
          tokenLexicalActions(matchedToken);
          if (jjnewLexState[jjmatchedKind] != -1) {
            curLexState = jjnewLexState[jjmatchedKind];
          }
          return matchedToken;
        } else
        if (isSkip(jjmatchedKind) || isSpecial(jjmatchedKind)) {
          // Matched kind is a SKIP or SPECIAL_TOKEN.
          if (isSpecial(jjmatchedKind)) {
            matchedToken = jjFillToken();
            if (specialToken == nullptr) {
              specialToken = matchedToken;
            } else {
              matchedToken->specialToken() = specialToken;
              specialToken = (specialToken->next() = matchedToken);
            }
            skipLexicalActions(matchedToken);
          } else {
            skipLexicalActions(nullptr);
          }
          if (jjnewLexState[jjmatchedKind] != -1) {
            curLexState = jjnewLexState[jjmatchedKind];
          }
          goto EOFLoop;
        }
        // Here it's a MORE.
        moreLexicalActions();
        if (jjnewLexState[jjmatchedKind] != -1) {
          curLexState = jjnewLexState[jjmatchedKind];
        }
        lastReadPosition = 0;
        jjmatchedKind = 0x7fffffff;
        do {
          curChar = input_stream->readChar();
        } while(curChar >= 0);
      }
      int error_line = input_stream->getEndLine();
      int error_column = input_stream->getEndColumn();
      JJString error_after = JJEMPTY;
      bool EOFSeen = false;

      if(input_stream->endOfInput()) {
        EOFSeen = true;
        error_after = lastReadPosition <= 1 ? JJEMPTY : input_stream->getImage();
        if (curChar == '\n' || curChar == '\r') {
           error_line++;
           error_column = 0;
        }
        else
           error_column++;
      }
      if (!EOFSeen) {
        error_after = lastReadPosition <= 1 ? JJEMPTY : input_stream->getImage();
      }
      errorHandler->lexicalError(EOFSeen, curLexState, error_line, error_column, error_after, curChar, this);
      goto EOFLoop;
    }
  }
}
int SpecialTokenTokenManager::getStartAndSize(int index, int isCount)
{
  switch(index) {
    case 32: { return (isCount == 0) ? 0 : 1;}
    case 9: { return (isCount == 0) ? 5 : 1;}
    case 10: { return (isCount == 0) ? 10 : 1;}
    case 65578: { return (isCount == 0) ? 15 : 1;}
    case 13: { return (isCount == 0) ? 21 : 1;}
    case 45: { return (isCount == 0) ? 26 : 1;}
    case 65583: { return (isCount == 0) ? 32 : 1;}
    case 47: { return (isCount == 0) ? 38 : 1;}
  }
  return -1;
}

void SpecialTokenTokenManager::tokenLexicalActions(Token* matchedToken) {
  switch(matchedToken->kind()) {
    default: break;
  }
}
void SpecialTokenTokenManager::skipLexicalActions(const Token* matchedToken) {
  switch(jjmatchedKind) {
    case 5: {

       linesCommentCount = 1 ;
      break;
    }
    case 6: {

       linesCommentCount += 1 ;
      break;
    }
    case 7: {

       linesCommentCount -= 1; SwitchTo( linesCommentCount==0 ? DEFAULT : LinesComment ) ;
      break;
    }
    default: break;
  }
  switch(jjmatchedKind) {
    default: break;
  }
}
void SpecialTokenTokenManager::moreLexicalActions() {
jjimageLen += (lengthOfMatch = jjmatchedPos + 1);
  switch(jjmatchedKind) {
    default: break;
  }
}
/* JavaCC - OriginalChecksum=05e0f33f0c725e9d207279e94d2b1f1f (do not edit this line) */
