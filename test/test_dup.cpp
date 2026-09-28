#include <iostream>
#include <fcntl.h>
#include <unistd.h>

int main() {
  int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

  if (fd == -1) {
    perror("open");
    return 1;
  }

  dup2(fd, STDOUT_FILENO);

  close(fd);

  std::cout << "Hello from stdout\n";

  return 0;
}
