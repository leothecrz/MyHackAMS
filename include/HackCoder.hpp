#pragma once

#include <map>
#include <iostream>
#include <string>

class HackCoder
{
    private:
        std::map<std::string, std::string> COMPCODES;

    public:
        HackCoder();
        ~HackCoder();

        std::string destToBin(const std::string&);
        std::string compToBin(const std::string&);
        std::string jumpToBin(const std::string&);
};