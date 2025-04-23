#ifndef LIST_H
#define LIST_H

#include "token.h"

typedef struct list
{
    struct list *next;
    token *token;
} list;

int list_free(list *list);
int list_print(list *list, FILE *file);
list *list_init(enum token_type type);

#endif /* !LIST_H */
