#include <stdio.h>
#include <stdlib.h>
#include "../include/trees.h"


// ----------------------
// Height of the tree
// ----------------------
int get_tree_height(root *r) {
    if (r == NULL) return 0;
    int lh = get_tree_height(r->left_child);
    int rh = get_tree_height(r->right_child);
    return (lh > rh ? lh : rh) + 1;
}

// ----------------------
// Print spaces
// ----------------------
void print_spaces(int n) {
    for (int i = 0; i < n; i++)
        printf(" ");
}

// ----------------------
// Print nodes at level
// ----------------------
void print_nodes_at_level(root *r, int level, int space) {
    if (level == 1) {
        print_spaces(space);
        if (r)
            printf("%d", r->value);
        else
            printf(" ");
        print_spaces(space);
    } else {
        if (r == NULL) {
            // Print empty placeholders for missing children
            print_nodes_at_level(NULL, level - 1, space);
            print_nodes_at_level(NULL, level - 1, space);
        } else {
            print_nodes_at_level(r->left_child, level - 1, space);
            print_nodes_at_level(r->right_child, level - 1, space);
        }
    }
}

// ----------------------
// Print branches ( / and \ )
// ----------------------
void print_branches(root *r, int level, int space) {
    if (level == 1) {
        if (r == NULL) {
            print_spaces(space * 2 + 1);
            return;
        }

        print_spaces(space - 1);
        if (r->left_child) printf("/");
        else printf(" ");

        print_spaces(2);

        if (r->right_child) printf("\\");
        else printf(" ");

        print_spaces(space - 1);
    } else {
        if (r == NULL) {
            print_branches(NULL, level - 1, space);
            print_branches(NULL, level - 1, space);
        } else {
            print_branches(r->left_child, level - 1, space);
            print_branches(r->right_child, level - 1, space);
        }
    }
}

// ----------------------
// Main print function
// ----------------------
void print_entire_tree(root *r) {
    int h = get_tree_height(r);
    int space = 4 * h;

    for (int i = 1; i <= h; i++) {
        // print the nodes of this level
        print_nodes_at_level(r, i, space);
        printf("\n");

        // print branches after the nodes
        if (i != h) {
            print_branches(r, i, space);
            printf("\n");
        }

        // reduce spacing each level
        space /= 2;
    }
}

// ----------------------
// Node creation
// ----------------------
root *create_node(int value) {
    root *r = (root*)malloc(sizeof(root));
    r->value = value;
    r->left_child = NULL;
    r->right_child = NULL;
    return r;
}






