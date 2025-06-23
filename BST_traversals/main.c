/*
Scaffold - Level order Traversal
Kacie Beckett May 2025
(c) University of Melbourne
*/
#include <stdio.h>
#include <stdlib.h>
#include "treeops.h"
#include "listops.h"
#include <assert.h>
void print_level_order_traversal(tree_t *tree);
void inorder_traversal(tree_t *tree); 
void preorder_traversal(tree_t *tree); 
void postorder_traversal(tree_t *tree); 
int tree_cmp(void *a, void *b);

int main(int argc, char *argv[]) {
    tree_t *tree = make_empty_tree(tree_cmp);
    int random[] = {7, 2, 14, 1, 9, 12, 5, 10, 3, 6, 15, 4, 11, 13, 8};

    for (int i = 0; i < 15; i++) {
        // int *a = (int*) malloc(sizeof(*a));
        // *a = i;
        // insert_in_order(tree, a);
        int *a = (int*) malloc(sizeof(*a)); 
        *a = random[i]; 
        insert_in_order(tree, a);
    }
    printf("Post-order: "); 
    postorder_traversal(tree); 
    printf("Pre-order: "); 
    preorder_traversal(tree); 
    printf("In-order: "); 
    inorder_traversal(tree); 
    print_level_order_traversal(tree);

    return 0;
}

int tree_cmp(void *a, void *b) {
    return *((int *) a) - *((int *) b);
}

// Challenge Task 
// Write code to print a level order traversal of a tree

/* L -> Root -> R */
void inorder_recursive(tnode_t *tnode) {
    if (tnode == NULL) return; 
    inorder_recursive(tnode->left); 
    printf("%d ", *(int*)tnode->data); 
    inorder_recursive(tnode->rght); 
}
void inorder_traversal(tree_t *tree) {
    if (tree->root == NULL) return;
    inorder_recursive(tree->root); 
    printf("\n"); 
}
/* L -> R -> Root */
void postorder_recursive(tnode_t *tnode) {
    if (tnode == NULL) return; 
    postorder_recursive(tnode->left); 
    postorder_recursive(tnode->rght); 
    printf("%d ", *(int*)tnode->data); 
}
void postorder_traversal(tree_t *tree) {
    if (tree->root == NULL) return;
    postorder_recursive(tree->root); 
    printf("\n"); 
}
/* Root -> L -> R*/
void preorder_recursive(tnode_t *tnode) {
    if (tnode == NULL) return; 
    printf("%d ", *(int*)tnode->data); 
    postorder_recursive(tnode->left); 
    postorder_recursive(tnode->rght); 
}
void preorder_traversal(tree_t *tree) {
    if (tree->root == NULL) return;
    preorder_recursive(tree->root); 
    printf("\n"); 
}

// Dequeue at front, enqueue at foot. 
data_t dequeue(list_t *list) {
    data_t popped_node = get_head(list); 
    node_t *temp = list->head; 
    list->head = list->head->next; 
    if (list->head == NULL) {
        list->foot = NULL; 
    }
    free(temp); 
    return popped_node;
}
list_t *enqueue(list_t *list, data_t value) {
    node_t *new_node = malloc(sizeof(node_t));
    assert(new_node != NULL);
    new_node->next = NULL; 
    new_node->data = value; 
    if (is_empty_list(list)) {
        list->head = list->foot = new_node;
    } else {
        list->foot->next = new_node; 
        list->foot = new_node; 
    }

    return list; 
}
void print_level_order_traversal(tree_t *tree) {
    list_t *queue = make_empty_list(); 
    enqueue(queue, tree->root); 
    while (!is_empty_list(queue)){
        data_t removed_tree_node = dequeue(queue); 
        if(removed_tree_node->left != NULL) enqueue(queue, removed_tree_node->left); 
        if(removed_tree_node->rght != NULL) enqueue(queue, removed_tree_node->rght); 
        printf("%d ", *(int*)removed_tree_node->data); 
    }
    free_list(queue);
}
