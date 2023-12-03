#include <algorithm>
#include <iterator>
#include <map>
#include <sstream>

#include "../common.hpp"

int func(const std::string line)
{

  return 0;
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

  int answer = 0;
  for (const auto &line : input)
  {
    const auto result = func(line);
  }

  std::cout << '\n'
            << "Answer: "
            << answer << std::endl;

  return 0;
}
