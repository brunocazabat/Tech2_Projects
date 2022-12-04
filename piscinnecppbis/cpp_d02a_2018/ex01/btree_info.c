/*
** EPITECH PROJECT, 2019
** info
** File description:
** info
*/

#include <stdlib.h>
#include <stdio.h>
#include "simple_btree.h"

bool_t btree_is_empty(tree_t tree)
{
    if (tree == NULL)
        return (TRUE);
    return (FALSE);
}

unsigned int btree_get_size(tree_t tree)
{
    unsigned int i = 0;

    if (btree_is_empty(tree))
        return (0);
    if (tree->left != NULL)
        i += btree_get_size(tree->left);
    if (tree->right != NULL)
        i += btree_get_size(tree->right);
    return (i += 1);
}

unsigned int btree_get_depth(tree_t tree)
{
    unsigned int left = 0;
    unsigned int right = 0;

    if (btree_is_empty(tree))
        return (0);
    if (tree->left != NULL)
        left += btree_get_depth(tree->left);
    if (tree->right != NULL)
        right += btree_get_depth(tree->right);
    return ((left >= right) ? left + 1 : right + 1);
}