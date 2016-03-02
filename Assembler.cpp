#include <iostream>
#include <fstream>
#include "Parser.h"
#include "Code.h"
#include "SymbolTable.h"

using namespace std;

string getFileName(const string &s) {
    char sep = '/';

    size_t i = s.rfind(sep, s.length());
    if (i != string::npos) {
        return s.substr(i + 1, s.length() - i);
    }

    return s;
}

string getBaseName(const string &s) {
    size_t i = s.rfind('.', s.length());
    if (i != string::npos) {
        return s.substr(0, i);
    }

    return s;
}

inline bool isNumber(string s) {
    if (s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+')))
        return false;

    char *p;
    strtol(s.c_str(), &p, 10);

    return (*p == 0);
}

int main(int argc, char *argv[]) {

    if (argc > 0) {
        string readFilename = argv[1];
        string baseName = getBaseName(getFileName(readFilename));
        string writeFilename = baseName + ".hack";

        ifstream readFile;
        readFile.open(readFilename);

        ofstream writeFile;
        writeFile.open(writeFilename);

        Parser parser(readFile);

        SymbolTable table;
        int instAddress = 0;
        int varAddress = 16;

        if (!readFile.good()) {
            cout << "Error reading file: " << readFilename << endl;
            return -1;
        }


        // first pass, dealing with L-commands
        while (parser.hasMoreCommands()) {
            parser.advance();
            if (parser.commandType() == CType::A_COMMAND)
                instAddress++;
            else if (parser.commandType() == CType::L_COMMAND)
                table.addEntry(parser.symbol(), instAddress);
            else if (parser.commandType() == CType::C_COMMAND)
                instAddress++;
        }

        // reset ifstream to the start
        readFile.clear();
        readFile.seekg(0, ios::beg);

        // second pass, translating into binary
        while (parser.hasMoreCommands()) {
            parser.advance();

            if (parser.commandType() == CType::A_COMMAND) {
                string sym = parser.symbol();
                if (table.contains(sym)) {
                    bitset<16> inst((unsigned long) table.getAddress(sym));
                    inst.reset(15);
                    writeFile << inst.to_string() << endl;
                } else if (isNumber(sym)) {
                    bitset<16> inst(stoul(sym));
                    inst.reset(15);
                    writeFile << inst.to_string() << endl;
                } else {
                    table.addEntry(sym, varAddress);
                    bitset<16> inst((unsigned long) varAddress);
                    inst.reset(15);
                    varAddress++;
                    writeFile << inst.to_string() << endl;
                }
            } else if (parser.commandType() == CType::C_COMMAND) {
                string inst = "111"
                              + Code::comp(parser.comp()).to_string()
                              + Code::dest(parser.dest()).to_string()
                              + Code::jump(parser.jump()).to_string();
                writeFile << inst << endl;
            } else if (parser.commandType() == CType::L_COMMAND) {
                //should skip
            }
        }

        readFile.close();
        writeFile.close();

        return 0;
    }

    cout << "Error command argument" << endl;
    return -1;
}