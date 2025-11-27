#ifndef TREES_H
#define TREES_h
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    int key;
    struct node *left_child;
    struct node *right_child;
} root;

// ----------------------
// Height of the tree
// ----------------------
int get_tree_height(root *r);
// ----------------------
// Print spaces
// ----------------------
void print_spaces(int n);

// ----------------------
// Print nodes at level
// ----------------------
void print_nodes_at_level(root *r, int level, int space);

// ----------------------
// Print branches ( / and \ )
// ----------------------
void print_branches(root *r, int level, int space);

// ----------------------
// Main print function
// ----------------------
void print_entire_tree(root *r);

// ----------------------
// Node creation
// ----------------------
root *create_node(int value);

#endif