#include "list.h"

int list_free(list *list)
{
    if (!list)
        errx(50, "attempt to free a null list");
    while (list)
    {
        struct list *temp = list->next;
        token_free(list->token);
        free(list);
        list = temp;
    }
    return 0;
}

int list_print(list *list, FILE *file)
{
    if (list == NULL)
        errx(50, "attempt to print a null list");
    fprintf(file, "[");
    for (; list->next; list = list->next)
    {
        token_print(list->token, file);
        fprintf(file, ", ");
    }
    token_print(list->token, file);
    fprintf(file, "]\n");
    return 0;
}

list *list_init(enum token_type type)
{
    list *list = malloc(sizeof(struct list));
    if (!list)
        return NULL;
    list->token = malloc(sizeof(token));
    if (!list->token)
    {
        free(list);
        return NULL;
    }
    list->next = NULL;
    list->token->type = type;
    list->token->data = NULL;
    return list;
}
