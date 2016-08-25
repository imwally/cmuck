/*
 * Problem 8 - printPaths()
 *
 * Given a binary tree, print out all of its root-to-leaf paths as defined
 * above. This problem is a little harder than it looks, since the "path so
 * far" needs to be communicated between the recursive calls. Hint: In C, C++,
 * and Java, probably the best solution is to create a recursive helper
 * function printPathsRecur(node, int path[], int pathLen), where the path
 * array communicates the sequence of nodes that led up to the current call.
 * Alternately, the problem may be solved bottom-up, with each node returning
 * its list of paths. This strategy works quite nicely in Lisp, since it can
 * exploit the built in list and mapping primitives. (Thanks to Matthias
 * Felleisen for suggesting this problem.)
 *
 * Given a binary tree, print out all of its root-to-leaf paths, one per line.
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

void printPathsRecur(struct node* node, int path[], int pathLen) {
    if (node == NULL) {
        return;
    }

    path[pathLen] = node->data;
    pathLen++;

    if (node->left == NULL && node->right == NULL) {
        for (int i = 0; i < pathLen; i++) {
            printf("%d ", path[i]);
        }
        printf("\n");
    }

    printPathsRecur(node->left, path, pathLen);
    printPathsRecur(node->right, path, pathLen);
}

void printPaths(struct node* node) {
    int path[100];
    printPathsRecur(node, path, 0);

}

int main(int argc, char* argv[]) {
    struct node* root = buildBSTree();
    printPaths(root);
}
