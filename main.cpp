
#include "main.hpp"

int main(int charc, char** charv)
{
    {
        if(charc < 2)
        {
            std::cout << "No Input File" << std::endl;
            exit(0);
        }
        if(charc > 2)
        {
            std::cout << "TOO Many Arguments" << std::endl;
            exit(0);
        }
    }

    std::string fileName = extractFileName(charv[1]);
    std::string outFileName = fileName.append(".hack");
    fileExistCheck(outFileName);
    std::ofstream outFile(outFileName);
    
    HackParser parserMod;
    HackCoder coderMod;

    parserMod.loadFile(charv[1]);
    while(!parserMod.endOfFile())
    {
        std::cout << parserMod.getLN() <<"\n"<< parserMod.getType() <<"\n"<< parserMod.getSym() <<"\n"<< parserMod.getDest() <<"\n"<< parserMod.getComp() << "\n" << parserMod.getJump() << "\n";
        switch (parserMod.getType())
        {
            case A_INSTRUCTION:
                if( is_number( parserMod.getSym() ))
                    outFile << "0" << numToBin(parserMod.getSym());
                else
                    if(parserMod.hasSymbol(parserMod.getSym()))
                        outFile << "0" << numToBin( parserMod.getSymbolVallue(parserMod.getSym()) ) << "\n";
                    else    
                        {

                        }
        break;
            case C_INSTRUCTION:
                outFile << "111" 
                << coderMod.compToBin( parserMod.getComp() )
                << coderMod.destToBin( parserMod.getDest() )
                << coderMod.jumpToBin( parserMod.getJump() )
                << "\n";
        break;
            case L_INSTRUCTION:
        break;
            case UNSET:
        break;
            default:
        break;
        }
    }
    outFile.close();
}


std::string extractFileName(const char* str)
{
    std::string string = str;
    //int slashIndex = string.find_last_of('/');
    //int slashTwoIndex = string.find_last_of('\\');
    int fileMarker = string.find_last_of('.');
    //if(slashTwoIndex > slashIndex)
    //    slashIndex = slashTwoIndex;

    //if(slashIndex != -1)
        return string.substr(0, string.length()-fileMarker);

    //return string.substr(slashIndex+1, string.length()-slashIndex+1);

}

void fileExistCheck(const std::string& str)
{
    if(std::filesystem::exists(str))
    {
        std::cout << "The .HACK file already exists." << 
            "Do you want to replace it? (y/n)(1/0): ";
        char choice;
        std::cin >> choice;

        if (choice != 'y' && choice != 'Y' && choice != '1') 
        {
            std::cout << "Operation cancelled.\n";
            exit(0);
        }  
    }
     
}

bool is_number(const std::string& str)
{
    std::string::const_iterator charIT = str.begin();
    while ( charIT != str.end() && 
        std::isdigit(*charIT)) // escape on nondigit
        ++charIT;
    
    return !str.empty() && charIT == str.end(); // fails with early end
}

std::string numToBin(const std::string& str)
{
    int value = std::stoi(str);
    return std::bitset<15>(value).to_string(); 
}