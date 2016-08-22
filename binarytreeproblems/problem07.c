/*
 * Problem 7 - hasPathSum()
 *
 * We'll define a "root-to-leaf path" to be a sequence of nodes in a tree
 * starting with the root node and proceeding downward to a leaf (a node with
 * no children). We'll say that an empty tree contains no root-to-leaf paths.
 * 
 * For this problem, we will be concerned with the sum of the values of such a
 * path -- for example, the sum of the values on the 5-4-11-7 path is 5 + 4 +
 * 11 + 7 = 27.
 *
 * Given a binary tree and a sum, return true if the tree has a root-to-leaf
 * path such that adding up all the values along the path equals the given sum.
 * Return false if no such path can be found. (Thanks to Owen Astrachan for
 * suggesting this problem.)
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

int hasPathSum(struct node* node, int sum) {
    if (node == NULL) {
        return 0;
    }

    if (node->left == NULL && node->right == NULL) {
        return sum == node->data;
    }
 
    return hasPathSum(node->right, sum - node->data) ||
            hasPathSum(node->left, sum - node->data);
}

int main(int argc, char* argv[]) {
    struct node* root = buildBSTree();

    int sum = 9;
    int sumPath = hasPathSum(root, sum);

    if (sumPath) {
        printf("tree has sum path of %d\n", sum);
    } else {
        printf("no sum path of %d found\n", sum);
    }
}
