
#include "HackParser.hpp"

HackParser::HackParser(std::string filePath)
{
    inputFile.open(filePath);
    symbol = "";
    dest = "";
    comp = "";
    jump = "";

    type = UNSET;
}

HackParser::~HackParser()
{
    inputFile.close();
}

void HackParser::Next()
{
    std::string currentLine;
    getline(inputFile, currentLine);

    if(currentLine[0] == '@')
        processA_INS(currentLine);
    else
        processC_INS(currentLine);
}

void HackParser::processA_INS(std::string& str)
{
    symbol = str.substr(1,str.length()-1);
    dest = "";
    comp = "";
    jump = "";
    type = A_INS;
}

void HackParser::processC_INS(std::string& str)
{
    int conpBreak = str.find_first_of('=');
    int jumpBreak = str.find_first_of(':');
    symbol="";
    dest = str.substr(0,conpBreak-1);
    comp = str.substr(conpBreak+1, jumpBreak-1);
    jump = str.substr(jumpBreak+1,str.length()-1);
    type = C_INS;
}

bool HackParser::hasMore()
{
    return inputFile.peek() != EOF;
}