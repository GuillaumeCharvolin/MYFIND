#include "stack.h"

#include <stdlib.h>

stack *stack_push(stack *stack, ast *ast)
{
    if (!ast)
        return NULL;
    struct stack *new = malloc(sizeof(struct stack));
    if (!new)
        return NULL;

    new->ast = ast;
    new->next = stack;
    return new;
}

stack *stack_pop(stack *stack)
{
    if (!stack)
        return NULL;

    struct stack *temp = stack->next;
    free(stack);
    return temp;
}

int stack_print(stack *stack, FILE *file)
{
    if (stack == NULL)
        errx(50, "attempt to print a null stack");
    fprintf(file, "< ");
    for (; stack->next; stack = stack->next)
    {
        token_print(stack->ast->token, file);
        fprintf(file, ", ");
    }
    token_print(stack->ast->token, file);
    fprintf(file, " |\n");
    return 0;
}

int stack_free(stack *stack)
{
    if (!stack)
        errx(50, "attempt to free a null stack");
    ast_free(stack->ast);
    free(stack);
    return 0;
}

ast *stack_peek(stack *stack)
{
    if (!stack)
        return NULL;
    return stack->ast;
}

char is_single(stack *stack)
{
    return stack->ast->token->type == TOKEN_NONE
        || stack->next->ast->token->type == TOKEN_NONE;
}
