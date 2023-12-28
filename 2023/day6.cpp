#include <algorithm>
#include <iterator>
#include <map>
#include <sstream>
#include <iostream>

#include "../common.hpp"

std::vector<long> getNumbersFromString(const std::string &s)
{
  std::vector<long> numbers;

  std::string number = "";
  for (auto c : s)
  {
    if (isdigit(c))
    {
      number += c;
    }
    else
    {
      if (number != "")
      {
        numbers.push_back(stringToNum<long>(number));
        number = "";
      }
    }
  }
  numbers.push_back(stringToNum<long>(number));

  return numbers;
}

long getNumberFromString(const std::string &s)
{
  long n;

  std::string number = "";
  for (auto c : s)
  {
    if (isdigit(c))
    {
      number += c;
    }
  }
  n = stringToNum<long>(number);

  return n;
}

long solve1(std::vector<std::string> &input)
{
  long result = 1;

  auto t = split(input[0], ':', false)[1];
  auto d = split(input[1], ':', false)[1];

  auto times = getNumbersFromString(t);
  auto distances = getNumbersFromString(d);

  for (int i = 0; i < times.size(); i++)
  {
    // std::cout << "t: " << times[i] << " d: " << distances[i] << std::endl;
    // std::cout << "positions: ";

    std::vector<int> positions;
    for (int j = 0; j <= times[i]; j++)
    {
      auto time = times[i] - j;
      auto speed = j;
      auto distance = time * speed;

      positions.push_back(distance);
      // std::cout << distance << " ";
    }
    // std::cout << std::endl;

    size_t index = 0;
    for(; index < positions.size(); index++) {
      if(positions[index] > distances[i])
      {
        break;
      }
    }
    auto res = positions.size()/2 - index;
    auto r = positions.size() % 2 == 0 ? res *2 : res*2 + 1;
    // std::cout << "index: " << index << std::endl;
    // std::cout << "res: " << res << std::endl;
    // std::cout << "r: " << r << " size: " << positions.size() << std::endl;

    result *= r;
  }

  return result;
}

int solve2(std::vector<std::string> &input)
{
  long result = 1;

  auto t = split(input[0], ':', false)[1];
  auto d = split(input[1], ':', false)[1];

  auto time = getNumberFromString(t);
  auto distance = getNumberFromString(d);

  std::cout << "time: " << time << " distance: " << distance << std::endl;

  std::vector<long> positions;
    for (int j = 0; j <= time; j++)
    {
      auto t = time - j;
      auto speed = j;
      auto distance = t * speed;

      positions.push_back(distance);
      // std::cout << distance << " ";
    }
    // std::cout << std::endl;

    size_t index = 0;
    for(; index < positions.size(); index++) {
      if(positions[index] > distance)
      {
        break;
      }
    }
    auto res = positions.size()/2 - index;
    auto r = positions.size() % 2 == 0 ? res *2 : res*2 + 1;
    // std::cout << "index: " << index << std::endl;
    // std::cout << "res: " << res << std::endl;
    // std::cout << "r: " << r << " size: " << positions.size() << std::endl;

    result = r;

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
