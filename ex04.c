#include "ft_btree.h"

static int btree_level_count(t_btree *root)
{
	int size_left;
	int size_right;

	if (!root)
		return (0);
	size_left = btree_level_count(root->left);
	size_right = btree_level_count(root->right);
	if (size_left > size_right)
		return (size_left + 1);
	else
		return(size_right + 1);
}

void __space_calculator(t_btree *root)
{
    t_btree *tmp;
    int i;

    i = 0;
    if(!root)
        return;
    tmp = root;
     while(tmp)
    {
        //printf("-%s-",tmp->item);
        tmp = tmp->left;
        i++;
    }
    while ( i >= 0)
    {
        printf("  ");
        i--;
    }
 }

void btree_process_level(t_btree *root,int *tab, int level, void (*applyf)(void *item, int current_level, int is_first))
{
    if (!root)
        return ;
    if (level == 1)
    {
        if (tab[1] == 1)
            printf("\n");
        __space_calculator(root);
        applyf(root->item, tab[0],tab[1]);
        tab[1] = 0;
    }
    else if (level > 1)
    {
        btree_process_level(root->left, tab, level -1, applyf);
        btree_process_level(root->right, tab, level -1, applyf);
    }

}

void btree_apply_by_level(t_btree *root, void (*applyf)(void *item, int current_level, int is_first))
{
    int tab[2];
    int size;
    int i;

    size = btree_level_count(root);
    i = 0;
    while (i < size)
    {
        tab[0] = i;
        tab[1] = 1;
        i++;
        btree_process_level(root,tab , i, applyf);
    }
}