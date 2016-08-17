/*
 * Problem 1 - build123()
 *
 * This is a very basic problem with a little pointer manipulation. (You can
 * skip this problem if you are already comfortable with pointers.) Write code
 * that builds the following little 1-2-3 binary search tree...
 *
 *     2
 *    / \
 *   1   3
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

int main(int argc, char* argv[]) {
    struct node* root = build123();

    printf("%d\n", root->data);
    printf("%d\n", root->left->data);
    printf("%d\n", root->right->data);
}
