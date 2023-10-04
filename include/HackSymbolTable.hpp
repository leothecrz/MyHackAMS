#pragma once

#include <map>
#include <string>

class HackSymbollTable
{
    public:
        HackSymbollTable();
        ~HackSymbollTable();

        void insertSymbol(std::string sym, int value );

        int getSymbolVallue(std::string sym);

        bool hasSymbol(std::string sym);

        
};