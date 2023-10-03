
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
    int compBreak = str.find_first_of('=');
    int jumpBreak = str.find_first_of(':');
    
    symbol="";

    dest = str.substr(0,compBreak-1);
    if( compBreak != -1 )
        comp = str.substr(compBreak+1, jumpBreak-compBreak-1);
    if(jumpBreak != -1)
        jump = str.substr(jumpBreak+1);

    type = C_INS;
}

bool HackParser::hasMore()
{
    std::cout << "PEEK " << inputFile.peek() << std::endl;
    return inputFile.peek() != EOF;
}