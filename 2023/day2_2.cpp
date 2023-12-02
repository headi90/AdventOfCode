#include <algorithm>
#include <iterator>
#include <map>
#include <sstream>

#include "common.hpp"

constexpr auto MAX_RED = 12;
constexpr auto MAX_GREEN = 13;
constexpr auto MAX_BLUE = 14;

// print vector
template <typename T>
void printVector(const std::vector<T> &v)
{
  std::copy(v.begin(), v.end(), std::ostream_iterator<T>(std::cout, " "));
}

int func(const std::string line)
{
  std::cout << line << std::endl;

  const auto gamesBegin = line.find(':') + 2;
  const auto games = line.substr(gamesBegin, line.size() - gamesBegin);

  const auto gamesVec = split(games, ';');
  std::map<std::string, std::vector<int>> m;
  for (const auto &game : gamesVec)
  {
    const auto rounds = split(game, ',');
    for (const auto &round : rounds)
    {
      const auto cube = split(round, ' ', false);
      m[cube[1]].push_back(stringToInt(cube[0]));
    }
  }

  int maxRed = *std::max_element(m["red"].begin(), m["red"].end());
  int maxGreen = *std::max_element(m["green"].begin(), m["green"].end());
  int maxBlue = *std::max_element(m["blue"].begin(), m["blue"].end());

  return maxRed * maxGreen * maxBlue;
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

  int sum = 0;
  for (const auto &line : input)
  {
    const auto result = func(line);
    sum += result;
    std::cout << result << std::endl;
  }
  std::cout << '\n'
            << "Answer: "
            << sum << std::endl;

  return 0;
}
