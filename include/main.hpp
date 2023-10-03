#pragma once

#include "HackParser.hpp"
#include "HackInToBin.hpp"

#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include <bitset>

std::string fileExistEnd(const std::string& input);

std::string numToBin(const std::string& str);