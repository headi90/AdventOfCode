#include "common.hpp"
#include <sstream>

std::vector<std::string> readFile(const std::string &filePath)
{
  std::vector<std::string> lines;
  std::ifstream file(filePath);
  std::string line;

  if (file.is_open())
  {
    while (std::getline(file, line))
    {
      lines.push_back(line);
    }
    file.close();
  }

  return lines;
}

std::vector<std::string> split(const std::string &s, char seperator, bool skipSpace)
{
  std::vector<std::string> output;

  std::string::size_type prev_pos = 0, pos = 0;

  while ((pos = s.find(seperator, pos)) != std::string::npos)
  {
    std::string substring(s.substr(prev_pos, pos - prev_pos));

    output.push_back(substring);

    if (skipSpace)
    {
      pos += 2;
    }
    else
    {
      ++pos;
    }
    prev_pos = pos;
  }

  output.push_back(s.substr(prev_pos, pos - prev_pos)); // Last word

  return output;
}

int stringToInt(const std::string &s)
{
  std::stringstream ss(s);
  int result;
  ss >> result;
  return result;
}
