
#include "HackInToBin.hpp"

HackInToBin::HackInToBin()
{
    COMPCODES.insert({"0", "0101010"});
    COMPCODES.insert({"1", "0111111"});
    COMPCODES.insert({"-1","0111010"});
    COMPCODES.insert({"D","0001100"});
    COMPCODES.insert({"A", "0110000"});
    COMPCODES.insert({"!D", "0001101"});
    COMPCODES.insert({"!A", "0110001"});
    COMPCODES.insert({"-D", "0001111"});
    COMPCODES.insert({"-A", "0110011"});
    
    COMPCODES.insert({"D+1", "0011111"});
    COMPCODES.insert({"A+1", "0110111"});
    COMPCODES.insert({"D-1", "0001110"});
    COMPCODES.insert({"A-1", "0110010"});
    COMPCODES.insert({"D+A", "0000010"});
    COMPCODES.insert({"D-A", "0010011"});
    COMPCODES.insert({"A-D","0000111"});
    COMPCODES.insert({"D&A", "0000000"});
    COMPCODES.insert({"D|A", "0010101"});

    COMPCODES.insert({"M", "1110000"});
    COMPCODES.insert({"!M", "1110001"});
    COMPCODES.insert({"-M", "1110011"});
    COMPCODES.insert({"M+1", "1110111"});
    COMPCODES.insert({"M-1", "1110010"});
    COMPCODES.insert({"D+M", "1000010"});
    COMPCODES.insert({"D-M", "1010011"});
    COMPCODES.insert({"M-D", "1000111"});
    COMPCODES.insert({"D&M", "1000000"});
    COMPCODES.insert({"D|M", "1010101"});
}

std::string HackInToBin::compToBin(std::string& str)
{
    std::map<std::string,std::string>::iterator it;
    it = COMPCODES.find(str);
    if( it != COMPCODES.end() )
        return COMPCODES[str]; 
    std::cout << "ERROR in comp section of line" << std::endl; 
    exit(1);
}

std::string HackInToBin::destToBin(std::string& str)
{

    std::string out = "000";

    for(char c: str)
    {
        if(c == 'M')
            out[2] = '1';
        if(c == 'D')
            out[1] = '1';
        if(c == 'A')
            out[0] = '1';
    }

    return out;
}

std::string HackInToBin::jumpToBin(std::string& str)
{
    std::string out = "000";
    if(str.length() == 3)
        for(int i=1; i<3; i++)
        {
            switch (str[i])
            {
                case 'M':
                    return "111";

                case 'N':
                    return "101";
                    
                case 'G':
                    out[2] = '1';
                    break;
                case 'E':
                    out[1] = '1';
                    break;
                case 'L':
                    out[0] = '1';
                    break;
                default:
                    break;
            }
        }
    return out;
}