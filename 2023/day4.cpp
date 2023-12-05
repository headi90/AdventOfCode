#include <algorithm>
#include <iterator>
#include <map>
#include <sstream>

#include "../common.hpp"

int main(int argc, char **argv)
{
  if (argc != 2)
  {
    std::cerr << "Usage: " << argv[0] << " <input file>" << std::endl;
    return 1;
  }
  std::string input_file(argv[1]);

  auto input = readFile(input_file);

  auto result = 0;
  for (const auto &line : input)
  {
    std::cout << line << std::endl;
  }

  std::cout << '\n'
            << "Answer: "
            << result << std::endl;

  return 0;
}
