#include <algorithm>
#include <iterator>
#include <map>
#include <sstream>
#include <iostream>

#include "../common.hpp"

using DestSourceRange = std::tuple<long, long, long>;
using DestSourceRanges = std::vector<DestSourceRange>;
using DestSourceRangesMap = std::map<int, DestSourceRanges>;

std::vector<long> getSeeds(std::string &input)
{
  std::vector<long> result;
  auto seeds = split(input, ' ', false);
  for (int i = 1; i < seeds.size(); ++i)
  {
    result.push_back(stringToNum<long>(seeds[i]));
  }

  return result;
}

DestSourceRange getDestSourceRange(std::string &input)
{
  DestSourceRange result;
  auto seeds = split(input, ' ', false);
  std::get<0>(result) = stringToNum<long>(seeds[0]);
  std::get<1>(result) = stringToNum<long>(seeds[1]);
  std::get<2>(result) = stringToNum<long>(seeds[2]);

  return result;
}

DestSourceRangesMap getDestSourceRangesMap(std::vector<std::string> &input)
{
  DestSourceRangesMap result;
  int no = -1;

  for (auto i = 1; i < input.size(); ++i)
  {
    if (input[i].empty())
    {
      continue;
    }
    if (*(input[i].end() - 1) == ':')
    {
      no++;
      continue;
    }

    result[no].push_back(getDestSourceRange(input[i]));
  }

  return result;
}

long mapSourceToDest(long input, DestSourceRanges &destSourceRanges)
{
  long result = input;
  for (auto &[dest, source, range] : destSourceRanges)
  {
    if (input >= source && input <= source + range)
    {
      result = dest + (input - source);
      break;
    }
  }

  return result;
}

long solve1(std::vector<std::string> &input)
{
  long result = 0;

  const auto seeds = getSeeds(input[0]);

  DestSourceRangesMap destSourceRangesMap = getDestSourceRangesMap(input);

  std::vector<long> res;
  for (const auto seed : seeds)
  {
    auto input = seed;
    for (auto &destSourceRanges : destSourceRangesMap)
    {
      input = mapSourceToDest(input, destSourceRanges.second);
    }
    res.push_back(input);

    std::cout << seed << " -> " << input << std::endl;
  }

  result = std::min_element(res.begin(), res.end())[0];

  return result;
}

int solve2(std::vector<std::string> &input)
{
    long result = 0;

  const auto seeds = getSeeds(input[0]);

  DestSourceRangesMap destSourceRangesMap = getDestSourceRangesMap(input);

  std::vector<long> newSeeds;
  for(auto i = 0; i < seeds.size(); i+=2) {
      auto start = seeds[i];
      auto range = seeds[i+1];
      for(auto j = 0; j < range; ++j) {
          newSeeds.push_back(start + j);
      }
  }

  std::vector<long> res;
  for (const auto seed : newSeeds)
  {
    auto input = seed;
    for (auto &destSourceRanges : destSourceRangesMap)
    {
      input = mapSourceToDest(input, destSourceRanges.second);
    }
    res.push_back(input);

    std::cout << seed << " -> " << input << std::endl;
  }

  result = std::min_element(res.begin(), res.end())[0];

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
