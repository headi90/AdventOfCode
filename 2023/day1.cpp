#include <algorithm>
#include <iterator>
#include <map>

#include "../common.hpp"

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
        std::size_t pos = 0;
        do
        {
            pos = input.find(key);
            if (pos != std::string::npos)
              input[pos + 1] = '0' + char(value);
        } while (pos != std::string::npos);
    }

    std::string digits;
    // std::cout << input << "    ";
    std::copy_if(input.begin(), input.end(), std::back_inserter(digits), ::isdigit);
    std::string number = leaveFirstAndLastChar(digits);

    return std::stoi(number);
}

int main(int argc, char **argv)
{
  if (argc != 2)
  {
    std::cerr << "Usage: " << argv[0] << " <input file>" << std::endl;
    return 1;
  }
  std::string input_file(argv[1]);

  auto input = readFile(input_file);

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
