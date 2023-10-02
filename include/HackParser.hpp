
#include "main.hpp"

class HackParser 
{
    HackParser(std::string filePath);
    ~HackParser();
    void Next();
    bool hasMore();
    
    INSTRUCTION_TYPE type;

    std::string symbol;
    std::string dest;
    std::string comp;
    std::string jump;

    std::ifstream inputFile;

};