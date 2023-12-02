#include "common.hpp"

std::vector<std::string> readFile(const std::string &filePath) {
  std::vector<std::string> lines;
  std::ifstream file(filePath);
  std::string line;

  if (file.is_open()) {
    while (std::getline(file, line)) {
      lines.push_back(line);
    }
    file.close();
  }

  return lines;
}
