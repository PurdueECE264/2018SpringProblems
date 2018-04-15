#include "tree.h"

#ifndef USIGN_TO_BIN
// function to create binary values from the input char values
char * UnSig2Bin(unsigned char value) {
    // determine the number of bits needed ("sizeof" returns bytes)
	// create mask which you would use for the getting each bit value
	// for loop to mast values and creating char array of bits
    
}

#endif

#ifndef WRITE_BINARY

// WriteInOrderBinary takes root and file * as input
// and creates binary representation of the tree as specified in the example
int WritePreOrderBinary(TreeNode * root, FILE *outptr){
  return EXIT_SUCCESS;
}

int CreateBinaryFromTree(TreeNode * root, const char *outfile){
  return ret;
}

#endif





#ifndef CLEAN_TREE

void CleanTree(TreeNode * root){
}
#endif





#ifndef BINARY_SEARCH_TREE

int IntCompare(const void * val1, const void * val2){
  return (*(unsigned char*)val1 - *(unsigned char*)val2);
}

TreeNode * CreateBinarySearchTree(long randomSeed, long numNodes){
  unsigned char * binArray = malloc(sizeof(unsigned char)*numNodes);
  if(binArray == NULL){
    printf("Memory allocation to array failed\n" );
    return NULL;
  }
  srand(randomSeed);
  // allocate values to array
  for(int index = 0; index < numNodes ; index++){
    binArray[index] = rand() % 256;
  }
  // sort the array
  qsort(binArray, numNodes, sizeof(unsigned char), IntCompare);

  // create bst from the sorted array
  TreeNode * root = CreateBST(binArray, 0, numNodes-1);
  free(binArray);
  return root;

}
// TreeNode *CreateBSTHelper()
TreeNode* CreateTreeNode(unsigned char value){
  TreeNode *newNode = malloc(sizeof(TreeNode));
  newNode->data = value;
  newNode->leftChild = NULL;
  newNode->rightChild = NULL;
  return newNode;
}

TreeNode *CreateBST(unsigned char *sortedArray, int start , int end){
  // int len = sizeof(sortedArray)/sizeof(int);
  if(start > end) return NULL;
  int mid = (start+end)/2;
  TreeNode *newNode = CreateTreeNode(sortedArray[mid]);
  newNode->leftChild = CreateBST(sortedArray, start, mid -1);
  newNode->rightChild = CreateBST(sortedArray, mid +1, end);
  return newNode;

}
#endif
