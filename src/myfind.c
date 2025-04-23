#include <stdio.h>
#include <stdlib.h>

#include "eval/eval.h"
#include "lexer/lexer.h"
#include "parser/parser.h"

int myfind(char *path, char *argv[])
{
    // LEXER
    list *args = list_init(TOKEN_NONE);

    enum lexer_error lexer_error = lexer(args, argv);
    if (lexer_error)
        return lexer_handle_error(lexer_error, args);

    // PARSER
    ast *root = ast_init(args);
    parser(root, args);
    list_free(args);

    // EVAL
    eval(path, root->left);
    ast_free(root);

    return 0;
}

int main(int argc, char *argv[])
{
    if (argc == 1 || argv[1][0] == '-' || argv[1][0] == '!')
        return myfind(".", &argv[1]);

    int error = 0;
    for (int i = 1; argv[i] && argv[i][0] != '-'; i++)
    {
        struct stat info_file;
        if (stat(argv[i], &info_file) != -1)
            error = myfind(argv[i], &argv[i + 1]) || error;
        else
        {
            fprintf(stderr, "myfind: '%s': no such file or directory\n",
                    argv[i]);
            error = 1;
        }
    }
    return error;
}
