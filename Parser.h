//
// Created by Colin Tan on 2/27/16.
// Parser.h
//

#include <string>
#include <iostream>

#ifndef HACKASSEMBLER_PARSER_H
#define HACKASSEMBLER_PARSER_H

enum class CType {
    A_COMMAND, C_COMMAND, L_COMMAND, EMPTY
};

class Parser {
public:
    Parser(std::istream &in);

    bool hasMoreCommands();

    void advance();

    CType commandType();

    std::string symbol();

    std::string dest();

    std::string comp();

    std::string jump();

private:
    std::string line_;
    std::istream &in_;
};


#endif //HACKASSEMBLER_PARSER_H
