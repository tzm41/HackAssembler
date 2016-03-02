//
// Created by Colin Tan on 2/27/16.
// Parser.cpp
//

#include "Parser.h"

using namespace std;

Parser::Parser(istream &in) : in_(in) {
}

bool Parser::hasMoreCommands() {
    return in_.good();
}

void Parser::advance() {
    if (in_.good())
        getline(in_, line_);

    // remove whitespaces
    line_.erase(remove_if(line_.begin(), line_.end(), ::isspace), line_.end());

    // skip comments
    unsigned long index = line_.find("//");
    line_ = line_.substr(0, index);

    // skip empty lines
    if (line_ == "" && in_.good())
        Parser::advance();
}

CType Parser::commandType() {
    if (line_ != "") {
        if (line_.at(0) == '@')
            return CType::A_COMMAND;
        else if (line_.at(0) == '(')
            return CType::L_COMMAND;
        else
            return CType::C_COMMAND;
    }
    return CType::EMPTY;
}

string Parser::symbol() {
    try {
        if (commandType() == CType::C_COMMAND)
            throw 1;
        else if (commandType() == CType::A_COMMAND)
            return line_.substr(1, line_.length() - 1);
        else if (commandType() == CType::L_COMMAND)
            return line_.substr(1, line_.length() - 2);
        else
            throw 2;
    } catch (int e) {
        if (e == 1)
            cout << "Exception, not A_COMMAND or L_COMMAND call on symbol()" << endl;
        if (e == 2)
            cout << "Exception, no more command" << endl;
    }
    return "";
}

string Parser::dest() {
    try {
        if (commandType() == CType::C_COMMAND) {
            unsigned long index = line_.find('=');
            if (index == string::npos)
                return "";
            else
                return line_.substr(0, index);
        } else
            throw;
    } catch (...) {
        cout << "Exception, not C_COMMAND call on dest()" << endl;
    }
    return "";
}

string Parser::comp() {
    try {
        if (commandType() == CType::C_COMMAND) {
            unsigned long index1 = line_.find('=');
            unsigned long index2 = line_.find(';');
            return line_.substr(index1 + 1, index2 - index1 - 1);
        } else
            throw;
    } catch (...) {
        cout << "Exception, not C_COMMAND call on comp()" << endl;
    }
    return "";
}

string Parser::jump() {
    try {
        if (commandType() == CType::C_COMMAND) {
            unsigned long index = line_.find(';');
            if (index == string::npos)
                return "";
            else
                return line_.substr(index + 1, line_.length() - 1);
        } else
            throw;
    } catch (...) {
        cout << "Exception, not C_COMMAND call on jump()" << endl;
    }
    return "";
}