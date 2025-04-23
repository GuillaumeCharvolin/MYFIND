#include <err.h>
#include <stdio.h>
#include <sys/stat.h>

int print_stat(struct stat *info)
{
    printf("st_dev=%ld\n", info->st_dev);
    printf("st_ino=%ld\n", info->st_ino);
    printf("st_mode=0%o\n", info->st_mode);
    printf("st_nlink=%ld\n", info->st_nlink);
    printf("st_uid=%d\n", info->st_uid);
    printf("st_gid=%d\n", info->st_gid);
    printf("st_rdev=%ld\n", info->st_rdev);
    printf("st_size=%ld\n", info->st_size);
    printf("st_atime=%ld\n", info->st_atime);
    printf("st_mtime=%ld\n", info->st_mtime);
    printf("st_ctime=%ld\n", info->st_ctime);
    printf("st_blksize=%ld\n", info->st_blksize);
    printf("st_blocks=%ld\n", info->st_blocks);
    return 0;
}

int simple_stat(char *path)
{
    struct stat info_file;

    if (stat(path, &info_file))
        return 1;

    if (print_stat(&info_file))
        return 1;
    return 0;
}

int main(int argc, char *argv[])
{
    for (int i = 1; i < argc; i++)
    {
        if (simple_stat(argv[i]))
            err(1, "Simple stat: Error");
    }

    return 0;
}
