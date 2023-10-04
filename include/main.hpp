#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <bitset>

#include "HackCoder.hpp"
#include "HackParser.hpp"

std::string extractFileName(const char* str);

void fileExistCheck(const std::string& str);

bool is_number(const std::string& str);

std::string numToBin(const std::string& str);
