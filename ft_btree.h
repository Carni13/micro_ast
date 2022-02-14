#ifndef FT_BTREE_H
# define FT_BTREE_H
# include <unistd.h>
# include <stdio.h>
# include<stdio.h>
# include<malloc.h>
# define COUNT 10

typedef struct s_btree
{
    struct s_btree  *left;
    struct s_btree  *right;
    void    *item;
} t_btree;
#endif