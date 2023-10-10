
#include "main.hpp"

int main(int charc, char** charv)
{
    argumentSizeCheck(charc);
    std::string outFileName = extractFileName( charv[1] ).append( ".hack" );

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
                        outFile << "0" << numToBin( parserMod.getSymbolValue(parserMod.getSymb()) ) << "\n";
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

