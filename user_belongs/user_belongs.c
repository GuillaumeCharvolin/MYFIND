#include <err.h>
#include <pwd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

int does_belongs(char *file, char *user)
{
    struct passwd *user_info = getpwnam(user);
    if (!user_info)
        err(2, "This user doesnt exist");

    struct stat info_file;
    if (stat(file, &info_file))
        err(2, "This file doesnt exist");

    if (user_info->pw_uid == info_file.st_uid)
        printf("%s does belong to user %s\n", file, user);
    else
        printf("%s does not belong to user %s\n", file, user);

    return 0;
}

int main(int argc, char *argv[])
{
    if (argc != 3)
        err(2, "Bad usage");

    return does_belongs(argv[1], argv[2]);
}
