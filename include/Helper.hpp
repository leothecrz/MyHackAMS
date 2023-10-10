
#pragma once

#include <string>
#include <filesystem>
#include <iostream>
#include <bitset>

void argumentSizeCheck(int inputs);

void fileExistCheck(const std::string& str);

std::string extractFileName(const char* str);

bool is_number(const std::string& str);

std::string numToBin(const std::string& str);
