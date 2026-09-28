#include "../include/executer.hpp"

#include <cstdio>
#include <fcntl.h>
#include <iostream>
#include <sys/wait.h>
#include <unistd.h>
#include <vector>

void Executor::execute(const Command &command) {
  if (command.args.empty()) {
    return;
  }

  pid_t pid = fork();

  if (pid < 0) {
    perror("fork");
    return;
  }
  if (pid == 0) {
    std::vector<char *> argv;

    for (const auto &arg : command.args) {
      argv.push_back(const_cast<char *>(arg.c_str()));
    }

    argv.push_back(nullptr);
    if (!command.outputFile.empty()) {
      int fd =
          open(command.outputFile.c_str(), O_WRONLY | O_CREAT | O_TRUNC, 0644);

      if (fd == -1) {
        perror("open");
        _exit(1);
      }

      if (dup2(fd, STDOUT_FILENO) == -1) {
        perror("dup2");
        _exit(1);
      }

      close(fd);
    }

    execvp(argv[0], argv.data());

    perror("execvp");
    _exit(1);
  }

  waitpid(pid, nullptr, 0);
}
