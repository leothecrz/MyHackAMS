
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

void HackParser::reset()
{
    symbol_= "";
    comp_ = "";
    dest_ = "";
    jump_ = "";
    type_ = UNSET;
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

void HackParser::sendOpenErrorMessage()
{
    std::cout << "The File Could Not Be Opened" << std::endl;
    exit(EXIT_SUCCESS);
}
 
void HackParser::loadFile(const std::string& filepath)
{
    if(!fileSet)
    {
        filePath = filepath;
        inputFile_.open(filepath);
        if(inputFile_.failbit)
            sendOpenErrorMessage();
        std::cout << "The File: " << filepath <<" was opened." << "\n";
        fileSet = true;

        fillSymbolTable();
    }   
    else
    {
        // CLOSE FILE && OPEN NEW
    }
}

std::string HackParser::trimWhiteSpace(const std::string& str)
{
    int f = str.find_first_not_of(' ');
    if(f == std::string::npos)
        return str;
    int e = str.find_last_not_of(' ');
    return str.substr(f, (e-f+1));
}

void HackParser::setInstructionType()
{
    currentLine = trimWhiteSpace(currentLine);

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
        endOfFile(); // CALL GET NEXT SAFETLY
        break;
    default:
        lineNumber_++;
        CINS();
        break;
    }

}

void HackParser::AINS()
{
    reset();
    type_ = A_INSTRUCTION;
    symbol_ = trimWhiteSpace( currentLine.substr(1,currentLine.length()-1) );
}

void HackParser::CINS()
{
    reset();
    type_ = C_INSTRUCTION;

    int destBreak = currentLine.find_first_of('=');
    int jumpBreak = currentLine.find_first_of(':');
    
    if(destBreak == std::string::npos)
    {
        if(jumpBreak == std::string::npos)
        {
            comp_ = currentLine;
            return;
        }

        comp_ = trimWhiteSpace( currentLine.substr(0, jumpBreak-1) );
        jump_ = trimWhiteSpace( currentLine.substr(jumpBreak+1) );
        return;
    }
    if(jumpBreak ==std::string::npos)
    {
        dest_ = trimWhiteSpace( currentLine.substr(0, destBreak-1 ) );
        comp_ = trimWhiteSpace( currentLine.substr(destBreak+1) );
        return;
    }
    dest_ = trimWhiteSpace( currentLine.substr(0, destBreak-1) );
    comp_ = trimWhiteSpace( currentLine.substr(destBreak+1, jumpBreak-destBreak+1) );
    jump_ = trimWhiteSpace( currentLine.substr(jumpBreak+1) );
}

void HackParser::LINS()
{
    reset();
    symbol_ = trimWhiteSpace( currentLine.substr(1,currentLine.length()-2) );
    type_ = L_INSTRUCTION;
}

void HackParser::fillCurrentLine()
{
    std::getline(inputFile_, currentLine);
}

void HackParser::getNext()
{
    if(!fileSet)
    {
        std::cout << "No File Open" << "\n";
        return;
    }

    fillCurrentLine();
    setInstructionType();
}

void HackParser::closeFile()
{
    if(fileSet)
        inputFile_.close();
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
    if(type_ != L_INSTRUCTION)
        return;

    int pIndex = currentLine.find_first_of('(');
    int pTwoIndex= currentLine.find_first_of(')');

    std::string activeSym = trimWhiteSpace( currentLine.substr(pIndex+1, pIndex-pTwoIndex+1) );
    
    if( symbolTable.insert({activeSym, lineNumber_}).second )
        std::cout << activeSym << " " << lineNumber_ << "\n";
   
}

void HackParser::fillSymbolTable()
{
    while(!endOfFile())
    {
        fillSymbolTableLoopFunction();
    }
    closeFile();
    loadFile(filePath);
}

bool HackParser::hasSymbol(const std::string& sym)
{
    std::map<std::string,int>::iterator it;
    it = symbolTable.find(sym);

    if( it != symbolTable.end() )
        return true;
    return false;
}

std::string HackParser::getSymbolVallue(const std::string& sym)
{
    std::map<std::string,int>::iterator it;
    it = symbolTable.find(sym);
    if( it != symbolTable.end() )
        return  std::to_string( symbolTable[sym] ); 
    std::cout << "ERROR in Gathering Symbols " << std::endl; 
    exit(1);
}