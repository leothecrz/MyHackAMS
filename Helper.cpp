
#include "Helper.hpp"

bool is_number(const std::string& str)
{
    std::string::const_iterator charIT = str.begin();
    while ( charIT != str.end() && 
        std::isdigit(*charIT)) // escape on nondigit
        ++charIT;
    
    return !str.empty() && charIT == str.end(); // fails with early end
}

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

std::string numToBin(const std::string& str)
{
    int value = std::stoi(str);
    return std::bitset<15>(value).to_string(); 
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

