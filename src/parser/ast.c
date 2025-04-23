#include "ast.h"

#define DOT_FILE "tests/ast.dot"

int ast_free(ast *ast)
{
    if (!ast)
        return 0;

    int right = ast_free(ast->right);
    int left = ast_free(ast->left);

    token_free(ast->token);
    free(ast);
    return right && left;
}

int ast_dot_rec(ast *ast, FILE *dot_file)
{
    token_print(ast->token, dot_file);
    fprintf(dot_file, "\n");
    int error = 1;
    if (ast->right)
    {
        token_print(ast->token, dot_file);
        fprintf(dot_file, " -> ");
        token_print(ast->right->token, dot_file);
        fprintf(dot_file, "\n");
        error = error && ast_dot_rec(ast->right, dot_file);
    }
    if (ast->left)
    {
        token_print(ast->token, dot_file);
        fprintf(dot_file, " -> ");
        token_print(ast->left->token, dot_file);
        fprintf(dot_file, "\n");
        error = error && ast_dot_rec(ast->left, dot_file);
    }
    return error;
}

int ast_dot(ast *root)
{
    FILE *dot_file = fopen(DOT_FILE, "w+");
    if (!dot_file)
        errx(1, "can not open dot file");
    int error = ast_dot_rec(root, dot_file);
    fclose(dot_file);
    return error;
}

ast *ast_implicit_and(void)
{
    ast *ast = malloc(sizeof(struct ast));
    if (!ast)
        errx(1, "miss ram capacity");
    ast->token = malloc(sizeof(token));
    if (!ast->token)
        errx(1, "miss ram capacity");
    ast->right = NULL;
    ast->left = NULL;
    ast->token->type = TOKEN_AND;
    ast->token->data = NULL;
    return ast;
}

ast *ast_init(list *list)
{
    ast *ast = malloc(sizeof(struct ast));
    if (!ast)
        errx(1, "miss ram capacity");
    ast->token = malloc(sizeof(token));
    if (!ast->token)
        errx(1, "miss ram capacity");
    ast->right = NULL;
    ast->left = NULL;
    ast->token->type = list->token->type;
    if (!list->token->data)
        ast->token->data = NULL;
    else
    {
        ast->token->data =
            calloc(1, sizeof(char) * (strlen(list->token->data) + 1));
        if (!ast->token->data)
            errx(1, "miss ram capacity");
        if (!strcpy(ast->token->data, list->token->data))
            errx(1, "miss ram capacity");
    }
    return ast;
}
