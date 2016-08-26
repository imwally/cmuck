/*
 * Problem 10 - doubleTree()
 * 
 * For each node in a binary search tree, create a new duplicate node, and
 * insert the duplicate as the left child of the original node. The resulting
 * tree should still be a binary search tree.
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

    return node;
}

struct node* buildBSTree() {
    struct node* root = NewNode(2);
    root->left = NewNode(1);
    root->right = NewNode(3);

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

void doubleTree(struct node* node) {
    if (node == NULL) {
        return;
    }

    struct node* temp = node->left;  
    node->left = NewNode(node->data);
    node->left->left = temp;

    doubleTree(node->right);
    doubleTree(node->left->left);
}

int main(int argc, char* argv[]) {
    struct node* root = buildBSTree();
    printPostorder(root);
    printf("\n");
    doubleTree(root);
    printPostorder(root);
    printf("\n");
}
