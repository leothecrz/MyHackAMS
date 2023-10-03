
#include "HackParser.hpp"

HackParser::HackParser(std::string filePath)
{
    inputFile.open(filePath);
    reset();
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
    reset();
    symbol = trimWhiteSpace( str.substr(1,str.length()-1) );
    type = A_INS;
}

void HackParser::processC_INS(std::string& str)
{
    int compBreak = str.find_first_of('=');
    int jumpBreak = str.find_first_of(':');
    
    reset();

    if( compBreak != -1 )
    {
        dest = trimWhiteSpace( str.substr(0,compBreak-1) );
        comp = trimWhiteSpace( str.substr(compBreak+1, jumpBreak-compBreak-1) );
    }
    else
    {
        comp = trimWhiteSpace( str.substr(0,jumpBreak) );
    }

    if(jumpBreak != -1)
        jump = trimWhiteSpace( str.substr(jumpBreak+1) );

    type = C_INS;
}

bool HackParser::hasMore()
{
    std::cout << "\nPEEK " << inputFile.peek() << std::endl;
    return inputFile.peek() != EOF;
}

void HackParser::reset()
{
    symbol = "";
    dest = "";
    comp = "";
    jump = "";

    type = UNSET;
}

std::string trimWhiteSpace(const std::string& str)
{
    int f = str.find_first_not_of(' ');
    if(f == std::string::npos)
        return str;
    int e = str.find_last_not_of(' ');
    return str.substr(f, (e-f+1));
}