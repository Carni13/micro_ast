#include "ft_btree.h"
#include <stdlib.h>
#include <string.h>

t_btree	*btree_create_node(void *item)
{
	t_btree	*new;

	new = malloc(sizeof(t_btree));
	if (!new)
		return (NULL);
	new->left = NULL;
	new->left = NULL;
	new->item = item;
	return (new);
}

void	btree_apply_prefix(t_btree *root, void (*applyf)(void *))
{
	if (!root)
		return ;
	applyf(root->item);
	btree_apply_prefix(root->left, applyf);
	btree_apply_prefix(root->right, applyf);
}

void	btree_apply_infix(t_btree *root, void (*applyf)(void *))
{
	if (!root)
		return ;
	btree_apply_infix(root->left, applyf);
	applyf(root->item);
	btree_apply_infix(root->right, applyf);

}

void	btree_apply_suffix(t_btree *root, void (*applyf)(void *))
{
	if (!root)
		return ;
	btree_apply_suffix(root->left, applyf);
	btree_apply_suffix(root->right, applyf);
	applyf(root->item);

}

void print_item(void *items, int level, int first)
{	
	printf("[%s]", (char *)items);
}

int cmpf(void *c1, void *c2)
{
	int *cmp1;
	int *cmp2;

	cmp1 = (int *)c1;
	cmp2 = (int *)c2;

	printf ("cmp1 %d cmp2 %d\n",cmp1, cmp2);
	if (cmp1 < cmp2)
		return (-1);
	if (cmp1 == cmp2)
		return (0);
	return (1);
}


void btree_insert_data(t_btree **root, void *item, int (*cmpf) (void *, void *))
{
	if (!*root)
	{
		*root = btree_create_node(item);
		return ;
	}
	if (cmpf(item, (*root)->item) < 0)
		btree_insert_data(&(*root)->left,item, cmpf);
	else
		btree_insert_data(&(*root)->right,item, cmpf);
}

void *btree_search_item(t_btree **root, void *data_ref, int (*cmpf) (void *, void *))
{

	void *item;

	if (!*root)
		return (NULL);
	item = btree_search_item(&(*root)->left, data_ref, cmpf);
	if (item)
		return (item);
	if(cmpf(data_ref, (*root)->item) == 0)
	{
		item = (*root)->item;
		return (item);
	}
	return (btree_search_item(&(*root)->right, data_ref, cmpf));
}

void print2DUtil(t_btree *root, int space)
{
    // Base case
    if (root == NULL)
        return;
 
    // Increase distance between levels
    space += COUNT;
 
    // Process right child first
    print2DUtil(root->right, space);
 
    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%s\n", root->item);
 
    // Process left child
    print2DUtil(root->left, space);
}

void print2D(t_btree *root)
{
   // Pass initial space count as 0
   print2DUtil(root, 0);
}

int btree_level_count(t_btree *root)
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

int main()
{
	t_btree *root;

	root = NULL;
	/*
	t_btree *root_left;
	t_btree *root_left1;
	t_btree *root_left2;
	t_btree *root_left3;
	t_btree *root_left4;
	t_btree *root_right;
	t_btree *root_right1;
	t_btree *root_right2;
	t_btree *root_right3;
	*/
	/*
	// level 1
	root = btree_create_node(1);
	root->left = btree_create_node(2);
	root->right = btree_create_node(3);
	// level 2
	root->left->left = btree_create_node(4);
	root->left->right = btree_create_node(5);
	root->right->left = btree_create_node(6);
	root->right->right = btree_create_node(7);
	// level 3
	root->left->left->left = btree_create_node(8);
	root->left->left->right = btree_create_node(9);
	root->left->right->left = btree_create_node(10);
	*/
	/*
	btree_apply_prefix(root, print_item);
	printf("\n");
	btree_apply_infix(root, print_item);
		printf("\n");
	btree_apply_suffix(root, print_item);
	printf("\n");
	printf("1 2 = %d\n", cmpf(1,2));
	printf("\n");
	printf("1 1 = %d\n", cmpf(1,1));
	printf("\n");
	printf("2 1 = %d\n", cmpf(2,1));
	*/
	btree_insert_data(&root, "1",	strcmp);
	print2D(root);
	btree_insert_data(&root, "0",	strcmp);
	print2D(root);
	btree_insert_data(&root, "2", strcmp);
	print2D(root);
	btree_insert_data(&root, "4",	strcmp);
	print2D(root);
	btree_insert_data(&root, "3",	strcmp);
	printf("===========================================================================\n");
	print2D(root);
	btree_insert_data(&root, "-3",	strcmp);
	printf("===========================================================================\n");
	print2D(root);
	printf("===========================================================================\n");

	/*
	printf("valeur de retour %d\n",(int *)btree_search_item(&root, 1, cmpf));
	printf("valeur de retour %d\n",(int *)btree_search_item(&root, 2, cmpf));
	printf("valeur de retour %d\n",(int *)btree_search_item(&root, 4, cmpf));
	printf("valeur de retour %d\n",(int *)btree_search_item(&root, 10, cmpf));
	*/
	printf("valeur de retour %d\n", btree_level_count(root));
	btree_apply_by_level(root, print_item);

	return (0);
}
/*
Préfixe : 1, 2, 4, 8, 9, 5, 10, 3, 6, 7
(VGD)
Infixe : 8, 4, 9, 2, 10, 5, 1, 6, 3, 7
(GVD)
Suffixe : 8, 9, 4, 10, 5, 2, 6, 7, 3, 1
(GDV)
*/