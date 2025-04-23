#ifndef EVAL_H
#define EVAL_H

#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include "../parser/ast.h"
#include "action.h"
#include "test.h"

int eval(char *path, ast *root);

#endif /* !EVAL_H */
