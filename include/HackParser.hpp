
#pragma once

#include <string>
#include <fstream>
#include <iostream>
#include <map>
#include "enumInstruc.hpp"
#include "Helper.hpp"

class HackParser
{
    private:

        std::map<std::string, int> symbolTable;
        int lineNumber_;
        std::string symbol_;
        std::string comp_;
        std::string dest_;
        std::string jump_;
        std::string filePath;
        INSTRUCTION_TYPES type_;
        std::ifstream inputFile_;

        std::string currentLine;
        bool fileSet;

        void fillCurrentLine();
        void setInstructionType();
        void sendOpenErrorMessage();

        void AINS();
        void CINS();
        void LINS();

        void reset();
        void getNext();
        void fillSymbolTable();
        void fillSymbolTableLoopFunction();
        void fillSymbolTableDefaults();
        std::string trimComments(const std::string& str);

    public:
        HackParser();
        ~HackParser();

        std::string trimWhiteSpace(const std::string& str);

        void loadFile(const std::string& filepath);
        bool endOfFile();
        void closeFile();

        bool hasSymbol(const std::string& sym);
        std::string getSymbolVallue(const std::string& sym);

        const int& getLN() {return lineNumber_;};
        const std::string& getSymb() {return symbol_;};
        const std::string& getComp() {return comp_;};
        const std::string& getDest() {return dest_;};
        const std::string& getJump() {return jump_;};
        const INSTRUCTION_TYPES& getType() {return type_;};

};
