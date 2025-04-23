#include <err.h>
#include <stdio.h>
#include <stdlib.h>

#include "expression.h"

int eval_expr(struct my_expr *expr)
{
    if (expr->type == EXPR_NUMBER)
        return expr->data.value;
    if (expr->type == EXPR_ADDITION)
        return eval_expr(expr->data.children.left)
            + eval_expr(expr->data.children.right);
    if (expr->type == EXPR_SUBTRACTION)
        return eval_expr(expr->data.children.left)
            - eval_expr(expr->data.children.right);
    if (expr->type == EXPR_MULTIPLICATION)
        return eval_expr(expr->data.children.left)
            * eval_expr(expr->data.children.right);
    if (expr->type == EXPR_DIVISION)
    {
        int divisor = eval_expr(expr->data.children.right);
        if (!divisor)
            err(1, "Division by zero not allowed!");
        return eval_expr(expr->data.children.left) / divisor;
    }
    if (expr->type == EXPR_ADDITION)
        return eval_expr(expr->data.children.left)
            + eval_expr(expr->data.children.right);
    if (expr->type == EXPR_NEGATION)
        return (-1) * eval_expr(expr->data.children.left);

    return 0;
}
