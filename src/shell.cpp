#include "../include/shell.hpp"
#include "../include/executer.hpp"
#include "../include/parser.hpp"
#include <csignal>

#include <iostream>
#include <string>

#include <sys/wait.h>
#include <unistd.h>

#define prompt "msh$ "

bool running = true;

bool is_ctrl_c(int signal) { return signal == SIGINT; }

void handle_signal(int signal) {
  if (signal == SIGINT) {
    running = false;
  }
}

void Shell::run() {

  Parser parser;
  Executor executor;

  while (running) {
    std::string user_input;

    std::cout << prompt;
    if (!std::getline(std::cin, user_input)) {
      break;
    }
    Command command = parser.parse(user_input);

    if (!command.args.empty()) {
      executor.execute(command);
    }
  }
}
