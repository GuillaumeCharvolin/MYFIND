#ifndef TEST_H
#define TEST_H

#include <fnmatch.h>
#include <stdio.h>
#include <sys/stat.h>

#include "../lexer/token.h"

int _name(char *name, token *token);
int _type(char *full_name, char type);
int _newer(char *to_test, char *full_path);

#endif /* !ACTION_H */
