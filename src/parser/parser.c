#include "parser.h"

int parser(ast *root, list *args)
{
    stack *operator= stack_push(NULL, ast_init(args));
    stack *operand = stack_push(NULL, ast_init(args));
    char was_operand = 0;
    for (args = args->next; args; args = args->next)
    {
        if (is_operand(args->token))
        {
            if (was_operand)
                operator= stack_push(operator, ast_implicit_and());
            operand = stack_push(operand, ast_init(args));
            was_operand = 1;
        }
        else if (is_operator(args->token))
        {
            operator= stack_push(operator, ast_init(args));
            was_operand = 0;
        }
    }
    for (ast *operation = stack_peek(operator);
         operation->token->type != TOKEN_NONE;
         operator= stack_pop(operator), operation = stack_peek(operator))
    {
        ast *left = stack_peek(operand);
        if (!left)
            errx(1, "missing operand in operand stack");
        operand = stack_pop(operand);
        operation->left = left;

        if (operation->token->type != TOKEN_NOT)
        {
            ast *right = stack_peek(operand);
            if (!right)
                errx(1, "missing operand in operand stack");
            operand = stack_pop(operand);
            operation->right = right;
        }

        operand = stack_push(operand, operation);
    }
    if (!is_single(operand))
        errx(1, "missing operator in operator stack");
    if (stack_peek(operand)->token->type != TOKEN_NONE)
    {
        root->left = stack_peek(operand);
        operand = stack_pop(operand);
    }

    stack_free(operand);
    stack_free(operator);

    return 0;
}
