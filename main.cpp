
#include "main.hpp"


int main(int charc , char** charv)
{
    if(charc < 1)
    {
        std::cout << "Not enough arguments \n"; 
        exit(0);
    }
        
    std::string input = std::string(charv[1]);
    HackParser parser(input);

    while(parser.hasMore())
    {
        parser.Next();
        std::cout << parser.type <<"\n"<< parser.symbol <<"\n"<< parser.dest <<"\n"<< parser.comp << "\n" << parser.jump << "\n";

        switch (parser.type)
        {
        case A_INS:
            
            break;
        case C_INS:

            break;
        case L_INS: // WIP
            break;
        default:
            std::cout << "ERROR STATE" << std::endl;
            exit(1);
        };

        
    }
    
}