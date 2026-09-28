#pragma once

#include <string>
#include <vector>

struct Command {
  std::vector<std::string> args;
  std::string outputFile;
};

class Parser {
public:
  Command parse(const std::string &input);
};
