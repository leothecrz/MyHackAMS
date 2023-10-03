#pragma once

#include <string>

#include "InsEnum.hpp"


class HackInToBin
{
    public:
        HackInToBin();
        std::string destToBin(std::string&);
        std::string compToBin(std::string&);
        std::string jumpToBin(std::string&);

};