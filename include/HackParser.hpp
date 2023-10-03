#pragma once

#include <string>
#include <fstream>
#include <iostream>

#include "InsEnum.hpp"

class HackParser 
{
    public:
        HackParser(std::string filePath);
        ~HackParser();
        void Next();

        void processA_INS(std::string& str);
        void processC_INS(std::string& str);

        bool hasMore();
    
        void reset();
    
        INSTRUCTION_TYPE type;
        std::string symbol;
        std::string dest;
        std::string comp;
        std::string jump;
        std::ifstream inputFile;

};