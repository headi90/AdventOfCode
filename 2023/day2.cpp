#include <algorithm>
#include <iterator>
#include <map>
#include <sstream>

#include "../common.hpp"

constexpr auto MAX_RED = 12;
constexpr auto MAX_GREEN = 13;
constexpr auto MAX_BLUE = 14;

int func(const std::string line)
{
  std::cout << line << std::endl;
  const std::string gameNo = split(split(line, ':')[0], ' ', false)[1];
  int gameNoInt = stringToInt(gameNo);

  const auto gamesBegin = line.find(':') + 2;
  const auto games = line.substr(gamesBegin, line.size() - gamesBegin);

  const auto gamesVec = split(games, ';');
  for (const auto &game : gamesVec)
  {
    const auto rounds = split(game, ',');
    std::map<std::string, int> m;
    for (const auto &round : rounds)
    {
      // std::cout << round << std::endl;
      const auto cube = split(round, ' ', false);
      // std::cout << cube[0] << " " << cube[1] << std::endl;
      m[cube[1]] = stringToInt(cube[0]);
    }
    if (m["red"] > MAX_RED || m["green"] > MAX_GREEN || m["blue"] > MAX_BLUE)
    {
      return 0;
    }
  }

  return gameNoInt;
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
            << sum << std::endl;

  return 0;
}
