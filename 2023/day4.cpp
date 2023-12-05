#include <algorithm>
#include <iterator>
#include <map>
#include <sstream>

#include "../common.hpp"

std::vector<int> gerNumbers(const std::string &s)
{
  std::vector<int> numbers;

  std::string number = "";
  for(auto c : s) {
    if(isdigit(c)) {
      number += c;
    } else {
      if(!number.empty()) {
        numbers.push_back(stringToInt(number));
        number = "";
      }
    }
  }
  return numbers;
}

int solve1(std::vector<std::string> &input)
{
  int result = 0;

  for (auto &line : input)
  {
    std::map<int, int> winingMap{};
    winingMap.clear();
    auto numbers = split(line, ':')[1];
    auto winingMyNumers = split(numbers, '|');
    std::cout << "wining: " << winingMyNumers[0] << '|' << std::endl;
    std::cout << "my: " << winingMyNumers[1] << '|' << std::endl;
    auto wining = gerNumbers(winingMyNumers[0]);
    auto my = gerNumbers(winingMyNumers[1]);

      std::cout << "wining: ";
      for(auto &num : wining) {
        std::cout << num << " ";
      }
      std::cout << '|' << std::endl;
      std::cout << "my: ";
      for(auto &num : my) {
        std::cout << num << " ";
      }
      std::cout << std::endl;
    

    for (auto &num : wining)
    {
      winingMap[num] = 0;
    }

    for (auto &num : my)
    {
      winingMap[num]++;
    }

    for(auto [key, value] : winingMap) {
      std::cout << key << " " << value << std::endl;
    }
    std::cout << std::endl;
  }

  return result;
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

  auto answer1 = solve1(input);

  auto answer2 = 0;

  std::cout << '\n'
            << "Answer 1: "
            << answer1 << "\nAnswer 2: " << answer2 << std::endl;

  return 0;
}
