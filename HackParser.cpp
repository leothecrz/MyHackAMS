
#include "HackParser.hpp"

HackParser::HackParser()
{
    lineNumber_ = 0;
    fileSet = false;
    fillSymbolTableDefaults();
}

HackParser::~HackParser()
{
    if(fileSet)
        closeFile();
}

void HackParser::fillSymbolTableDefaults()
{
    symbolTable.insert({"SP", 0});
    symbolTable.insert({"LCL", 1});
    symbolTable.insert({"ARG", 2});
    symbolTable.insert({"THIS", 3});
    symbolTable.insert({"THAT", 4});
    symbolTable.insert({"R0", 0});
    symbolTable.insert({"R1", 1});
    symbolTable.insert({"R2", 2});
    symbolTable.insert({"R3", 3});
    symbolTable.insert({"R4", 4});
    symbolTable.insert({"R5", 5});
    symbolTable.insert({"R6", 6});
    symbolTable.insert({"R7", 7});
    symbolTable.insert({"R8", 8});
    symbolTable.insert({"R9", 9});
    symbolTable.insert({"R10", 10});
    symbolTable.insert({"R11", 11});
    symbolTable.insert({"R12", 12});
    symbolTable.insert({"R13", 13});
    symbolTable.insert({"R14", 14});
    symbolTable.insert({"R15", 15});
    symbolTable.insert({"SCREEN", 16384});
    symbolTable.insert({"KBD", 24576});
}

void HackParser::fillSymbolTableLoopFunction()
{

    if(type_ == A_INSTRUCTION && !is_number(symbol_) )
    {
        if ( !hasSymbol(symbol_) )
            symbolTable.insert({symbol_, lineNumber_});
        return;
    }

    if(type_ != L_INSTRUCTION)
        return;
    
    int pIndex = currentLine.find_first_of('(');
    int pTwoIndex= currentLine.find_first_of(')');
    std::string activeSym = trimWhiteSpace( currentLine.substr( pIndex + 1, pTwoIndex- pIndex- 1) );
    
    if( symbolTable.insert({activeSym, lineNumber_}).second )
        std::cout << activeSym << " " << lineNumber_ << "\n";
    
}

void HackParser::fillSymbolTable()
{
    while(!endOfFile())
    {
        fillSymbolTableLoopFunction();
    }
    
    inputFile_.clear();
    inputFile_.seekg(0, std::ios::beg);
    lineNumber_ = 0;
}

void HackParser::reset()
{
    symbol_= "";
    comp_ = "";
    dest_ = "";
    jump_ = "";
    type_ = UNSET;
}

void HackParser::sendOpenErrorMessage()
{
    std::cout << "The File Could Not Be Opened" << std::endl;
    exit(1);
}
 
void HackParser::loadFile(const std::string& filepath)
{
    if(!fileSet)
    {
        filePath = filepath;
        inputFile_.clear();
        inputFile_.open(filepath);
        if(!inputFile_.good())
            sendOpenErrorMessage();
        std::cout << "The File: " << filepath <<" was opened." << "\n";
        fileSet = true;

        fillSymbolTable();
    }   
    else
        std::cout << "File is already Open" << "\n";
}

std::string HackParser::trimWhiteSpace(const std::string& str)
{
    int f = str.find_first_not_of(' ');
    if(f == std::string::npos)
        return str;
    int e = str.find_last_not_of(' ');
    return str.substr(f, (e-f+1));
}

std::string HackParser::trimComments(const std::string& str)
{
    int index = str.find_first_of('/');
    if(index == std::string::npos)
        return str;
    
    if(index == 0)
        return "";

    return str.substr(0, index);
}

void HackParser::setInstructionType()
{
    currentLine = trimWhiteSpace( trimComments( currentLine ) );   
    reset();

    if(currentLine.length() < 1)
    {
        type_ = UNSET;
        return;
    }
        
    switch (currentLine[0])
    {
    case '@':
        lineNumber_++;
        AINS();
        break;
    case '(':
        LINS();
        break;
    case '/':
        type_ = UNSET;
        break;
    default:
        lineNumber_++;
        CINS();
        break;
    }

}

void HackParser::AINS()
{
    type_ = A_INSTRUCTION;
    symbol_ = trimWhiteSpace( currentLine.substr(1,currentLine.length()-1) );
}

void HackParser::CINS()
{
    type_ = C_INSTRUCTION;

    int destBreak = currentLine.find_first_of('=');
    int jumpBreak = currentLine.find_first_of(';');
    
    if(destBreak == std::string::npos)
    {
        if(jumpBreak == std::string::npos)
        {
            comp_ = currentLine;
            return;
        }

        comp_ = trimWhiteSpace( currentLine.substr(0, jumpBreak) );
        jump_ = trimWhiteSpace( currentLine.substr(jumpBreak+1) );
        return;
    }
    if(jumpBreak ==std::string::npos)
    {
        dest_ = trimWhiteSpace( currentLine.substr(0, destBreak ) );
        comp_ = trimWhiteSpace( currentLine.substr(destBreak+1) );
        return;
    }
    dest_ = trimWhiteSpace( currentLine.substr(0, destBreak-1) );
    comp_ = trimWhiteSpace( currentLine.substr(destBreak+1, jumpBreak-destBreak-1) );
    jump_ = trimWhiteSpace( currentLine.substr(jumpBreak+1) );
}

void HackParser::LINS()
{
    symbol_ = trimWhiteSpace( currentLine.substr(1,currentLine.length()-2) );
    type_ = L_INSTRUCTION;
}

void HackParser::fillCurrentLine()
{
    std::getline(inputFile_, currentLine);
    currentLine = trimWhiteSpace(currentLine);
}

void HackParser::getNext()
{
    fillCurrentLine();
    setInstructionType();
}

bool HackParser::endOfFile()
{
    std::cout << "\n PEEK " << inputFile_.peek() << std::endl;
    if (inputFile_.peek() != EOF )
    {
        getNext();
        return false;
    }
    else
        return true;
}

void HackParser::closeFile()
{
    if(fileSet)
        inputFile_.close();
}

bool HackParser::hasSymbol(const std::string& sym)
{
    std::map<std::string,int>::iterator it;
    it = symbolTable.find(sym);

    if( it != symbolTable.end() )
        return true;
    return false;
}

std::string HackParser::getSymbolValue(const std::string& sym)
{
    std::map<std::string,int>::iterator it;
    it = symbolTable.find(sym);
    if( it != symbolTable.end() )
        return  std::to_string( symbolTable[sym] ); 
    std::cout << "ERROR in Gathering Symbols " << std::endl; 
    exit(1);
}