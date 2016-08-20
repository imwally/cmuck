/*
 * Problem 5 - printTree()
 *
 * Given a binary search tree (aka an "ordered binary tree"), iterate over the
 * nodes to print them out in increasing order. 
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
    struct node* root = NewNode(5);
    root->left = NewNode(3);
    root->left->right = NewNode(4);
    root->left->left = NewNode(1);


    root->right = NewNode(9);
    root->right->left = NewNode(6);

    return root; 
}

void printTree(struct node* node) {
    if (node == NULL) {
        return;
    }

    if (node->left != NULL) {
        printTree(node->left);
    }
    
    printf("%d  ", node->data);

    if (node->right != NULL) {
        printTree(node->right);
    }
}

int main(int argc, char* argv[]) {
    struct node* root = buildBSTree();
    printTree(root);
}
