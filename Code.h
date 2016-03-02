//
// Created by Colin Tan on 3/1/16.
// Code.h
//

#include <string>
#include <bitset>

#ifndef HACKASSEMBLER_CODE_H
#define HACKASSEMBLER_CODE_H


class Code {
public:
    static std::bitset<3> dest(std::string in);

    static std::bitset<7> comp(std::string in);

    static std::bitset<3> jump(std::string in);
};


#endif //HACKASSEMBLER_CODE_H
