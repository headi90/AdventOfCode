#include <algorithm>
#include <iterator>
#include <map>
#include <sstream>

#include "../common.hpp"

std::vector<int> getNumbers(const std::string &s)
{
  std::vector<int> numbers{};

  std::string number = "";
  for (const auto c : s)
  {
    if (isdigit(c))
    {
      number += c;
    }
    else
    {
      if (!number.empty())
      {
        numbers.push_back(stringToInt(number));
        number = "";
      }
    }
  }
  if (!number.empty())
  {
    numbers.push_back(stringToInt(number));
    number = "";
  }

  return numbers;
}

int getPointsFromCard(const std::string &card)
{
  std::map<int, int> winingMap{};
  winingMap.clear();
  auto numbers = split(card, ':')[1];
  auto winingMyNumers = split(numbers, '|');
  auto wining = getNumbers(winingMyNumers[0]);
  auto my = getNumbers(winingMyNumers[1]);

  for (const auto &num : wining)
    winingMap[num] = 1;

  for (const auto &num : my)
    winingMap[num]++;

  int points = 0;
  for (auto [key, value] : winingMap)
  {
    if (value > 1)
      points++;
  }

  return points;
}

int solve1(std::vector<std::string> &input)
{
  int result = 0;

  for (auto &line : input)
  {
    int points = getPointsFromCard(line);

    if (points > 0)
      result += (1 << points - 1);
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
