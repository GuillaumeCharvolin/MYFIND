#ifndef AST_H
#define AST_H

#include <string.h>

#include "../lexer/list.h"
#include "../lexer/token.h"

typedef struct ast
{
    struct ast *right;
    struct ast *left;
    token *token;
} ast;

int ast_free(ast *ast);
int ast_dot(ast *ast);
ast *ast_init(list *list);
ast *ast_implicit_and(void);

#endif /* !AST_H */
