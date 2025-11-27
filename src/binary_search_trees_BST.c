#include "../include/trees.h"

root *BST(root *r,int key)
{
    if (r==NULL || r->value == key )return r;
    else if(r->value < key) return BST(r->right_child,key);
    else return BST(r->left_child,key);
}
int main()
{
    root *r = create_node(6);
    r->left_child = create_node(3);
    r->left_child->left_child = create_node(2);
    r->left_child->right_child = create_node(4);
    r->right_child = create_node(10);
    r->right_child->right_child = create_node(12);

    print_entire_tree(r);
    
    if(BST(r,6) != NULL)printf("FOUND\n");
    else printf("NOT FOUND \n");


}