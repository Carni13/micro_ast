#include "micro_ast.h"

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
    printf("%s\n", root->token);
 
    // Process left child
    print2DUtil(root->left, space);
}

void print2D(t_btree *root)
{
   // Pass initial space count as 0
   print2DUtil(root, 0);
}


t_type __find_type(char *item)
{
    if(!item)
        return (-1); 
    if(__strncmp(item, "+", 2) == 0)
        return (PLUS);
    if(__strncmp(item, "*", 2) == 0)
        return (MULTI);
    else 
        return (NBR);
}

t_btree	*btree_create_node(char *token)
{
	t_btree	*new;

	new = malloc(sizeof(t_btree));
	if (!new)
		return (NULL);
	new->left = NULL;
	new->left = NULL;
	new->token = token;
    new->type = __find_type(token);
	return (new);
}

int __priority_cmp(char *find, char *tmp)
{
    return (__find_type(find) - __find_type(tmp));
}

char *__find_next_operator(char **token)
{
    char *find;
    char *tmp;
    int i;

    find = NULL;
    tmp = NULL;
    i = 0;
    while(token[i])
    {
        if (__find_type(token[i]) == PLUS || __find_type(token[i]) == MULTI)
            tmp = token[i];
        if (find == NULL)
            find = tmp;
        else if (__priority_cmp(find, tmp) > 0)
            find = tmp;
        i++;
    }
    return (find);
}

char **__split_token_left(char **token, char *next_op)
{
    char **left;
    int     size_left;

    size_left = 0;
    while(token[size_left] != next_op)
        size_left++;
    left = malloc(sizeof(char *) * (size_left + 1));
    if (!left)
        return(NULL);
    left[size_left] = NULL;
    while(--size_left > -1)
        left[size_left] = token[size_left];
    return (left);
}

char **__split_token_right(char **token, char *next_op)
{
    char **right;
    int     size_right;
    int     i;

    size_right = 0;
    i = 0;
    while(token[i] != next_op)
        i++;
    i++;
    while (token[i + size_right])
        size_right++;
    right = malloc(sizeof(char *) * (size_right + 1));
    if (!right)
        return(NULL);
    right[size_right] = NULL;
    while(--size_right > -1)
        right[size_right] = token[size_right + i];
    return (right);
}

void print_token(char **token)
{
    int i;

    i = 0;
    while(token[i])
    {
        printf("%s\n", token[i]);
        i++;
    }
    printf("%p\n", token[i]);
}

int __create_tree(char **token, t_btree **root)
{
    char *next_op;
    char **left_token;
    char **right_token;
    t_btree *new_node;
    int res;
    int res2;

    if (!token)
    {
        *root = NULL;
        return (1);
    }
    next_op = __find_next_operator(token);
    if (! next_op)
    {
        new_node = btree_create_node(token[0]);
        if (!new_node)
            return (0);
        *root = new_node;
        return (1);
    }
    left_token = __split_token_left(token, next_op);
    right_token = __split_token_right(token, next_op);
    if (!left_token)
        return (0);
    if (!right_token)
        return (free(left_token), 0);
    new_node = btree_create_node(next_op);
    if (!new_node)
        return (0);
    *root = new_node;
    res = __create_tree(left_token, &(new_node->left));
    res2 = __create_tree(right_token, &(new_node->right));
    if (!res || !res2)
        return (0);
    //destroy_tree
    return(1);
    /*
    printf("token = %s\n", next_op);
    printf("-left-\n");
    print_token(left_token);
    printf("-right-\n");
    print_token(right_token);
    printf("\n");
        printf("\n");
    printf("\n");
*/
}

#include <string.h>

int main (int ac, char **av)
{
    t_btree *root;
    char **token;
    (void)ac;
    (void)root;

    root = NULL;
    token = __split(av[1],' ');
    /*
    int i;
    i = 0;
    while(token[i])
    {
        printf("%s\n", token[i]);
        i++;
    }
    printf("%p\n", token[i]);
    */
   int res = 0;
    res = __create_tree(token, &root);
    printf("res = %d \n", res);
    printf("root %p\n", root);
    print2D(root);
}  
//je suis un nbr et que right et left sont null je cree le node
// si je suis un nbr et que left 
// si je suis un nbr et que left est pris par un nbr ou un operateur je me met dans la branche droite
// si je suis un operateur et que left est nbr, je me creer et le nbr devient ma branche left
// si je suis un operateur et que left est un operateur, je devient le root.