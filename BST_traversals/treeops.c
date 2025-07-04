// Note: all node_t renamed to tnode_t to avoid collisions with listops
#include "treeops.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

tree_t *
make_empty_tree(int func(void *, void *)) {
    tree_t *tree;
    tree = malloc(sizeof(*tree));
    assert(tree != NULL);
    /* initialize tree to empty */
    tree->root = NULL;
    /* and save the supplied function pointer */
    tree->cmp = func;
    return tree;
}

int
is_empty_tree(tree_t *tree) {
    assert(tree != NULL);
    return tree->root == NULL;
}

static void *recursive_search_tree(tnode_t *, void *, int(void *, void *));

static void *
recursive_search_tree(tnode_t *root, void *key, int cmp(void *, void *)) {
    int outcome;
    if (!root) {
        return NULL;
    }
    if ((outcome = cmp(key, root->data)) < 0) {
        return recursive_search_tree(root->left, key, cmp);
    } else if (outcome > 0) {
        return recursive_search_tree(root->rght, key, cmp);
    } else {
        /* hey, must have found it! */
        return root->data;
    }
}

/* Returns a pointer to the tree node storing object "key",
   if it exists, otherwise returns a NULL pointer. */
void *
search_tree(tree_t *tree, void *key) {
    assert(tree != NULL);
    return recursive_search_tree(tree->root, key, tree->cmp);
}

static tnode_t *recursive_insert(tnode_t *, tnode_t *, int(void *, void *));

static tnode_t *
recursive_insert(tnode_t *root, tnode_t *new, int cmp(void *, void *)) {
    if (root == NULL) {
        return new;
    } else if (cmp(new->data, root->data) < 0) {
        root->left = recursive_insert(root->left, new, cmp);
    } else {
        root->rght = recursive_insert(root->rght, new, cmp);
    }
    return root;
}

/* Returns a pointer to an altered tree that now includes
   the object "value" in its correct location. */
tree_t *
insert_in_order(tree_t *tree, void *value) {
    tnode_t *new;
    /* make the new node */
    new = malloc(sizeof(*new));
    assert(tree != NULL && new != NULL);
    new->data = value;
    new->left = new->rght = NULL;
    /* and insert it into the tree */
    tree->root = recursive_insert(tree->root, new, tree->cmp);
    return tree;
}

static void recursive_traverse(tnode_t *, void action(void *));

static void
recursive_traverse(tnode_t *root, void action(void *)) {
    if (root) {
        recursive_traverse(root->left, action);
        action(root->data);
        recursive_traverse(root->rght, action);
    }
}

/* Applies the "action" at every node in the tree, in
   the order determined by the cmp function. */
void
traverse_tree(tree_t *tree, void action(void *)) {
    assert(tree != NULL);
    recursive_traverse(tree->root, action);
}

static void recursive_free_tree(tnode_t *);

static void
recursive_free_tree(tnode_t *root) {
    if (root) {
        recursive_free_tree(root->left);
        recursive_free_tree(root->rght);
        free(root);
    }
}

/* Release all memory space associated with the tree
   structure. */
void
free_tree(tree_t *tree) {
    assert(tree != NULL);
    recursive_free_tree(tree->root);
    free(tree);
}

/* =====================================================================
   Program written by Alistair Moffat, as an example for the book
   "Programming, Problem Solving, and Abstraction with C", Pearson
   Custom Books, Sydney, Australia, 2002; revised edition 2012,
   ISBN 9781486010974.

   See http://people.eng.unimelb.edu.au/ammoffat/ppsaa/ for further
   information.

   Prepared December 2012 for the Revised Edition.
   ================================================================== */