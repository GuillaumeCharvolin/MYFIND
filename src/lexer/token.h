#ifndef TOKEN_H
#define TOKEN_H

#include <err.h>
#include <stdio.h>
#include <stdlib.h>

typedef enum token_type
{
    TOKEN_NONE,
    TOKEN_NAME,
    TOKEN_TYPE,
    TOKEN_OR,
    TOKEN_AND,
    TOKEN_NEWER,
    TOKEN_PRINT,
    TOKEN_NOT,
} token_type;

typedef struct token
{
    token_type type;
    char *data;
} token;

int token_print(token *token, FILE *file);
int token_free(token *token);
char is_operator(token *token);
char is_operand(token *token);

#endif /* !TOKEN_H */
