
#include "main.hpp"


int main(int charc , char** charv)
{
    if(charc < 1)
    {
        std::cout << "Not enough arguments \n"; 
        exit(0);
    }
        
    std::string input = std::string(charv[1]);
    int dataTypeEndPoint = input.find_last_of('.');
    std::string fileName = input.substr(0, dataTypeEndPoint-1);
    fileName.append(".hack");

    if(std::filesystem::exists(fileName))
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

    std::ofstream hackFile(fileName);
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
    
    HackInToBin inputToBin;

    std::string test = "MAD";
    std::cout << inputToBin.destToBin(test) << "\n";

     test = "JGT";
    std::cout << inputToBin.jumpToBin(test) << "\n";

     test = "JEQ";
    std::cout << inputToBin.jumpToBin(test) << "\n";

     test = "JGE";
    std::cout << inputToBin.jumpToBin(test) << "\n";

     test = "JLT";
    std::cout << inputToBin.jumpToBin(test) << "\n";

     test = "JNE";
    std::cout << inputToBin.jumpToBin(test) << "\n";

     test = "JLE";
    std::cout << inputToBin.jumpToBin(test) << "\n";

     test = "JMP";
    std::cout << inputToBin.jumpToBin(test) << "\n";


     test = "0";
    std::cout << inputToBin.compToBin(test) << "\n";



}