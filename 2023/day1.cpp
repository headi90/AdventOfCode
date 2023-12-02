#include <algorithm>
#include <iterator>
#include <map>

#include "common.hpp"

std::string leaveFirstAndLastChar(const std::string &input)
{
    if (input.empty())
        return std::string();

    return std::string() + input.front() + input.back();
}

int getNumberFromString(const std::string &in)
{
    std::map<std::string, int> stringToNumber =
        {
            {"one", 1},
            {"two", 2},
            {"three", 3},
            {"four", 4},
            {"five", 5},
            {"six", 6},
            {"seven", 7},
            {"eight", 8},
            {"nine", 9}};

    std::string input = in;
    for (const auto &[key, value] : stringToNumber)
    {
        auto pos = 0;
        do
        {
            pos = input.find(key);
            if (pos != std::string::npos)
              input[pos + 1] = '0' + value;
        } while (pos != std::string::npos);
    }

    std::string digits;
    // std::cout << input << "    ";
    std::copy_if(input.begin(), input.end(), std::back_inserter(digits), ::isdigit);
    std::string number = leaveFirstAndLastChar(digits);

    return std::stoi(number);
}

int main()
{
  auto input = readFile("input/day1.txt");

  int sum{};
  for (const auto &line : input) {
    auto val = getNumberFromString(line);
    sum += val;
    // std::cout << line << "    " << val << std::endl;
    }

    std::cout << sum << std::endl;
    std::cout << input.size() << std::endl;

    return 0;
}
