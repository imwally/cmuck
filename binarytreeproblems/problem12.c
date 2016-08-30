/*
 * Problem 12 - countTrees()
 * 
 * Suppose you are building an N node binary search tree with the
 * values 1..N. How many structurally different binary search trees
 * are there that store those values? Write a recursive function that,
 * given the number of distinct values, computes the number of
 * structurally unique binary search trees that store those
 * values. For example, countTrees(4) should return 14, since there
 * are 14 structurally unique binary search trees that store 1, 2, 3,
 * and 4. The base case is easy, and the recursion is short but
 * dense. Your code should not construct any actual trees; it's just a
 * counting problem.
 */

#include <stdio.h>

// Compute unique trees of 1 ... n number of nodes.
int countTrees(int numKeys) {
  if (numKeys == 1) {
    return 1;
  }

  // Use catalan number formula.
  return 2 * (2 * numKeys - 1) * countTrees(numKeys - 1) / (1 + numKeys);
}

int main(int argc, char* argv[]) {
  printf("%d\n", countTrees(4));
}
