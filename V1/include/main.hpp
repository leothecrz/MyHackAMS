#pragma once

#include "HackParser.hpp"
#include "HackInToBin.hpp"
#include "HackSymbolTable.hpp"

#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include <bitset>

std::string fileExistEnd(const std::string& input);

std::string numToBin(const std::string& str);

bool is_number(const std::string& s);