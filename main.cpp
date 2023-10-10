
#include "main.hpp"

std::string extractFileName(const char* str)
{
    std::string string = str;
    int fileMarker = string.find_last_of('.');
    return string.substr(0, fileMarker);
}

void fileExistCheck(const std::string& str)
{
    if(!std::filesystem::exists(str))
        return;
    
    std::cout << "The .HACK file already exists." << "Do you want to replace it? (y/n)(1/0): ";
    char choice;
    std::cin >> choice;

    if (choice != 'y' && choice != 'Y' && choice != '1') 
    {
        std::cout << "Operation cancelled.\n";
        exit(0);
    }  
}

void argumentSizeCheck(int inputs)
{
    if(inputs < 2)
    {
        std::cout << "No Input File" << std::endl;
        exit(0);
    }
    if(inputs > 2)
    {
        std::cout << "TOO Many Arguments" << std::endl;
        exit(0);
    }
}

std::string numToBin(const std::string& str)
{
    int value = std::stoi(str);
    return std::bitset<15>(value).to_string(); 
}

int main(int charc, char** charv)
{
    argumentSizeCheck(charc);

    std::string fileName = extractFileName(charv[1]);
    std::string outFileName = fileName.append(".hack");

    fileExistCheck(outFileName);
    std::ofstream outFile(outFileName);

    HackParser parserMod;
    HackCoder coderMod;
    parserMod.loadFile(charv[1]);

    while(!parserMod.endOfFile())
    {
        std::cout << parserMod.getLN() <<"\n"
        << parserMod.getType() <<"\n"
        << parserMod.getSymb() <<"\n"
        << parserMod.getDest() <<"\n"
        << parserMod.getComp() <<"\n" 
        << parserMod.getJump() <<"\n";

        switch ( parserMod.getType() )
        {
            case A_INSTRUCTION:
                if( is_number( parserMod.getSymb() ))
                    outFile << "0" << numToBin(parserMod.getSymb()) << "\n" ;
                else
                    if(parserMod.hasSymbol(parserMod.getSymb()))
                        outFile << "0" << numToBin( parserMod.getSymbolVallue(parserMod.getSymb()) ) << "\n";
                    else    
                        {
                            std::cout << "Symbol could not be found. SYM='" << parserMod.getSymb() << "'" << "\n";
                            outFile.close();
                            exit(1); 
                        }
                break;

            case C_INSTRUCTION:
                outFile << "111" << coderMod.compToBin( parserMod.getComp() )<< coderMod.destToBin( parserMod.getDest() ) << coderMod.jumpToBin( parserMod.getJump() ) << "\n";
                break;

            default:
                break;

        }
    }
    outFile.close();
}

