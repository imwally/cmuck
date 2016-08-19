/*
 * Problem 4 - minValue() 
 *
 * Given a non-empty binary search tree (an ordered binary tree), return the
 * minimum data value found in that tree. Note that it is not necessary to
 * search the entire tree. A maxValue() function is structurally very similar
 * to this function. This can be solved with recursion or with a simple while
 * loop.
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

int minValue(struct node* node) {
    if (node->left == NULL) {
        return node->data;
    }

    return minValue(node->left);
}

int main(int argc, char* argv[]) {
    struct node* root = buildBSTree();

    int min_value = minValue(root);
    printf("%d\n", min_value);
}
