#include <err.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int sub_exec(char *argv[])
{
    pid_t pid = fork();
    if (pid == -1)
        return 1;
    else if (!pid)
    {
        int error = execvp(argv[1], &argv[1]);
        if (error == -1)
            err(error, "%s: command not found", argv[1]);
    }
    int error = 0;
    waitpid(pid, &error, 0);
    return error;
}

int main(int argc, char *argv[])
{
    if (argc == 1)
        err(1, "Bad usage");
    if (sub_exec(argv))
        return 1;
    return 0;
}
