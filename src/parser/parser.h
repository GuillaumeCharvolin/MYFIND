#ifndef PARSER_H
#define PARSER_H

#include "../lexer/list.h"
#include "ast.h"
#include "stack.h"

int parser(ast *root, list *args);

#endif /* !PARSER_H */
