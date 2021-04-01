/* Generated By:JavaCC: Do not edit this line. ExpressionTokenManager.java Version 8.0.0 */

                         

 
package org.parser;

public class ExpressionTokenManager  implements ExpressionConstants {

protected boolean moveToNextChar() {
  try {
    curChar = input_stream.readChar();
  } catch(java.io.IOException e) {
    return false;
  }
  return true;
}



    /** Constructor. */
    public ExpressionTokenManager(JavaCharStream stream){

      if (JavaCharStream.staticFlag)
            throw new RuntimeException("ERROR: Cannot use a static CharStream class with a non-static lexical analyzer.");

    input_stream = stream;
  }

  /** Constructor. */
  public ExpressionTokenManager (JavaCharStream stream, int lexState){
    ReInit(stream);
    SwitchTo(lexState);
  }

  /** Reinitialise parser. */
  
  public void ReInit(JavaCharStream stream)
  {

    jjmatchedPos = 0;
    curLexState = defaultLexState;
    input_stream = stream;
  }

  /** Reinitialise parser. */
  public void ReInit(JavaCharStream stream, int lexState)
  
  {
    ReInit(stream);
    SwitchTo(lexState);
  }

  /** Switch to specified lex state. */
  public void SwitchTo(int lexState) {
    curLexState = lexState;
  }

private  int jjRunStringLiteralMatch() {
  int curPos = 0;
  int key = (int)curLexState << 16 | curChar;
  int startState = jjInitStates[curLexState];
  if (startAndSize.containsKey(key)) {
    int[] arr = startAndSize.get(key);
    int index = arr[0];
    for (int i = 0; i < arr[1]; i++) {
      int len = stringLiterals[index++];
      int ignoreCase = stringLiterals[index++];
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
        jjmatchedKind = stringLiterals[index + len + (ignoreCase * len)];
        jjmatchedPos = curPos;
        startState = stringLiterals[index + len + (ignoreCase * len) + 1];
        if (!moveToNextChar()) {
          return curPos;
        }
        curPos++;
        break;
      } else {
        index += len + (ignoreCase * len) + 2;
        input_stream.backup(curPos + 1);
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

private   int[] stateSet = new int[32];
private   int[] newStateSet = new int[32];
private   long[] moved = new long[32];
private  long moveIndex = 1L;

private final int jjMoveNfa(int startState, int curPos) {

  if (startState < 0) {
    return curPos;
  }

  // We have a long array indexed by the NFA state number to roughly indicate
  // the input position so when the input reaches part Long.MAX_VALUE (which
  // should be extremely rare), we need to reset them all back to zero.
  if (++moveIndex == Long.MAX_VALUE) {
    for (int i = 0; i < 32; i++) moved[i] = 0L;
    moveIndex = 1L;
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
    int kind = Integer.MAX_VALUE;
    if (++moveIndex == Long.MAX_VALUE) {
      for (int i = 0; i < 32; i++) moved[i] = 0L;
      moveIndex = 1L;
    }

    int vectorIndex = curChar >> 6;
    long bitpattern = (1L << (curChar & 0x3f));
    do {
      int state = stateSet[--cnt];
      if ((jjChars[state][vectorIndex] & bitpattern) != 0L) {
        // Current input character can move this NFA state. So add all the
        // next states of the current states for use with the next input char.
        for (int newState : jjnextStateSet[state]) {
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

    if (kind != Integer.MAX_VALUE) {
      // We found a match. So remember the kind and position of the match.
      jjmatchedKind = kind;
      jjmatchedPos = curPos;
      // Reset the kind to max value so we can contine looking for a longer
      // match.
      kind = Integer.MAX_VALUE;
    }

    // Swap the current and next state sets.
    int[] tmp = stateSet;
    stateSet = newStateSet;
    newStateSet = tmp;
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

  assert(false) :
      "Interal error. Please submit a bug at: http://javacc.java.net.";
  return curPos;
}

private  int defaultLexState = 0;
protected  int curLexState = 0;
private  int jjmatchedPos;
private  int jjmatchedKind;
private  StringBuilder jjimage = new StringBuilder();
private StringBuilder image = jjimage;
private int jjimageLen;
private int lengthOfMatch;
protected int curChar;
protected  JavaCharStream input_stream;

public static boolean isToken(int kind) {
  return (jjtoToken[kind >> 6] & (1L << (kind & 0x3f))) != 0L;
}

public static final boolean isSkip(int kind) {
  return (jjtoSkip[kind >> 6] & (1L << (kind & 0x3f))) != 0L;
}

public static boolean isSpecial(int kind) {
  return (jjtoSpecial[kind >> 6] & (1L << (kind & 0x3f))) != 0L;
}

public static boolean isMore(int kind) {
  return (jjtoMore[kind >> 6] & (1L << (kind & 0x3f))) != 0L;
}

protected  Token jjFillToken() {
  Token t;
  String curTokenImage;
  int beginLine;
  int endLine;
  int beginColumn;
  int endColumn;
  if (jjmatchedPos < 0) {
    if (image == null) {
      curTokenImage = "";
    } else {
      curTokenImage = image.toString();
    }
    beginLine = endLine = input_stream.getEndLine();
    beginColumn = endColumn = input_stream.getEndColumn();
  } else {
    String im = jjstrLiteralImages[jjmatchedKind];
    curTokenImage = (im == null) ? input_stream.GetImage() : im;
    beginLine = input_stream.getBeginLine();
    beginColumn = input_stream.getBeginColumn();
    endLine = input_stream.getEndLine();
    endColumn = input_stream.getEndColumn();
  }

   t = Token.newToken(jjmatchedKind);
   t.kind = jjmatchedKind;
   t.image = curTokenImage;

   t.beginLine = beginLine;
   t.endLine = endLine;
   t.beginColumn = beginColumn;
   t.endColumn = endColumn;

   return t;
}

/** Get the next Token. */
public  Token getNextToken() {
  Token specialToken = null;
  Token matchedToken;
  int lastReadPosition = 0;

  EOFLoop:
  for (;;) {
    // First see if we have any input at all.
    try {
      curChar = input_stream.BeginToken();
    } catch(Exception e) {
      // No input. So return EOF token.
      jjmatchedKind = EOF;
      jjmatchedPos = -1;
      matchedToken = jjFillToken();
      matchedToken.specialToken = specialToken;
      return matchedToken;
    }

    // Set matched kind to a MAX VALUE to implement largest, first occuring rule
    // i.e., smallest kind value matched should be used.
    image = jjimage;
    image.setLength(0);
    jjimageLen = 0;

    MoreLoop: for (;;) {
      jjmatchedKind = Integer.MAX_VALUE;
      jjmatchedPos = 0;
      lastReadPosition = jjRunStringLiteralMatch();
      if (jjmatchedPos == 0 && jjmatchedKind > canMatchAnyChar[curLexState]) {
        jjmatchedKind = canMatchAnyChar[curLexState];
      }

      if (jjmatchedKind != Integer.MAX_VALUE) {
        // We have a match!
  
        // Put back any characters looked ahead.
        input_stream.backup(lastReadPosition - jjmatchedPos);
        if (isToken(jjmatchedKind)) {
          // Matched kind is a real TOKEN.
          matchedToken = jjFillToken();
          matchedToken.specialToken = specialToken;
          TokenLexicalActions(matchedToken);
          if (jjnewLexState[jjmatchedKind] != -1) {
            curLexState = jjnewLexState[jjmatchedKind];
          }
          return matchedToken;
        } else if (isSkip(jjmatchedKind)) {
          // Matched kind is a SKIP or SPECIAL_TOKEN.
          if (isSpecial(jjmatchedKind)) {
            matchedToken = jjFillToken();
            if (specialToken == null) {
              specialToken = matchedToken;
            } else {
              matchedToken.specialToken = specialToken;
              specialToken = (specialToken.next = matchedToken);
            }
            SkipLexicalActions(matchedToken);
          } else {
            SkipLexicalActions(null);
          }
          if (jjnewLexState[jjmatchedKind] != -1) {
            curLexState = jjnewLexState[jjmatchedKind];
          }
          continue EOFLoop;
        }
        // Here it's a MORE.
        MoreLexicalActions();
        if (jjnewLexState[jjmatchedKind] != -1) {
          curLexState = jjnewLexState[jjmatchedKind];
        }
        lastReadPosition = 0;
        jjmatchedKind = Integer.MAX_VALUE;
        try {
          curChar = input_stream.readChar();
          continue;
        }
        catch (java.io.IOException e1) { }
      }
      reportError(lastReadPosition);
    }
  }
}

protected  void reportError(int lastReadPosition) {
  int error_line = input_stream.getEndLine();
  int error_column = input_stream.getEndColumn();
  String error_after = null;
  boolean EOFSeen = false;
  try {
    input_stream.readChar();
    input_stream.backup(1);
  } catch (java.io.IOException e1) {
    EOFSeen = true;
    error_after = lastReadPosition <= 1 ? "" : input_stream.GetImage();
    if (curChar == '\n' || curChar == '\r') {
       error_line++;
       error_column = 0;
    }
    else
       error_column++;
  }
  if (!EOFSeen) {
    input_stream.backup(1);
    error_after = lastReadPosition <= 1 ? "" : input_stream.GetImage();
  }
  throw new TokenMgrException(EOFSeen, curLexState, error_line, error_column,
                          error_after, curChar, TokenMgrException.LEXICAL_ERROR);
}

private static final java.util.Map<Integer, int[]> startAndSize =
    new java.util.HashMap<Integer, int[]>();


private static final long[][] jjChars = new long[32][];
private static void InitNfaData() {
  for (int i = 0; i < 32; i++) {
    jjChars[i] = new long[1024];
    int ind = 0;
    // We originally generate something like RLE for the static arrays and
    // we actually expannd them here.
    for (int j = 0; j < jjCharData[i].length; j += 2) {
      for (int k = 0; k < (int)jjCharData[i][j]; k++) {
        jjChars[i][ind++] = jjCharData[i][j + 1];
      }
    }
  }
}
public static String[] lexStateNames = {
"DEFAULT"
};
private static final int[] stringLiterals = {
1, 0, 32, 6, -1, 
1, 0, 40, 7, -1, 
1, 0, 9, 1, -1, 
1, 0, 41, 8, -1, 
2, 1, 105, 115, 73, 83, 21, -1, 
2, 1, 105, 115, 73, 83, 21, -1, 
1, 0, 10, 2, -1, 
1, 0, 11, 3, -1, 
1, 0, 12, 4, -1, 
1, 0, 44, 10, -1, 
1, 0, 13, 5, -1, 
1, 0, 46, 9, -1, 
4, 1, 110, 117, 108, 108, 78, 85, 76, 76, 19, -1, 
3, 1, 110, 111, 116, 78, 79, 84, 20, -1, 
4, 1, 110, 117, 108, 108, 78, 85, 76, 76, 19, -1, 
3, 1, 110, 111, 116, 78, 79, 84, 20, -1};
static void InitStringLiteralData() {
startAndSize.put(32, new int[]{0, 1});
startAndSize.put(40, new int[]{5, 1});
startAndSize.put(9, new int[]{10, 1});
startAndSize.put(41, new int[]{15, 1});
startAndSize.put(105, new int[]{20, 1});
startAndSize.put(73, new int[]{28, 1});
startAndSize.put(10, new int[]{36, 1});
startAndSize.put(11, new int[]{41, 1});
startAndSize.put(12, new int[]{46, 1});
startAndSize.put(44, new int[]{51, 1});
startAndSize.put(13, new int[]{56, 1});
startAndSize.put(46, new int[]{61, 1});
startAndSize.put(110, new int[]{66, 2});
startAndSize.put(78, new int[]{88, 2});
}
private static final long[][] jjCharData = {
new long[] {1, 549755813888L},
new long[] {1, 549755813888L},
new long[] {1, 549755813888L},
new long[] {1, -549755813889L, 1023, -1L},
new long[] {1, 549755813888L},
new long[] {1, 0L, 1, 576460745995190270L},
new long[] {1, 287948901175001088L, 1, 576460745995190270L},
new long[] {1, 17179869184L},
new long[] {1, -17179869185L, 1023, -1L},
new long[] {1, 17179869184L},
new long[] {1, 0L, 1, 16384L},
new long[] {1, 0L, 1, 8589934592L},
new long[] {1, 0L, 1, 16384L},
new long[] {1, 0L, 1, 144115188075855872L},
new long[] {1, 0L, 1, 4503599627370496L},
new long[] {1, 0L, 1, 2199023255552L},
new long[] {1, 0L, 1, 70368744177664L},
new long[] {1, 0L, 1, 2199023255552L},
new long[] {1, 0L, 1, 274877906944L},
new long[] {1, 0L, 1, 70368744177664L},
new long[] {1, 0L, 1, 512L},
new long[] {1, 70368744177664L},
new long[] {1, 287948901175001088L},
new long[] {1, 287948901175001088L},
new long[] {1, 281474976710656L},
new long[] {1, 70368744177664L},
new long[] {1, 70368744177664L},
new long[] {1, 287667426198290432L},
new long[] {1, 287948901175001088L},
new long[] {1, 287948901175001088L},
new long[] {1, 287948901175001088L},
new long[] {1, 287948901175001088L}};
private static final int[][] jjcompositeState = {
new int[]{0, 5, 7, 12, 20, 21, 24, 27}, 
new int[]{}, 
new int[]{}, 
new int[]{}, 
new int[]{}, 
new int[]{}, 
new int[]{}, 
new int[]{}, 
new int[]{}, 
new int[]{}, 
new int[]{}, 
new int[]{}, 
new int[]{}, 
new int[]{}, 
new int[]{}, 
new int[]{}, 
new int[]{}, 
new int[]{}, 
new int[]{}, 
new int[]{}, 
new int[]{}, 
new int[]{}, 
new int[]{}, 
new int[]{}, 
new int[]{}, 
new int[]{}, 
new int[]{}, 
new int[]{}, 
new int[]{}, 
new int[]{}, 
new int[]{}, 
new int[]{}};
private static final int[] jjmatchKinds = {
2147483647, 
2147483647, 
2147483647, 
2147483647, 
11, 
12, 
12, 
2147483647, 
2147483647, 
13, 
15, 
2147483647, 
2147483647, 
15, 
2147483647, 
2147483647, 
2147483647, 
2147483647, 
2147483647, 
2147483647, 
2147483647, 
2147483647, 
15, 
15, 
14, 
2147483647, 
2147483647, 
14, 
14, 
2147483647, 
2147483647, 
15};
private static final int[][] jjnextStateSet = {
new int[]{2, 3, 4}, 
new int[]{2, 3, 4}, 
new int[]{1}, 
new int[]{2, 3, 4}, 
new int[]{}, 
new int[]{6}, 
new int[]{6}, 
new int[]{8, 9}, 
new int[]{8, 9}, 
new int[]{}, 
new int[]{}, 
new int[]{10}, 
new int[]{11}, 
new int[]{}, 
new int[]{13}, 
new int[]{14}, 
new int[]{15}, 
new int[]{16}, 
new int[]{17}, 
new int[]{18}, 
new int[]{19}, 
new int[]{22, 23}, 
new int[]{22}, 
new int[]{23}, 
new int[]{25, 26}, 
new int[]{22}, 
new int[]{23}, 
new int[]{25, 26, 28, 29, 30, 31}, 
new int[]{28}, 
new int[]{25, 29}, 
new int[]{26, 30}, 
new int[]{31}};
private static final int[] jjInitStates  = {
0};
private static final int[] canMatchAnyChar = {
2147483647};
public static final String[] jjstrLiteralImages = {
null
, 
"\11", 
"\12", 
"\13", 
"\14", 
"\15", 
"\40", 
"\50", 
"\51", 
"\56", 
"\54", 
null
, 
null
, 
null
, 
null
, 
null
, 
null
, 
null
, 
null
, 
"\156\165\154\154", 
"\116\117\124", 
"\111\123"};
private static final long[] jjtoSkip = {
8388734L};
private static final long[] jjtoSpecial = {
8388608L};
private static final long[] jjtoMore = {
8388608L};
private static final long[] jjtoToken = {
12582785L};
private static final int[] jjnewLexState = {
-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
void TokenLexicalActions(Token matchedToken) {
  switch(matchedToken.kind) {
    default: break;
  }
}
void SkipLexicalActions(Token matchedToken) {
  switch(jjmatchedKind) {
    default: break;
  }
  switch(jjmatchedKind) {
    default: break;
  }
}
void MoreLexicalActions() {
jjimageLen += (lengthOfMatch = jjmatchedPos + 1);
  switch(jjmatchedKind) {
    default: break;
  }
}
static {
  InitStringLiteralData();
  InitNfaData(); } 
}
/* JavaCC - OriginalChecksum=681d4ca9befed5bb2645be839de7de54 (do not edit this line) */
