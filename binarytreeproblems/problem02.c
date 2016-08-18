/*
 * Problem 2 - size()
 *
 * This problem demonstrates simple binary tree traversal. Given a binary tree,
 * count the number of nodes in the tree.
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

struct node* build123() {
    struct node* root = NewNode(2);
    root->left = NewNode(1);
    root->right = NewNode(3);

    return root; 
}

int size(struct node* node) {
    int count = 0;

    if (node == NULL) {
        return count;
    }
    
    if (node->left != NULL) {
        count = count + size(node->left);
    }

    if (node->right != NULL) {
        count = count + size(node->right);
    }
   
    // Add in root node. 
    count++;

    return count;
}

int main(int argc, char* argv[]) {
    struct node* root = build123();

    // This is not a binary search tree.
    root->left->left = NewNode(33);
    root->left->right = NewNode(28);
    root->left->right->left = NewNode(92);
    root->right->right = NewNode(4);
    root->right->right->right = NewNode(5);
    root->right->right->right->left = NewNode(100);

    int count = size(root);
    printf("%d\n", count);
}
