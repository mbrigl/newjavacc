/* JavaCC generated file. */
#include "CharStream.h"

template <class T>
void ArrayCopy(T* src, int src_offset, T* dest, int dest_offset, int len) {
 for (int i = 0; i < len; i++) {
   dest[dest_offset + i] = src[src_offset + i];
 }
}

class StringReaderStream : public ReaderStream {
 public:
  StringReaderStream(const JJString& str) : str_(str), cur_(0), max_(str.size()) {}
  virtual size_t read(JJChar *bufptr, int offset, size_t len) {
    size_t count = str_.copy(bufptr + offset, len > max_ ? max_ : len, cur_);
    cur_ += count;
    max_ -= count;
    return count;
  }
  virtual ~StringReaderStream() {}
  virtual bool endOfInput() {
    return max_ == 0;
  }

 private:
  const JJString str_;
  size_t cur_;
  size_t max_;
};

void CharStream::ReInit(const JJString& str, int startline,
                        int startcolumn, int buffersize) {
  StringReaderStream *stream = new StringReaderStream(str);
  ReInit(stream, startline, startcolumn, buffersize);
  deleteStream = true;
}

void CharStream::ReInit(ReaderStream *input_stream, int startline,
                        int startcolumn, int buffersize) {
  if (deleteStream) {
   delete inputStream;
  }

  if (buffer) {
    DeleteBuffers();
  }

  available = bufsize = buffersize;
  buffer = new JJChar[buffersize];
  bufline = new int[buffersize];
  bufcolumn = new int[buffersize];

  column = startcolumn - 1;
  inputStream = input_stream;
  line = startline;
  prevCharIsLF = prevCharIsCR = false;
  tokenBegin = inBuf = maxNextCharInd = 0;
  bufpos = -1;
  deleteStream = false;
}

void CharStream::DeleteBuffers() {
  delete[] buffer;
  delete[] bufline;
  delete[] bufcolumn;
}

void CharStream::adjustBeginLineColumn(int newLine, int newCol) {
  int start = tokenBegin;
  int len;

  if (bufpos >= tokenBegin) {
    len = bufpos - tokenBegin + inBuf + 1;
  } else {
    len = bufsize - tokenBegin + bufpos + 1 + inBuf;
  }

  int i = 0, j = 0, k = 0;
  int nextColDiff = 0, columnDiff = 0;

  while (i < len && bufline[j = start % bufsize] ==
         bufline[k = (start + 1) % bufsize]) {
    bufline[j] = newLine;
    nextColDiff = columnDiff + bufcolumn[k] - bufcolumn[j];
    bufcolumn[j] = newCol + columnDiff;
    columnDiff = nextColDiff;
    i++;
    start++;
  }

  if (i < len) {
    bufline[j] = newLine++;
    bufcolumn[j] = newCol + columnDiff;

    while (i++ < len) {
      if (bufline[j = start % bufsize] != bufline[(start + 1) % bufsize])
        bufline[j] = newLine++;
      else
        bufline[j] = newLine;
      start++;
    }
  }

  line = bufline[j];
  column = bufcolumn[j];
}

void CharStream::ExpandBuff(bool wrapAround) {
  JJChar *newbuffer = new JJChar[bufsize + 2048];
  int *newbufline = new int[bufsize + 2048];
  int *newbufcolumn = new int[bufsize + 2048];

  if (wrapAround) {
    ArrayCopy(buffer, tokenBegin, newbuffer, 0, bufsize - tokenBegin);
    ArrayCopy(buffer, 0, newbuffer, bufsize - tokenBegin, bufpos);
    ArrayCopy(bufline, tokenBegin, newbufline, 0, bufsize - tokenBegin);
    ArrayCopy(bufline, 0, newbufline, bufsize - tokenBegin, bufpos);
    ArrayCopy(bufcolumn, tokenBegin, newbufcolumn, 0, bufsize - tokenBegin);
    ArrayCopy(bufcolumn, 0, newbufcolumn, bufsize - tokenBegin, bufpos);
    bufpos += (bufsize - tokenBegin);
  } else {
    ArrayCopy(buffer, tokenBegin, newbuffer, 0, bufsize - tokenBegin);
    ArrayCopy(bufline, tokenBegin, newbufline, 0, bufsize - tokenBegin);
    ArrayCopy(bufcolumn, tokenBegin, newbufcolumn, 0, bufsize - tokenBegin);
    bufpos -= tokenBegin;
  }

  maxNextCharInd = bufpos;
  DeleteBuffers();
  buffer = newbuffer;
  bufline = newbufline;
  bufcolumn = newbufcolumn;
  bufsize += 2048;
  available = bufsize;
  tokenBegin = 0;
}

void CharStream::FillBuff() {
  if (maxNextCharInd == available) {
    if (available == bufsize) {
      if (tokenBegin > 2048) {
        bufpos = maxNextCharInd = 0;
        available = tokenBegin;
      } else if (tokenBegin < 0) {
        bufpos = maxNextCharInd = 0;
      } else {
        ExpandBuff(false);
      }
    } else if (available > tokenBegin) {
      available = bufsize;
    } else if ((tokenBegin - available) < 2048) {
      ExpandBuff(true);
    } else {
      available = tokenBegin;
    }
  }

  size_t i = inputStream->read(buffer, maxNextCharInd, available - maxNextCharInd);
  if (i > 0) {
    maxNextCharInd += i;
  } else {
    --bufpos;
    backup(0);
    if (tokenBegin == -1) {
      tokenBegin = bufpos;
    }
  }
}

void CharStream::UpdateLineColumn(JJChar c) {
  column++;
  if (prevCharIsLF) {
    prevCharIsLF = false;
    column = 1;
    line++;
  } else if (prevCharIsCR) {
    prevCharIsCR = false;
    if (c == '\n') {
      prevCharIsLF = true;
    } else {
      column = 1;
      line++;
    }
  }

  switch (c) {
    case '\r' :
      prevCharIsCR = true;
      break;
    case '\n' :
      prevCharIsLF = true;
      break;
    case '\t' :
      column--;
      column += (tabSize - (column % tabSize));
      break;
    default :
      break;
  }

  bufline[bufpos] = line;
  bufcolumn[bufpos] = column;
}

