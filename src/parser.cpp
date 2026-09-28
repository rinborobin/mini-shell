#include "../include/parser.hpp"
#include <sstream>

Command Parser::parse(const std::string &input) {
  std::stringstream ss(input);

  Command command;

  std::string word;

  while (ss >> word) {
    if (word == ">") {
      ss >> command.outputFile;
    } else {
      command.args.push_back(word);
    }
  }
  return command;
}
