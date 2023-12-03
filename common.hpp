#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

std::vector<std::string> readFile(const std::string &filePath);
std::vector<std::vector<char>> readFileToCharVector(const std::string &filePath);
std::vector<std::string> split(const std::string &s, char seperator, bool skipSpace = true);
int stringToInt(const std::string &s);

template <typename T>
void printVector(const std::vector<T> &v)
{
    std::copy(v.begin(), v.end(), std::ostream_iterator<T>(std::cout, " "));
}
