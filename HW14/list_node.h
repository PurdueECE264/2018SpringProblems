#ifndef LIST_NODE_H
#define LIST_NODE_H
#include <stdbool.h>
#include "frequency.h"
#include "tree.h"



// A Min Heap:  Collection of min heap (or Hufmman tree) nodes
typedef struct ListNode {
    // next pointer to the list
    struct ListNode *next;
    // Tree Node pointer as the value
    TreeNode *treeNodePtr;

} ListNode;


// builds the linked list with lower frequencies at the front
ListNode * ListBuild(CharFreq * freqArray);

// creates as single list node
ListNode * ListNodeCreate(TreeNode * treeNode);

// inserts a single node(listNode) in the given linked list (head)
ListNode * ListInsert(ListNode * head, ListNode * listNode);

// clean function to clean memory
void CleanList(ListNode *head);

// building huffman tree
ListNode * BuildHuffmanTree(ListNode *head);
// void PrintListBuild(ListNode *head);

#endif
