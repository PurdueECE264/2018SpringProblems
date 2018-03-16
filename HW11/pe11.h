struct node
{
	struct node * next;
	int value;
}nodeType;

void print(struct node** head);

void insertFirst(struct node** head,struct node * n);

void insertAt(struct node** head,struct node * n,int index);

void insertLast(struct node** head,struct node *n);

void deleteFirstMatch(struct node**head,int value);

void deleteAt(struct node** head,int index);

void deleteAllMatches(struct node** head,int value);

int getLength(struct node** head);

void freeMemory(struct node** head);


