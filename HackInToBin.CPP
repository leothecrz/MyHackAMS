
#include "HackInToBin.hpp"

std::string HackInToBin::destToBin(std::string& str)
{
    std::string out = "000";

    for(char c: string)
    {
        if(c == 'M')
            out[2] = 1;
        if(c == 'D')
            out[1] = 1;
        if(c == 'A')
            out[0] = 1;
    }

    return out;
}

std::string HackInToBin::compToBin(std::string& str)
{

}

std::string HackInToBin::jumpToBin(std::string& str)
{

}