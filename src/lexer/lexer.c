#include "lexer.h"

enum lexer_error control_type_args(char *type_args)
{
    if (!type_args)
        err(50, "Attempt to control type args null");
    if (strlen(type_args) != 1)
        errx(1, "invalid format type: %s", type_args);
    if (strchr("bcdlfps", type_args[0]) == NULL)
        errx(1, "invalid element: %s", type_args);
    return NO_ERROR;
}

enum lexer_error _action(list **args, enum token_type type)
{
    (*args)->next = list_init(type);
    *args = (*args)->next;
    if (!(*args))
        return FAILED_MALOC;
    return NO_ERROR;
}

enum lexer_error _operation(list **args, enum token_type type,
                            char *last_was_operator)
{
    if (*last_was_operator && type != TOKEN_NOT)
        return OPERATOR_LEFT;
    (*args)->next = list_init(type);
    *args = (*args)->next;
    if (!(*args))
        return FAILED_MALOC;
    *last_was_operator = 1;
    return NO_ERROR;
}

enum lexer_error _test(list **args, enum token_type type, int *i, char **argv)
{
    (*args)->next = list_init(type);
    (*args) = (*args)->next;
    if (!(*args))
        return FAILED_MALOC;
    *i += 1;
    if (!argv[*i])
        errx(1, "missing argument after -predicate");
    ;
    return NO_ERROR;
}

void _copy_arg(list **args, char *arg)
{
    (*args)->token->data = calloc(1, strlen(arg) + 1);
    strcpy((*args)->token->data, arg);
}

enum lexer_error lexer(list *args, char *argv[])
{
    char last_was_operator = 1;
    enum lexer_error error = NO_ERROR;
    for (int i = 0; argv[i]; i++)
    {
        if (!strcmp(argv[i], "-print"))
        {
            error = _action(&args, TOKEN_PRINT);
            last_was_operator = 0;
        }
        else if (!strcmp(argv[i], "-name"))
        {
            error = _test(&args, TOKEN_NAME, &i, argv);
            if (!error)
                _copy_arg(&args, argv[i]);
            last_was_operator = 0;
        }
        else if (!strcmp(argv[i], "-newer"))
        {
            error = _test(&args, TOKEN_NEWER, &i, argv);
            if (!error)
            {
                _copy_arg(&args, argv[i]);
                struct stat info_file;
                if (stat(args->token->data, &info_file) == -1)
                    errx(1, "%s: no such file or directory", args->token->data);
            }
            last_was_operator = 0;
        }
        else if (!strcmp(argv[i], "-type"))
        {
            error = _test(&args, TOKEN_TYPE, &i, argv);
            if (!error)
            {
                error = control_type_args(argv[i]);
                _copy_arg(&args, argv[i]);
            }
            last_was_operator = 0;
        }
        else if (!strcmp(argv[i], "-o"))
            error = _operation(&args, TOKEN_OR, &last_was_operator);
        else if (!strcmp(argv[i], "!") || !strcmp(argv[i], "-!"))
            error = _operation(&args, TOKEN_NOT, &last_was_operator);
        else if (!strcmp(argv[i], "-a"))
            error = _operation(&args, TOKEN_AND, &last_was_operator);
        else if (argv[i][0] == '-')
            errx(1, "unkown predicate '%s'", argv[i]);
        else if (i == 0)
            return 0;
        else
            errx(1, "path must precede expression '%s'", argv[i]);
        if (last_was_operator && !argv[i + 1])
            error = OPERATOR_RIGHT;
        if (error)
            return error;
    }
    return error;
}

int lexer_handle_error(enum lexer_error error, list *args)
{
    list_free(args);
    if (error == FAILED_MALOC)
        errx(1, "miss ram capacity");
    if (error == MISSING_NAME)
        errx(1, "missing argument to '-name'");
    if (error == MISSING_TYPE)
        errx(1, "missing argument to '-type'");
    if (error == TYPE_UNKNOW_ARGS)
        errx(1, "unknown argument to -type");
    if (error == TYPE_STICK_ARGS)
        errx(1, "must separate multiple arguments to -type using: ','");
    if (error == TYPE_MISSING_ARGS)
        errx(1,
             "last file type in list argument to -type is missing, i.e., list "
             "is ending on: ','");
    if (error == OPERATOR_RIGHT)
        errx(1, "expected an expression after an operator");
    if (error == OPERATOR_LEFT)
        errx(1, "expected an expression before an operator");
    return 1;
}
