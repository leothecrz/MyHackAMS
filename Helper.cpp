
#include "Helper.hpp"

bool is_number(const std::string& str)
{
    std::string::const_iterator charIT = str.begin();
    while ( charIT != str.end() && 
        std::isdigit(*charIT)) // escape on nondigit
        ++charIT;
    
    return !str.empty() && charIT == str.end(); // fails with early end
}