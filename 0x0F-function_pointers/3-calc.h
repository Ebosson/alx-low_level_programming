#ifndef CALC_H
#define CALC_H

/**
 * struct op - A struct op.
 * @op: The operator.
 * @f: The associated function.
 */
typedef struct op
{
	char *op;
	int (*f)(int a, int b);
} op_t;

int op_add(int a, b);
int op_sub(int a, b);
int op_mul(int a, b);
int op_div(int a, b);
int op_mod(int a, b);
int (*get_op_func(char *s))(int, int); /* Added a space after int */

#endif

