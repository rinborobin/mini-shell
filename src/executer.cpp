#include "../include/executer.hpp"

#include <cstdio>
#include <sys/wait.h>
#include <unistd.h>
#include <vector>

void Executor::execute(const std::vector<std::string> &args) {
  if (args.empty()) {
    return;
  }

  pid_t pid = fork();

  if (pid < 0) {
    perror("fork");
    return;
  }
  if (pid == 0) {
    std::vector<char *> argv;

    for (const auto &arg : args) {
      argv.push_back(const_cast<char *>(arg.c_str()));
    }

    argv.push_back(nullptr);

    execvp(argv[0], argv.data());

    perror("execvp");
    _exit(1);
  }

  waitpid(pid, nullptr, 0);
}
