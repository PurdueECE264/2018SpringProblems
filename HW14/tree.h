/*************** DO NOT MODIFY THIS FILE **********************/
#ifndef TREE_H
#define TREE_H
#include <stdlib.h>
#include <stdio.h>
#define HUFF_ELEM '#'
typedef struct TreeNode {
  // One of the input characters
  unsigned char data;
  // Frequency of the character
  int freq;
  // Left and right child of this node
  struct TreeNode *left;
  struct TreeNode *right;

} TreeNode ;

void PrintSingleHelper(TreeNode *treeNode);

TreeNode * TreeNodeCreate(unsigned char val, int freq);
TreeNode * TreeMerge(TreeNode * treenode1, TreeNode * treenode2);
void PrefixTreePrint(TreeNode *treeNode, int level);
void CleanTree(TreeNode *treeNode);

#endif
