#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> readFile(const std::string &filePath);
std::vector<std::string> split(const std::string &s, char seperator, bool skipSpace = true);
int stringToInt(const std::string &s);