#include "micro_ast.h"

t_type __find_type(char *item)
{
    if(__strncmp(item, "+", 2) == 0)
        return (PLUS);
    if(__strncmp(item, "*", 2) == 0)
        return (MULTI);
    else 
        return (NBR);
}

t_btree	*btree_create_node(char *item)
{
	t_btree	*new;

	new = malloc(sizeof(t_btree));
	if (!new)
		return (NULL);
	new->left = NULL;
	new->left = NULL;
	new->item = item;
    new->type = __find_type(item);
	return (new);
}

t_btree *__create_node(char **parsing)
{
    char **tmp;

    
}

t_btree **root(char *input, t_btree **root)
{
    if (!root)
    {
        root = 
    }
}

void create_tree(char **parsing, t_btree **root)
{
    
    int i;
    t_btree *new;

    i = 0;
    while (parsing[i])
    {
        new = __create_node(parsing[i]);
        root = __insert_node(new, root);
        i++
    }
	if (!*root)
	{
		*root = insert;
		return ;
	}
	if (insert->type == PLUS)
		btree_insert_data(&(*root)->left,item, cmpf);
	else
		btree_insert_data(&(*root)->right,item, cmpf);
}


int main (int ac, char **av)
{
    t_btree *root;
    char **parsing;

    parsing = __split(av[1],' ');
    __create_tree(parsing, &root);
    return (0);
}

// si je suis un nbr et que right et left sont null je cree la liste
// si je suis un operateur et que left est nbr, je me creer et le nbr devient ma branche left
// si je suis un nbr et que left est pris par un nbr ou un operateur je me met dans la branche droite
// si je suis un operateur et que left est un operateur, je devient le root.
