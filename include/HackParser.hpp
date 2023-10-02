#pragma once

#include <string>
#include <fstream>
#include <iostream>

enum INSTRUCTION_TYPE
{
    UNSET,
    A_INS,
    C_INS,
    L_INS
};

class HackParser 
{
    public:
        HackParser(std::string filePath);
        ~HackParser();
        void Next();

        void processA_INS(std::string& str);
        void processC_INS(std::string& str);

        bool hasMore();
    
    
        INSTRUCTION_TYPE type;
        std::string symbol;
        std::string dest;
        std::string comp;
        std::string jump;
        std::ifstream inputFile;

};