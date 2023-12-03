#include <algorithm>
#include <iterator>
#include <map>
#include <sstream>

#include "../common.hpp"

bool isInRange(int val, int min, int max)
{
  return val >= min && val <= max;
}

bool checkAdjacent(const std::vector<std::vector<char>> &chars, const int idxI, const int idxJ, const std::string &num)
{
  const int maxI = idxI + 1;
  const int minI = idxI - 1;
  const int maxJ = idxJ + num.size();
  const int minJ = idxJ - 1;

  for (int i = minI; i <= maxI; ++i)
  {
    for (int j = minJ; j <= maxJ; ++j)
    {
      // check table bounds
      if (i < 0 || j < 0 || i >= chars.size() || j >= chars[i].size())
      {
        continue;
      }
      // not include num
      if ((i == idxI) && isInRange(j, idxJ, idxJ + num.size() - 1))
      {
        continue;
      }

      char c = chars[i][j];
      if (c != '.')
      {
        return true;
      }
    }
  }
  return false;
}

long long func(std::vector<std::vector<char>> &chars)
{
  long long sum = 0;

  for (auto &row : chars)
  {
    row.push_back('.');
  }

  const auto ROWS = chars.size();
  const auto COLS = chars[0].size();

  for (auto i = 0; i < ROWS; ++i)
  {
    std::string num = "";
    for (auto j = 0; j < COLS; ++j)
    {
      char c = chars[i][j];
      if (std::isdigit(c))
      {
        num += c;
      }

      if (!num.empty() && !std::isdigit(c))
      {
        int idxI = i;
        int idxJ = j - num.size();
        if (checkAdjacent(chars, idxI, idxJ, num))
        {
          sum += stringToInt(num);
        }
        num = "";
      }
    }
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

  auto input = readFileToCharVector(input_file);

  const long long result = func(input);

  std::cout << '\n'
            << "Answer: "
            << result << std::endl;

  return 0;
}
