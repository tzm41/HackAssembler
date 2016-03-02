//
// Created by Colin Tan on 3/2/16.
// SymbolTable.cpp
//

#include "SymbolTable.h"

using namespace std;

SymbolTable::SymbolTable() : table_() {
    table_["SP"] = 0;
    table_["LCL"] = 1;
    table_["ARG"] = 2;
    table_["THIS"] = 3;
    table_["THAT"] = 4;
    table_["SCREEN"] = 16384;
    table_["KBD"] = 24576;

    for (int i = 0; i <= 15; ++i)
        table_["R" + to_string(i)] = i;
}

void SymbolTable::addEntry(string symbol, int address) {
    table_[symbol] = address;
}

bool SymbolTable::contains(string symbol) {
    return table_.find(symbol) != table_.end();
}

int SymbolTable::getAddress(string symbol) {
    map<string, int>::iterator it = table_.find(symbol);

    if (it != table_.end())
        return it->second;

    return -1;
}