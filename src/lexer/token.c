#include "token.h"

int token_print(token *token, FILE *file)
{
    if (token == NULL)
        errx(50, "Attempt to print a null token");
    if (token->type == TOKEN_NONE)
        fprintf(file, "{None}");
    else if (token->type == TOKEN_NAME)
        fprintf(file, "{NameI%s}", token->data);
    else if (token->type == TOKEN_TYPE)
        fprintf(file, "{TypeI%s}", token->data);
    else if (token->type == TOKEN_OR)
        fprintf(file, "{Or}");
    else if (token->type == TOKEN_AND)
        fprintf(file, "{And}");
    else if (token->type == TOKEN_NEWER)
        fprintf(file, "{NewerI%s}", token->data);
    else if (token->type == TOKEN_PRINT)
        fprintf(file, "{Print}");
    return 0;
}

int token_free(token *token)
{
    if (token == NULL)
        errx(50, "Attempt to free a null token");
    free(token->data);
    free(token);
    return 0;
}

char is_operator(token *token)
{
    return token->type == TOKEN_OR || token->type == TOKEN_AND
        || token->type == TOKEN_NOT;
}

char is_operand(token *token)
{
    return !is_operator(token);
}
