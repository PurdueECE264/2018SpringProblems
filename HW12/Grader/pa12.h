#ifndef PA12_H_
#define PA12_H_

struct node
{
	struct node * next;
	int value;
}nodeType;

struct dnode
{
	struct dnode * next;
	struct dnode * prev;
	int value;
}dnodeType;


void init(struct node **head,int length);
void print(struct node **head);
void josp(struct node ** head,int k,int p,int length);
void init2(struct dnode ** head,int length);
void print2(struct dnode ** head);
void josp2(struct dnode **head, int k, int q,int length);

#endif
