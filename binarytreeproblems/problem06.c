/*
 * Problem 6 - printPostorder()
 *
 * Given a binary tree, print out the nodes of the tree according to a
 * bottom-up "postorder" traversal -- both subtrees of a node are printed out
 * completely before the node itself is printed, and each left subtree is
 * printed before the right subtree.
 */

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* NewNode(int data) {
    struct node* node = malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return (node);
}

struct node* buildBSTree() {
    struct node* root = NewNode(4);
    root->left = NewNode(2);
    root->left->right = NewNode(3);
    root->left->left = NewNode(1);

    root->right = NewNode(5);

    return root; 
}

void printPostorder(struct node* node) {
    if (node == NULL) {
        return;
    }

    if (node->left != NULL) {
        printPostorder(node->left);
    }
    
    if (node->right != NULL) {
        printPostorder(node->right);
    }

    printf("%d  ", node->data);
}

int main(int argc, char* argv[]) {
    struct node* root = buildBSTree();
    printPostorder(root);
}
