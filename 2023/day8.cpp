#include <algorithm>
#include <iterator>
#include <map>
#include <sstream>
#include <iostream>
#include <vector>

#include "../common.hpp"

using StepGuides = std::map<std::string, std::pair<std::string, std::string>>;

long solve1(std::vector<std::string> &input)
{
  long result = 0;

  const auto moves = input[0];

  std::cout << moves << std::endl;

  StepGuides stepGuides;

  for (auto i = 2; i < input.size(); ++i)
  {
    auto current = input[i].substr(0, 3);

    auto nextLeft = input[i].substr(7, 3);
    auto nextRight = input[i].substr(12, 3);

    stepGuides[current] = std::make_pair(nextLeft, nextRight);
  }

  const auto movesSize = moves.size();
  int idx = 0;
  std::string current = "AAA";
  while (true)
  {
    auto currentMove = moves[idx % movesSize];
    auto next = stepGuides[current];

    current = currentMove == 'L' ? next.first : next.second;

    idx++;
    result++;

    if (current == "ZZZ")
    {
      break;
    }
  }
  return result;
}

// function calculating LCM from vectror of numbers
#include <numeric>

long lcm(std::vector<int> &v)
{
  long result = v[0];
  for (int i = 1; i < v.size(); i++)
  {
    result = (result * v[i]) / std::gcd(result, v[i]);
  }
  return result;
}

long solve2(std::vector<std::string> &input)
{
  long result = 0;

  const auto moves = input[0];

  StepGuides stepGuides;

  for (auto i = 2; i < input.size(); ++i)
  {
    auto current = input[i].substr(0, 3);

    auto nextLeft = input[i].substr(7, 3);
    auto nextRight = input[i].substr(12, 3);

    stepGuides[current] = std::make_pair(nextLeft, nextRight);
  }

  std::vector<std::string> startingPoints;
  for (const auto &[key, value] : stepGuides)
  {
    if (key[2] == 'A')
    {
      startingPoints.push_back(key);
    }
  }

  for (const auto &el : startingPoints)
  {
    std::cout << el << std::endl;
  }

  std::vector<int> steps;
  const auto movesSize = moves.size();
  int idx = 0;

  for (auto el : startingPoints)
  {
    auto current = el;
    auto r = 0;
    while (true)
    {
      auto currentMove = moves[idx % movesSize];
      auto next = stepGuides[current];

      current = currentMove == 'L' ? next.first : next.second;

      idx++;
      r++;

      if (current[2] == 'Z')
      {
        steps.push_back(r);
        break;
      }
    }
  }

  for (auto el : steps)
  {
    std::cout << el << std::endl;
  }
  result = lcm(steps);
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

  auto answer2 = solve2(input);

  std::cout << '\n'
            << "Answer 1: "
            << answer1 << "\nAnswer 2: " << answer2 << std::endl;

  return 0;
}
