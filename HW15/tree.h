#ifndef TREE_HEADER
#define TREE_HEADER

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define NUM_BITS 8

typedef struct TreeNode {
  unsigned char data;
  struct TreeNode *leftChild;
  struct TreeNode *rightChild;
} TreeNode;


TreeNode * CreateBinarySearchTree(long randomSeed, long numNodes);


int CreateBinaryFromTree(TreeNode * root, const char *outfile);

int WritePreOrderBinary(TreeNode * root, FILE *outptr);
char * UnSig2Bin(unsigned char value);

TreeNode* CreateTreeNode(unsigned char value);
TreeNode *CreateBST(unsigned char *sortedArray, int start , int end);

void CleanTree(TreeNode * root);

void PrintTreeInorder(TreeNode *root);
void PrintTreePostorder(TreeNode *root);

#endif
