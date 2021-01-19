#include <iostream>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <stdlib.h>
#include "StreamReader.h"

#include "SpecialToken.h"
#include "JavaCC.h"
#include "SpecialTokenTokenManager.h"
#include "ParseException.h"
#include "DefaultCharStream.h"
using namespace std;


JJString ReadFileFully() {
    JJString code;
    code =
"AA\n"
"/* kk */\n"
"DD -- ccc\n"
"BB\n"
"BB\n"
;
    return code;
}
static void usage(int argc, char**argv) {
	cerr << "IDL" << " [ spl in out err ]" << endl;
}
int main(int argc, char**argv) {
	istream*	input  = &cin;
	ostream*	output = &cout;
	ostream*	error  = &cerr;
	ifstream	spl;
	ifstream	ifs;
	ofstream	ofs;
	ofstream	efs;
	StreamReader*	sr = nullptr;
	CharStream *	cs = nullptr;

	try {
		if (argc == 5) {
			spl.open(argv[1]);
			ifs.open(argv[2]);
			ofs.open(argv[3]);
			efs.open(argv[4]);
			if (ifs.is_open() && ofs.is_open() && efs.is_open() && spl.is_open()) {
				input = &ifs;	output = &ofs;	error = &efs;
				sr = new StreamReader(spl);
                cs = new DefaultCharStream(sr);
			}
			else {
				cerr << "cannot open spl or in or out or err file" << endl;
				return 8;
			}
		} else
		if (argc == 1) {
			JJString s = ReadFileFully();
			*output << s << endl;
            cs = new DefaultCharStream(s.c_str(), s.size() - 1, 1, 1);
		}
		else {
			usage(argc, argv);
			return 0;
		}
		TokenManager *scanner = new SpecialTokenTokenManager(cs);
		SpecialToken parser(scanner);
		parser.Input();
     	*output << "IDL Parser Version 0.1:  IDL file parsed successfully." << endl;
	} catch (const ParseException& e) {
		clog << e.expectedTokenSequences << endl;
	}
	catch (...) {

	}
	if (spl.is_open()) spl.close();
	if (ifs.is_open()) ifs.close();
	if (ofs.is_open()) ofs.close();
	if (efs.is_open()) efs.close();
	if (cs) delete cs;
	if (sr) delete sr;

	return 0;
}
