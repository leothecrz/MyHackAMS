
#include "HackSymbolTable.hpp"

HackSymbolTable::HackSymbolTable()
{
    table.insert({"SP", 0});
    table.insert({"LCL", 1});
    table.insert({"ARG", 2});
    table.insert({"THIS", 3});
    table.insert({"THAT", 4});
    table.insert({"SCREEN", 16384});
    table.insert({"KBD", 24576});
    table.insert({"R0", 0});
    table.insert({"R1", 1});
    table.insert({"R2", 2});
    table.insert({"R3", 3});
    table.insert({"R4", 4});
    table.insert({"R5", 5});
    table.insert({"R6", 6});
    table.insert({"R7", 7});
    table.insert({"R8", 8});
    table.insert({"R9", 9});
    table.insert({"R10", 10});
    table.insert({"R11", 11});
    table.insert({"R12", 12});
    table.insert({"R13", 13});
    table.insert({"R14", 14});
    table.insert({"R15", 15});
}

HackSymbolTable::~HackSymbolTable()
{

}

std::string HackSymbolTable::getSymbolVallue(const std::string& sym)
{
    std::map<std::string,int>::iterator it;
    it = table.find(sym);
    if( it != table.end() )
        return  std::to_string( table[sym] ); 
    std::cout << "ERROR in Gathering Symbols " << std::endl; 
    exit(1);
}

bool HackSymbolTable::hasSymbol(const std::string& sym)
{
    std::map<std::string,int>::iterator it;
    it = table.find(sym);

    if( it != table.end() )
        return true;
    return false;
}

void HackSymbolTable::insertSymbol(std::string sym, int val)
{
    table.insert({sym, val});
}

std::map<std::string, int>& HackSymbolTable::getTable()
{
    return table;
}