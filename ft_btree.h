#ifndef FT_BTREE_H
# define FT_BTREE_H
# include <unistd.h>
# include <stdio.h>
# include <stdio.h>
# include <malloc.h>
# include <string.h>
# define COUNT 10

typedef struct s_btree
{
    struct s_btree  *left;
    struct s_btree  *right;
    void    *item;
} t_btree;

void btree_apply_by_level(t_btree *root, void (*applyf)(void *item, int current_level, int is_first));
void print_item(void *items, int level, int first);

#endif