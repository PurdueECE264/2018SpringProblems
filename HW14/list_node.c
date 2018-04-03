#include "list_node.h"

// Create the list node from treenode as input
#ifndef LIST_CREATE
ListNode * ListNodeCreate(TreeNode * treenode){
  return NULL;
}

#endif

#ifndef LIST_BUILD
ListNode * ListBuild(CharFreq * freqArray){
  // find the first index with non-zero frequency
  // if all are character have zero freq then return nothing
  ListNode * head = NULL;
  // build the linked list such that lower frequency comes first and then higher
  return head;
}
#endif




#ifndef LIST_INSERT

ListNode * ListInsert(ListNode * head, ListNode * listNode){
  // insert such that lower frequency comes before the already inserted frequency
  // if the frequencies are same for the nodes, then inserted node should come after the compared node
  return head;

}

#endif

#ifndef LIST_CLEAN

void CleanList(ListNode *head){
  // clean the ListNode
}

#endif

#ifndef HUFFMAN_BUILD
// builds the huffman tree from the linked list
ListNode * BuildHuffmanTree(ListNode *head){
  return NULL;
}

#endif
