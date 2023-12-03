#include <algorithm>
#include <iterator>
#include <map>
#include <sstream>

#include "../common.hpp"

// rock paper scissors game
// A for Rock
// B for Paper
// C for Scissors
// X means you need to lose
// Y means you need to draw
// Z means you need to win

int func(std::vector<std::string> lines)
{
  int sum = 0;
  for (const auto &l : lines)
  {
    std::cout << l << " -> ";
    const auto game = split(l, ' ', false);
    printVector(game);

    const auto p1 = game[0];
    const auto p3 = game[1];
    std::string p2{};

    if (p3 == "Y")
    {
      p2 = p1;
    }
    else if (p3 == "X")
    {
      if (p1 == "A")
      {
        p2 = "C";
      }
      else if (p1 == "B")
      {
        p2 = "A";
      }
      else if (p1 == "C")
      {
        p2 = "B";
      }
    }
    else if (p3 == "Z")
    {
      if (p1 == "A")
      {
        p2 = "B";
      }
      else if (p1 == "B")
      {
        p2 = "C";
      }
      else if (p1 == "C")
      {
        p2 = "A";
      }
    }

    std::cout << " -> " << p1 << " " << p2;

    int score = 0;
    if ((p1 == "A" && p2 == "B") || (p1 == "B" && p2 == "C") || (p1 == "C" && p2 == "A"))
    {
      score = 6;
    }
    if ((p1 == "A" && p2 == "A") || (p1 == "B" && p2 == "B") || (p1 == "C" && p2 == "C"))
    {
      score = 3;
    }

    if (p2 == "A")
    {
      score += 1;
    }
    if (p2 == "B")
    {
      score += 2;
    }
    if (p2 == "C")
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
