
#include "main.hpp"

std::string numToBin(const std::string& str)
{
    int value = std::stoi(str);
    return std::bitset<15>(value).to_string(); 
}

std::string fileExistEnd(std::string& input)
{
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
    return fileName;
}

int main(int charc , char** charv)
{
    if(charc < 2)
    {
        std::cout << "Not enough arguments \n"; 
        exit(0);
    }
        
    std::string input = std::string(charv[1]);

    std::string fileName = fileExistEnd(input);
    
    std::ofstream hackFile(fileName);
    HackParser parser(input);
    
    HackInToBin inputToBin;

    while(parser.hasMore())
    {
        std::string write = "";
        parser.Next();
        std::cout << parser.type <<"\n"<< parser.symbol <<"\n"<< parser.dest <<"\n"<< parser.comp << "\n" << parser.jump << "\n";

        switch (parser.type)
        {
        case A_INS:
            write.append("0");
            write.append(numToBin(parser.symbol));
            hackFile << write << "\n";
            break;

        case C_INS:
            write.append("111");
            write.append(inputToBin.compToBin(parser.comp));
            write.append(inputToBin.destToBin(parser.dest));
            write.append(inputToBin.jumpToBin(parser.jump));
            hackFile << write << "\n";
            break;
        case L_INS: // IGNORE
            break;
        default: // SHOULD ALWAYS HAVE STATE
            std::cout << "ERROR STATE" << std::endl;
            exit(1);
        };

        
    }
    hackFile.close();
    
}