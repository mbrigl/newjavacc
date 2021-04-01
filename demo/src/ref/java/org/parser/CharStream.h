/* JavaCC generated file. */
#ifndef JAVACC_Expression_CHARSTREAM_H_
#define JAVACC_Expression_CHARSTREAM_H_

#include "JavaCC.h"

#ifndef INITIAL_BUFFER_SIZE
#define INITIAL_BUFFER_SIZE 4096
#endif


/**
 * This class describes a character stream that maintains line and
 * column number positions of the characters.  It also has the capability
 * to backup the stream to some extent.  An implementation of this
 * class is used in the TokenManager implementation generated by
 * JavaCCParser.
 *
 * All the methods except backup can be implemented in any fashion. backup
 * needs to be implemented correctly for the correct operation of the lexer.
 * Rest of the methods are all used to get information like line number,
 * column number and the string that constitutes a token and are not used
 * by the lexer. Hence their implementation won't affect the generated lexer's
 * operation.
 */


class CharStream {
public:
   void setTabSize(int i) { tabSize = i; }
   int  getTabSize() { return tabSize; }

private:
  int getBufcolumn(int pos) {
    if (trackLineColumn && pos>=0) {
      return bufcolumn[pos];
    } else {
      return -1;
    }
  }
  int getBufline(int pos) {
    if (trackLineColumn && pos>=0) {
      return bufline[pos];
    } else {
      return -1;
    }
  }

public:
  virtual int getColumn()        { return getBufcolumn(bufpos); }
  virtual int getLine()          { return getBufline(bufpos); }
  virtual int getEndColumn()     { return getBufcolumn(bufpos); }
  virtual int getEndLine()       { return getBufline(bufpos); }
  virtual int getBeginColumn()   { return getBufcolumn(tokenBegin); }
  virtual int getBeginLine()     { return getBufline(tokenBegin); }

  virtual bool getTrackLineColumn()         { return trackLineColumn; }
  virtual void setTrackLineColumn(bool val) { trackLineColumn = val; }

/**
 * Backs up the input stream by amount steps. Lexer calls this method if it
 * had already read some characters, but could not use them to match a
 * (longer) token. So, they will be used again as the prefix of the next
 * token and it is the implemetation's responsibility to do this right.
 */
  virtual inline void backup(int amount) {
    inBuf += amount;
    bufpos -= amount;
    if (bufpos < 0) {
      bufpos += bufsize;
    }
  }

/**
 * Returns the next character that marks the beginning of the next token.
 * All characters must remain in the buffer between two successive calls
 * to this method to implement backup correctly.
 */
  virtual inline JJChar BeginToken() {
    tokenBegin = -1;
    JJChar c = readChar();
    tokenBegin = bufpos;
    return c;
  }


/**
 * Returns the next character from the selected input.  The method
 * of selecting the input is the responsibility of the class
 * implementing this class.
 */
  virtual inline JJChar readChar() {
    if (inBuf > 0) {
      --inBuf;
      ++bufpos;
      if (bufpos == bufsize) {
        bufpos = 0;
      }
      return buffer[bufpos];
    }

    ++bufpos;
    if (bufpos >= maxNextCharInd) {
      FillBuff();
    }

    JJChar c = buffer[bufpos];

    if (trackLineColumn) {
      UpdateLineColumn(c);
    }

    return c;
  }


  virtual void ExpandBuff(bool wrapAround);
  virtual void FillBuff();

  /**
   * Returns a string made up of characters from the marked token beginning
   * to the current buffer position. Implementations can return
   * anything that they want to. For example, for efficiency, one might decide
   * to just return NULL, which is a valid implementation.
   */
  virtual JJString GetImage() {
    if (bufpos >= tokenBegin)
      return JJString(buffer + tokenBegin, bufpos - tokenBegin + 1);
    else
      return JJString(buffer + tokenBegin, bufsize - tokenBegin).append(buffer, bufpos + 1);
  }

  /**
   * Returns an array of characters that make up the suffix of length 'len' for
   * the currently matched token. This is used to build up the matched string
   * for use in actions in the case of MORE. A simple and inefficient
   * implementation of this is as follows :
   */
  virtual JJString GetSuffix(int len) {
    if ((bufpos + 1) >= len) {
      return JJString(buffer + bufpos - len + 1, len);
    }
    return JJString(buffer + bufsize - (len - bufpos - 1), len - bufpos - 1).append(buffer, bufpos + 1);
  }

  /**
   * The lexer calls this function to indicate that it is done with the stream
   * and hence implementations can free any resources held by this class.
   */
  virtual void DeleteBuffers();

  virtual ~CharStream() {
    if (deleteStream) {
     delete inputStream;
    }
    DeleteBuffers();
  }

  bool endOfInput() {
    return inBuf == 0 && bufpos + 1 >= maxNextCharInd && inputStream->endOfInput();
  }

  CharStream(const JJChar *buf, int sz, int startline,
                      int startcolumn, int buffersize) :
    bufline(nullptr), bufcolumn(nullptr), buffer(nullptr), bufpos(0), bufsize(0), 
    tokenBegin(0), column(0), line(0), prevCharIsCR(false), prevCharIsLF(false),
    available(0), maxNextCharInd(0), inBuf(0), tabSize(1), trackLineColumn(true),
    inputStream(nullptr), deleteStream(false) {
    ReInit(JJString(buf, sz), startline, startcolumn, buffersize);
  }

  CharStream(const JJChar *buf, int sz, int startline, int startcolumn) :
    bufline(nullptr), bufcolumn(nullptr), buffer(nullptr), bufpos(0), bufsize(0), 
    tokenBegin(0), column(0), line(0), prevCharIsCR(false), prevCharIsLF(false),
    available(0), maxNextCharInd(0), inBuf(0), tabSize(1), trackLineColumn(true),
    inputStream(nullptr), deleteStream(false) {
    ReInit(JJString(buf, sz), startline, startcolumn, INITIAL_BUFFER_SIZE);
  }

  CharStream(const JJString& str, int startline,
                      int startcolumn, int buffersize) :
    bufline(nullptr), bufcolumn(nullptr), buffer(nullptr), bufpos(0), bufsize(0), 
    tokenBegin(0), column(0), line(0), prevCharIsCR(false), prevCharIsLF(false),
    available(0), maxNextCharInd(0), inBuf(0), tabSize(1), trackLineColumn(true),
    inputStream(nullptr), deleteStream(false) {
    ReInit(str, startline, startcolumn, buffersize);
  }

  CharStream(const JJString& str, int startline, int startcolumn) :
    bufline(nullptr), bufcolumn(nullptr), buffer(nullptr), bufpos(0), bufsize(0), 
    tokenBegin(0), column(0), line(0), prevCharIsCR(false), prevCharIsLF(false),
    available(0), maxNextCharInd(0), inBuf(0), tabSize(1), trackLineColumn(true),
    inputStream(nullptr), deleteStream(false) {
    ReInit(str, startline, startcolumn, INITIAL_BUFFER_SIZE);
  }

  CharStream(ReaderStream *input_stream, int startline,
             int startcolumn, int buffersize) :
    bufline(nullptr), bufcolumn(nullptr), buffer(nullptr), bufpos(0), bufsize(0), 
    tokenBegin(0), column(0), line(0), prevCharIsCR(false), prevCharIsLF(false),
    available(0), maxNextCharInd(0), inBuf(0), tabSize(1), trackLineColumn(true),
    inputStream(nullptr), deleteStream(false) {
    ReInit(input_stream, startline, startcolumn, INITIAL_BUFFER_SIZE);
  }

  CharStream(ReaderStream *input_stream, int startline, int startcolumn) :
    bufline(nullptr), bufcolumn(nullptr), buffer(nullptr), bufpos(0), bufsize(0), 
    tokenBegin(0), column(0), line(0), prevCharIsCR(false), prevCharIsLF(false),
    available(0), maxNextCharInd(0), inBuf(0), tabSize(1), trackLineColumn(true),
    inputStream(nullptr), deleteStream(false) {
    ReInit(input_stream, startline, startcolumn, INITIAL_BUFFER_SIZE);
  }

  CharStream(ReaderStream *input_stream) :
    bufline(nullptr), bufcolumn(nullptr), buffer(nullptr), bufpos(0), bufsize(0), 
    tokenBegin(0), column(0), line(0), prevCharIsCR(false), prevCharIsLF(false),
    available(0), maxNextCharInd(0), inBuf(0), tabSize(1), trackLineColumn(true),
    inputStream(nullptr), deleteStream(false) {
    ReInit(input_stream, 1, 1, INITIAL_BUFFER_SIZE);
  }

  virtual void ReInit(ReaderStream *input_stream, int startline, int startcolumn, int buffersize);

  virtual void ReInit(ReaderStream *input_stream, int startline, int startcolumn) {
    ReInit(input_stream, startline, startcolumn, INITIAL_BUFFER_SIZE);
  }

  virtual void ReInit(ReaderStream *input_stream) {
    ReInit(input_stream, 1, 1, INITIAL_BUFFER_SIZE);
  }

  virtual void ReInit(const JJString& str, int startline,
                      int startcolumn, int buffersize);

  virtual void ReInit(const JJString& str, int startline,
                      int startcolumn) {
    ReInit(str, startline, startcolumn, INITIAL_BUFFER_SIZE);
  }

  virtual void adjustBeginLineColumn(int newLine, int newCol);

protected:
  virtual void UpdateLineColumn(JJChar c);

  int*               bufline;
  int*               bufcolumn;
  JJChar*  	         buffer;
  int                bufpos;
  int                bufsize;
  int                tokenBegin;
  int                column;
  int                line;
  bool               prevCharIsCR;
  bool               prevCharIsLF;
  int                available;
  int                maxNextCharInd;
  int                inBuf;
  int                tabSize;
  bool               trackLineColumn;
  ReaderStream*      inputStream;
  bool               deleteStream;
};


#endif
