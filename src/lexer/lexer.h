#ifndef LEXER_H
#define LEXER_H

#include <stddef.h>
#include <string.h>
#include <sys/stat.h>

#include "list.h"

enum lexer_error
{
    NO_ERROR = 0,
    FAILED_MALOC,
    MISSING_NAME,
    MISSING_TYPE,
    TYPE_UNKNOW_ARGS,
    TYPE_STICK_ARGS,
    TYPE_MISSING_ARGS,
    OPERATOR_RIGHT,
    OPERATOR_LEFT,
};

enum lexer_error lexer(list *args, char *argv[]);
int lexer_handle_error(enum lexer_error error, list *args);

#endif /* !LEXER_H */
