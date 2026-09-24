#include "../include/parser.hpp"
#include <sstream>

std::vector<std::string> Parser::parse(const std::string &input) {
  std::stringstream ss(input);

  std::vector<std::string> args;

  std::string word;

  while (ss >> word) {
    args.push_back(word);
  }
  return args;
}
