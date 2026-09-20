#include <csignal>

#include "../include/shell.hpp"

#define prompt "msh$ "

bool running = true;

bool is_ctrl_c(int signal)
{
    return signal == SIGINT;
}

void handle_signal(int signal)
{
    if (signal == SIGINT)
    {
        running = false;
    }
}

int main()
{
}
