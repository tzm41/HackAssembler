//
// Created by Colin Tan on 3/1/16.
// Code.cpp
//

#include "Code.h"

using namespace std;

bitset<3> Code::dest(string in) {
    bitset<3> ans;

    if (in.find("M") != string::npos)
        ans.set(0);
    if (in.find("D") != string::npos)
        ans.set(1);
    if (in.find("A") != string::npos)
        ans.set(2);

    return ans;
}

bitset<7> Code::comp(string in) {
    if (in == "0")
        return bitset<7>("0101010");
    else if (in == "1")
        return bitset<7>("0111111");
    else if (in == "-1")
        return bitset<7>("0111010");
    else if (in == "D")
        return bitset<7>("0001100");
    else if (in == "A")
        return bitset<7>("0110000");
    else if (in == "M")
        return bitset<7>("1110000");
    else if (in == "!D")
        return bitset<7>("0001101");
    else if (in == "!A")
        return bitset<7>("0110001");
    else if (in == "!M")
        return bitset<7>("1110001");
    else if (in == "-D")
        return bitset<7>("0001111");
    else if (in == "-A")
        return bitset<7>("0110011");
    else if (in == "-M")
        return bitset<7>("1001111");
    else if (in == "D+1")
        return bitset<7>("0011111");
    else if (in == "A+1")
        return bitset<7>("0110111");
    else if (in == "M+1")
        return bitset<7>("1110111");
    else if (in == "D-1")
        return bitset<7>("0001110");
    else if (in == "A-1")
        return bitset<7>("0110010");
    else if (in == "M-1")
        return bitset<7>("1110010");
    else if (in == "D+A")
        return bitset<7>("0000010");
    else if (in == "D+M")
        return bitset<7>("1000010");
    else if (in == "D-A")
        return bitset<7>("0010011");
    else if (in == "D-M")
        return bitset<7>("1010011");
    else if (in == "A-D")
        return bitset<7>("0000111");
    else if (in == "M-D")
        return bitset<7>("1000111");
    else if (in == "D&A")
        return bitset<7>("0000000");
    else if (in == "D&M")
        return bitset<7>("1000000");
    else if (in == "D|A")
        return bitset<7>("0010101");
    else if (in == "D|M")
        return bitset<7>("1010101");

    return bitset<7>();
}

bitset<3> Code::jump(string in) {
    bitset<3> ans;

    if (in == "JGT") {
        ans.set(0);
    } else if (in == "JEQ") {
        ans.set(1);
    } else if (in == "JGE") {
        ans.set(0);
        ans.set(1);
    } else if (in == "JLT") {
        ans.set(2);
    } else if (in == "JNE") {
        ans.set(0);
        ans.set(2);
    } else if (in == "JLE") {
        ans.set(1);
        ans.set(2);
    } else if (in == "JMP") {
        ans.set();
    }

    return ans;
}