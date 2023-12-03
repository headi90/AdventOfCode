#include <algorithm>
#include <iterator>
#include <map>
#include <sstream>

#include "../common.hpp"

// rock paper scissors game
// A for Rock
// B for Paper
// C for Scissors
// X for Rock
// Y for Paper
// Z for Scissors

// A beats Z
// B beats X
// C beats Y

int func(std::vector<std::string> lines)
{
  int sum = 0;
  for (const auto &l : lines)
  {
    std::cout << l << " -> ";
    const auto game = split(l, ' ', false);
    printVector(game);

    const auto p1 = game[0];
    const auto p2 = game[1];

    int score = 0;
    if ((p1 == "A" && p2 == "Y") || (p1 == "B" && p2 == "Z") || (p1 == "C" && p2 == "X"))
    {
      score = 6;
    }
    if ((p1 == "A" && p2 == "X") || (p1 == "B" && p2 == "Y") || (p1 == "C" && p2 == "Z"))
    {
      score = 3;
    }

    if (p2 == "X")
    {
      score += 1;
    }
    if (p2 == "Y")
    {
      score += 2;
    }
    if (p2 == "Z")
    {
      score += 3;
    }

    sum += score;

    std::cout << " -> " << score << std::endl;
  }

  return sum;
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

  const auto result = func(input);

  std::cout << '\n'
            << "Answer: "
            << result << std::endl;

  return 0;
}
