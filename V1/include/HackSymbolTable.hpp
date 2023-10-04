#pragma once

#include <map>
#include <string>
#include <iostream>

class HackSymbolTable
{

    private:
        std::map<std::string, int> table;

    public:
        HackSymbolTable();
        ~HackSymbolTable();

        void insertSymbol(std::string sym, int value );

        std::string getSymbolVallue(const std::string& sym);

        bool hasSymbol(const std::string& sym);

        std::map<std::string, int>& getTable();
};