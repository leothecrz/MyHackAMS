
#include "HackParser.hpp"

HackParser::HackParser(std::string filePath)
{
    inputFile.open(filePath);
    symbol = "";
    dest = "";
    comp = "";
    jump = "";
}

HackParser::~HackParser()
{

}

void HackParser::Next()
{
    std::string currentLine;
    getline(inputFile, currentLine);

    for(char c : currentLine)
    {

    }




}

bool HackParser::hasMore()
{
    return inputFile.peek() != EOF;
}