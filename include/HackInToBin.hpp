#pragma once

#include <string>
#include <iostream>
#include <map>
#include "InsEnum.hpp"



class HackInToBin
{
    public:
        HackInToBin();

        std::map<std::string, std::string> COMPCODES;
        std::string destToBin(std::string&);
        std::string compToBin(std::string&);
        std::string jumpToBin(std::string&);

};