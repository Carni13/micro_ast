#ifndef MICRO_AST_H
# define MICRO_AST_H
# include <unistd.h>
# include <stdio.h>
# include <stdio.h>
# include <malloc.h>
# include <string.h>
# include "libft/includes/libft.h"
# define COUNT 10

typedef enum	e_type
{PLUS = 0, MULTI = 1, MINUS = 2, DIVIDE = 3, NBR = 4} t_type;

typedef struct s_btree
{
    t_type type;
    char    *token;
    struct s_btree  *left;
    struct s_btree  *right;
} t_btree;

#endif
