#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>

int my_err(int code, char *msg)
{
    fprintf(stderr, "%s\n", msg);
    return code;
}

int main(int argc, char *argv[])
{
    if (argc > 2)
        return my_err(1, "Simple ls: Bad Usage");

    DIR *dir = opendir(argv[1] ? argv[1] : ".");
    if (!dir)
        return my_err(1, "Simple ls: No such file or directory");

    struct dirent *entry = readdir(dir);
    for (; entry; entry = readdir(dir))
    {
        if (!strcmp(entry->d_name, ".") || !strcmp(entry->d_name, ".."))
            continue;
        printf("%s\n", entry->d_name);
    }

    closedir(dir);
    return 0;
}
