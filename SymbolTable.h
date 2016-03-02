//
// Created by Colin Tan on 3/2/16.
// SymbolTable.h
//

#include <string>
#include <map>
#include <iostream>

#ifndef HACKASSEMBLER_SYMBOLTABLE_H
#define HACKASSEMBLER_SYMBOLTABLE_H


class SymbolTable {
public:
    SymbolTable();

    void addEntry(std::string symbol, int address);

    bool contains(std::string symbol);

    int getAddress(std::string symbol);

private:
    std::map<std::string, int> table_;
};


#endif //HACKASSEMBLER_SYMBOLTABLE_H
