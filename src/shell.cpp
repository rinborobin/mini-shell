#include "../include/shell.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <ranges>

#include <unistd.h>
#include <sys/wait.h>

void Shell::run()
{
    while (running)
    {
        std::string user_input;

        std::cout << prompt;
        std::getline(std::cin, user_input);

        std::stringstream ss(user_input);

        std::vector<std::string> args;

        std::string word;

        while (ss >> word)
        {
            args.push_back(word);
        }

        if (args.empty())
            continue;

        pid_t pid = fork();

        if (pid < 0)
        {
            std::cerr << "Fork failed\n";
            return 1;
        }
        else if (pid == 0)
        {
            std::vector<char *> argv;

            for (std::string &arg : args)
            {
                argv.push_back(arg.data());
            }

            argv.push_back(nullptr);

            execvp(argv[0], argv.data());

            perror("execvp");
            return 1;
        }
        else
        {
            waitpid(pid, nullptr, 0);

            std::cout << "Child finished\n";
        }
    }
}