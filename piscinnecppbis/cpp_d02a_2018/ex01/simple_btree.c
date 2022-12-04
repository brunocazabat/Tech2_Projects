/*
** EPITECH PROJECT, 2019
** tree
** File description:
** tree
*/

#include <stdlib.h>
#include <stdio.h>
#include "simple_btree.h"

bool_t btree_delete(tree_t *root_ptr)
{
    tree_t tmp = *root_ptr;

    if (btree_is_empty(*root_ptr))
        return (FALSE);
    if (tmp->left != NULL)
        btree_delete(&tmp->left);
    if (tmp->right != NULL)
        btree_delete(&tmp->right);
    free(tmp);
    *root_ptr = NULL;
    return (TRUE);
}

double btree_get_max_value(tree_t tree)
{
    double left = 0;
    double right = 0;

    if (btree_is_empty(tree))
        return (0);
    if (tree->left != NULL)
        left = btree_get_max_value(tree->left);
    if (tree->right != NULL)
        right = btree_get_max_value(tree->right);
    if (left >= right)
        return ((left > tree->value) ? left : tree->value);
    else
        return ((right > tree->value) ? right : tree->value);
}

double btree_get_min_value(tree_t tree)
{
    double left = -1;
    double right = -1;

    if (btree_is_empty(tree))
        return (0);
    if (tree->left != NULL)
        left = btree_get_min_value(tree->left);
    if (tree->right != NULL)
        right = btree_get_min_value(tree->right);
    if (left <= right)
        return ((tree->value < left || left == -1) ? tree->value : left);
    else
        return ((tree->value < right || right == -1) ? tree->value : right);
}

bool_t btree_create_node(tree_t *node_ptr, double value)
{
    tree_t new_node = malloc(sizeof(tree_t));

    if (!new_node)
        return (FALSE);
    new_node->value = value;
    new_node->left = NULL;
    new_node->right = NULL;
    *node_ptr = new_node;
    return (TRUE);
}