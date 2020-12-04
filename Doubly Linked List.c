#include<stdio.h>
#include<stdlib.h>

struct Node
{
	struct Node *prev;
	int data;
	struct Node *next;
}*first=NULL;

void Create(int A[], int n)
{
	struct Node *t, *last;
	int i;
	
	first=(struct Node *)malloc(sizeof(struct Node));
	first->data=A[0];
	first->prev=first->next=NULL;
	last=first;
	
	for(i=1;i<n;i++)
	{
		t=(struct Node *)malloc(sizeof(struct Node));
		t->data=A[i];
		t->next=last->next;
		t->prev=last;
		last->next=t;
		last=t;
	}
}

void Display(struct Node *p)
{
	while(p)
	{
		printf("%d ", p->data);
		p=p->next;
	}
	printf("\n");
}

int Length(struct Node *p)
{
	int len=0;
	while(p)
	{
		len++;
		p=p->next;
	}
	return len;
}

int Insert(struct Node *p, int index, int x)
{
	struct Node *t;
	int i;
	
	if(index<0 || index>Length(p))
		return;
	if(index==0)
	{
		t=(struct Node *)malloc(sizeof(struct Node));
		t->data=x;
		t->prev=NULL;
		t->next=first;
		first->prev=t;
		first=t;
	}
	else
	{
		for(i=0;i<index-1;i++)
			p=p->next;
		t=(struct Node *)malloc(sizeof(struct Node));
		t->data=x;
		
		t->prev=p;
		t->next=p->next;
		if(p->next!=NULL) p->next->prev=t;
		p->next=t;
	}
}

int Delete(struct Node *p, int index)
{
	struct Node *q;
	int x=-1, i;
	
	if(index<1 || index>Length(p))
		return;
	if(index==1)
	{
		p=first;
		first=first->next;
		if(first!=NULL) first->prev=NULL;
		
		x=p->data;
		free(p);
	}
	else
	{
		for(i=0;i<index-1;i++)
			p=p->next;
		p->prev->next=p->next;
		if(p->next!=NULL) p->next->prev=p->prev;
		x=p->data;
		free(p);
	}
	return x;
}

void Reverse(struct Node *p)
{
	struct Node *temp;
	while(p!=NULL)
	{
		temp=p->next;
		p->next=p->prev;
		p->prev=temp;
		
		p=p->prev;
		if(p!=NULL && p->next==NULL)
			first=p;
	}
}

int main()
{
	int A[]={2,4,6,8,10};
	Create(A, 5);
	Display(first);
	printf("\nLength of DLL: %d\n", Length(first));
	
	printf("\nInsert after- 2nd index:\n");
	Insert(first,2,5);
	Display(first);
	
	printf("\nDelete at 3nd index:\n");
	Delete(first,3);
	Display(first);
	
	printf("\nReversing DLL:\n");
	Reverse(first);
	Display(first);
	printf("\nAgain Reversing DLL:\n");
	Reverse(first);
	Display(first);
	
	return 0;
}
