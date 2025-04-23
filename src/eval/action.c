#include "action.h"

int _print(char *full_name, char *is_printed)
{
    printf("%s\n", full_name);
    *is_printed = 1;
    return 0;
}
