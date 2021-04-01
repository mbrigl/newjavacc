#include "src/test/java/org/parser/CharStream.h"
#include "src/test/java/org/parser/JavaCC.h"
#include "src/test/java/org/parser/ParseException.h"
#include "src/test/java/org/parser/Expression.h"
#include "src/test/java/org/parser/ExpressionTokenManager.h"

using namespace std;

JJSimpleString ReadFileFully(char *file_name) {
    return "'a'\n";
}

// ' = 39
// a = 97
// ä = 132

int main(int argc, char** argv) {
    cout << "Reading from standard input..." << endl;
    JJSimpleString s = ReadFileFully(argv[1]);
    try {
        CharStream *stream = new CharStream(s.c_str(), s.size() - 1, 1, 1);
        ExpressionTokenManager *scanner = new ExpressionTokenManager(stream);
        Expression parser(scanner);
        Node* n = parser.compile();
        static_cast<SimpleNode*>(n)->dump("");
        cout << "Thank you." << endl;
    } catch (const ParseException& e) {
        cout << "Exception from standard input..." << endl;
    }
    return 0;
}





//#include <iostream>

//#include "src/test/java/org/parser/CharStream.h"
//#include "src/test/java/org/parser/ExpressionTokenManager.h"

//using namespace JavaCC;

//int main()
//{
//  JJString string = "ns.attr IS 56";
//  CharStream stream(string, 0, 0, 1024);
//  ExpressionTokenManager manager(&stream, 0);
//  Token *t = nullptr;
//  while ((t = manager.getNextToken())->kind != 0) {
//    std::cout << t->image << "(" << t->kind << ") " << std::endl;
//  }
//  return 0;
//}
