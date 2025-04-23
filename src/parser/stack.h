#ifndef STACK_H
#define STACK_H

#include <err.h>
#include <stdio.h>
#include <stdlib.h>

#include "../lexer/list.h"
#include "../lexer/token.h"
#include "ast.h"

typedef struct stack
{
    ast *ast;
    struct stack *next;
} stack;

int stack_print(stack *stack, FILE *file);
int stack_free(stack *stack);
stack *stack_push(stack *stack, ast *ast);
stack *stack_pop(stack *stack);
ast *stack_peek(stack *stack);
char is_single(stack *stack);

#endif /* !STACK_H */
