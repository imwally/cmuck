/*
 * Problem 9 - mirror()
 * 
 * Change a tree so that the roles of the left and right pointers are swapped
 * at every node.
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

void mirror(struct node* node) {
    if (node == NULL) {
        return;
    }
    
    struct node* temp;
    temp = node->left;
    node->left = node->right;
    node->right = temp;

    mirror(node->right);
    mirror(node->left);
}

int main(int argc, char* argv[]) {
    struct node* root = buildBSTree();
    printPostorder(root);
    printf("\n");
    mirror(root);
    printPostorder(root);
    printf("\n");
}
