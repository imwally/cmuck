/*
 * Problem 3 - maxDepth() 
 *
 * Given a binary tree, compute its "maxDepth" -- the number of nodes along the
 * longest path from the root node down to the farthest leaf node. The maxDepth
 * of the empty tree is 0, the maxDepth of the tree on the first page is 3.
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

int maxDepth(struct node* node) {
    int count = 0;

    if (node == NULL) {
        return count;
    }
    
    if (node->left != NULL) {
        count = maxDepth(node->left);
    }

    if (node->right != NULL) {
        count = maxDepth(node->right);
    }
   
    count++;

    return count;
}

int main(int argc, char* argv[]) {
    struct node* root = build123();

    // This is not a binary search tree.
    root->left->left = NewNode(33);
    root->left->left->left = NewNode(53);
    root->left->right = NewNode(28);
    root->left->right->left = NewNode(92);
    root->right->right = NewNode(4);
    root->right->right->right = NewNode(5);
    root->right->right->right->left = NewNode(100);
    root->right->right->right->left->right = NewNode(100);

    int count = maxDepth(root);
    printf("%d\n", count);
}
