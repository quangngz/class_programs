// Note: all node_t renamed to tnode_t to avoid collisions with listops
typedef struct tnode tnode_t;

struct tnode {
    void *data;    /* ptr to stored structure */
    tnode_t *left; /* left subtree of node */
    tnode_t *rght; /* right subtree of node */
};

typedef struct {
    tnode_t *root;              /* root node of the tree */
    int (*cmp)(void *, void *); /* function pointer */
} tree_t;

/* prototypes for the functions in this library */
tree_t *make_empty_tree(int func(void *, void *));
int is_empty_tree(tree_t *tree);
void *search_tree(tree_t *tree, void *key);
tree_t *insert_in_order(tree_t *tree, void *value);
void traverse_tree(tree_t *tree, void action(void *));
void free_tree(tree_t *tree);

/* =====================================================================
   Program written by Alistair Moffat, as an example for the book
   "Programming, Problem Solving, and Abstraction with C", Pearson
   Custom Books, Sydney, Australia, 2002; revised edition 2012,
   ISBN 9781486010974.

   See http://people.eng.unimelb.edu.au/ammoffat/ppsaa/ for further
   information.

   Prepared December 2012 for the Revised Edition.
   ================================================================== */