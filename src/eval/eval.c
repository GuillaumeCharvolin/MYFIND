#include "eval.h"

int eval_expr(char *full_name, char *name, ast *ast, char *is_printed)
{
    if (!ast)
        return 0;
    if (ast->token->type == TOKEN_PRINT)
        return _print(full_name, is_printed);
    if (ast->token->type == TOKEN_NAME)
        return _name(name, ast->token);
    if (ast->token->type == TOKEN_OR)
        return !(!eval_expr(full_name, name, ast->left, is_printed)
                 || !eval_expr(full_name, name, ast->right, is_printed));
    if (ast->token->type == TOKEN_AND)
        return !(!eval_expr(full_name, name, ast->left, is_printed)
                 && !eval_expr(full_name, name, ast->right, is_printed));
    if (ast->token->type == TOKEN_TYPE)
        return _type(full_name, ast->token->data[0]);
    if (ast->token->type == TOKEN_NOT)
        return !eval_expr(full_name, name, ast->left, is_printed);
    if (ast->token->type == TOKEN_NEWER)
        return _newer(ast->token->data, full_name);
    errx(1, "evaluation of this token is unimplemented");
}

int eval_rec(char *path, ast *root)
{
    DIR *dir = opendir(path);
    if (!dir)
        return 0;

    struct dirent *entry = readdir(dir);
    for (; entry; entry = readdir(dir))
    {
        if (!strcmp(entry->d_name, "..") || !strcmp(entry->d_name, "."))
            continue;

        int path_len = strlen(path);
        int full_path_len = path_len + strlen(entry->d_name) + 2;
        char *full_path = calloc(1, sizeof(char) * full_path_len);

        if (!full_path)
            continue;

        strcpy(full_path, path);
        if (full_path[path_len - 1] != '/')
            strcat(full_path, "/");
        strcat(full_path, entry->d_name);

        struct stat info_file;
        stat(full_path, &info_file);

        char is_printed = 0;
        if (!eval_expr(full_path, entry->d_name, root, &is_printed)
            && !is_printed)
            _print(full_path, &is_printed);

        eval_rec(full_path, root);
        free(full_path);
    }
    closedir(dir);
    return 0;
}

int eval(char *path, ast *root)
{
    char is_printed = 0;
    if (!eval_expr(path, path, root, &is_printed) && !is_printed)
        _print(path, &is_printed);
    return eval_rec(path, root);
}
