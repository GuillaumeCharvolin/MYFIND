#include "test.h"

int _name(char *name, token *token)
{
    return fnmatch(token->data, name, FNM_NOESCAPE);
}

int _type(char *full_name, char type)
{
    struct stat info_file;
    stat(full_name, &info_file);

    if (type == 'd' && S_ISBLK(info_file.st_mode))
        return 0;
    else if (type == 'c' && S_ISCHR(info_file.st_mode))
        return 0;
    else if (type == 'd' && S_ISDIR(info_file.st_mode))
        return 0;
    else if (type == 'f' && S_ISREG(info_file.st_mode))
        return 0;
    else if (type == 'l' && S_ISLNK(info_file.st_mode))
        return 0;
    else if (type == 'p' && S_ISFIFO(info_file.st_mode))
        return 0;
    return 1;
}

int _newer(char *to_test, char *full_path)
{
    struct stat info_file1;
    stat(full_path, &info_file1);

    struct stat info_file2;
    stat(to_test, &info_file2);

    return info_file1.st_mtime <= info_file2.st_mtime;
}
