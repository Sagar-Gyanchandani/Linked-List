#include<stdio.h>
#include<stdlib.h>
#define INT32_MIN -32576

struct Node
{
	int data;
	struct Node *next;
}*first=NULL,*second=NULL,*third=NULL;

void create(int A[], int n)
{
	int i;
	struct Node *t,*last;
	first=(struct Node *)malloc(sizeof(struct Node));
	first->data=A[0];
	first->next=NULL;
	last=first;
	
	for(i=1;i<n;i++)
	{
		t=(struct Node *)malloc(sizeof(struct Node));
		t->data=A[i];
		t->next=NULL;
		last->next=t;
		last=t;
	}
}
void create2(int A[], int n)
{
	int i;
	struct Node *t,*last;
	second=(struct Node *)malloc(sizeof(struct Node));
	second->data=A[0];
	second->next=NULL;
	last=second;
	
	for(i=1;i<n;i++)
	{
		t=(struct Node *)malloc(sizeof(struct Node));
		t->data=A[i];
		t->next=NULL;
		last->next=t;
		last=t;
	}
}



void Display(struct Node *p)
{
	while(p!=NULL)
	{
		printf("%d ", p->data);
		p=p->next;
	}
}
void RecursiveDisplay(struct Node *p)
{
	if(p!=NULL)
	{
		printf("%d ", p->data);
		RecursiveDisplay(p->next);
	}
}

int count(struct Node *p)
{
	int l=0;
	while(p)
	{
		l++;
		p=p->next;
	}
	return l;
}
int RecCount(struct Node *p)
{
	if(p!=NULL)
		return RecCount(p->next)+1;
	else
		return 0;
}

int sum(struct Node *p)
{
	int s=0;
	while(p!=NULL)
	{
		s+=p->data;
		p=p->next;
	}
	return s;
}
int RecSum(struct Node *p)
{
	int s=0;
	if(p!=NULL)
		return p->data+RecSum(p->next);
	else
		return 0;
}

int Max(struct Node *p)
{
	int max=INT32_MIN;
	while(p!=NULL)
	{
		if(p->data>max)
			max=p->data;
		p=p->next;
	}
	return max;
}
int RecMax(struct Node *p)
{
	int x=0;
	
	if(p==NULL)
		return INT32_MIN;
	x=RecMax(p->next);
	if(x>p->data)
		return x;
	else 
		return p->data;
}

struct Node * LinearSearch(struct Node *p, int key)
{
	while(p!=NULL)
	{
		if(key==p->data)
			return p;
		p=p->next;	
	}
	return NULL;
}
struct Node * RecursiveSearch(struct Node *p, int key)
{
	if(p==NULL)
		return NULL;
	if(key==p->data)
		return p;
	return RecursiveSearch(p->next, key);
}
struct Node * ImprovedLinearSearch(struct Node *p, int key)
{
	struct Node *q;
	
	while(p!=NULL)
	{
		if(key==p->data)
		{
			q->next=p->next;
			p->next=first;
			first=p;
			return p;
		}
		q=p;
		p=p->next;	
	}
	return NULL;
}

void Insert(struct Node *p, int index, int x)
{
	int i;
	struct Node *t;
	if(index < 0 || index > count(p))
		return;
	t = (struct Node *)malloc(sizeof(struct Node));
	t->data=x;
	
	if(index==0)
	{
		t->next=first;
		first=t;
	}
	else
	{
		for(i=0;i<index-1;i++)
			p=p->next;
		t->next=p->next;
		p->next=t;
	}
}

void SortedInsert(struct Node *p, int x)
{
	struct Node *t, *q=NULL;
	t=(struct Node*)malloc(sizeof(struct Node));
	t->data=x;
	t->next=NULL;
	
	if(p==NULL)
		first=t;
	else
	{
		while(p && p->data<x)
		{
			q=p;
			p=p->next;
		}
		if(p==first)
		{
			t->next=first;
			first=t;
		}
		else
		{
			t->next=q->next;
			q->next=t;
		}
	}
}

int Delete(struct Node *p, int index)
{
	struct Node *q=NULL;
	int x=-1,i;
	
	if(index < 1 || index>count(p))
		return -1;
	if(index==1)
	{
		q=first;
		x=first->data;
		first=first->next;
		free(q);
		return x;
	}
	else
	{
		for(i=0;i<index-1;i++)
		{
			q=p;
			p=p->next;
		}
		q->next=p->next;
		x=p->data;
		free(p);
		return x;
	}
}

int isSorted(struct Node *p)
{
	int x=INT32_MIN;
	
	while(p!=NULL)
	{
		if(p->data < x)
			return 0;
		x=p->data;
		p=p->next;
	}
	return 1;
}

void RemoveDuplicate(struct Node*p)
{
	struct Node *q=p->next;
	while(q!=NULL)
	{
		if(p->data!=q->data)
		{
			p=q;
			q=q->next;
		}
		else
		{
			p->next=q->next;
			free(q);
			q=p->next;
		}
	}
}

void Reverse1(struct Node *p)
{
	int *A,i;
	struct Node *q=p;
	
	A=(int *)malloc(sizeof(int)*count(p));
	
	while(q!=NULL)
	{
		A[i]=q->data;
		q=q->next;
		i++;
	}
	q=first;
	i--;
	while(q!=NULL)
	{
		q->data=A[i];
		q=q->next;
		i--;
	}
}

void Reverse2(struct Node *p)
{
	struct Node *q=NULL, *r=NULL;
	
	while(p!=NULL)
	{
		r=q;
		q=p;
		p=p->next;
		q->next=r;
	}
	first=q;
}

void Concat(struct Node *p, struct Node *q)
{
	third=p;
	
	while(p->next!=NULL)
		p=p->next;
	p->next=q;
}

void Merge(struct Node *p, struct Node *q)
{
	struct Node *last;
	if(p->data < q->data)
	{
		third=last=p;
		p=p->next;
		third->next=NULL;
	}
	else
	{
		third=last=q;
		q=q->next;
		third->next=NULL;	
	}
	while(p && q)
	{
		if(p->data)
	}
}

void Reverse3(struct Node *q, struct Node *p)
{
	if(p!=NULL)
	{
		Reverse3(p,p->next);
		p->next=q;
	}
	else
	{
		first=q;
	}
}

int main()
{
	int A[]={3,5,7,10,15};
	int B[]={1,4,6,8,12};
	struct Node *temp;
	
	create(A,5);
	printf("First LL: ");
	Display(first);
	printf("\n");
	printf("Second LL: ");
	create2(B,5);
	Display(second);
	printf("\n");
	
	printf("\nConcatenated LL: ");
	Concat(first, second);
	Display(third);
	printf("\n\n");
	
	
	RecursiveDisplay(first);
	printf("\nLength of Linked List is %d", count(first));
	printf("\nLength of Linked List using Recursion is %d", RecCount(first));
	printf("\nSum of Linked List %d", sum(first));
	printf("\nSum of Linked List using Recursion is %d", RecSum(first));
	printf("\nMaximum Number in Linked List is %d", Max(first));
	printf("\nMaximum Number in Linked List using Recursion %d", RecMax(first));
	
	// Linear Search
	temp = LinearSearch(first,15);
	if(temp)
		printf("\nKey is Found: %d is the Key.", temp->data);
	else
		printf("\nKey not Found\n");
	
	// Recursive Search
	temp = RecursiveSearch(first,15);
	if(temp)
		printf("\nKey is Found using Recursion: %d is the Key.", temp->data);
	else
		printf("\nKey not Found\n");
	
	// Improved Linear Search
	temp = ImprovedLinearSearch(first,15);
	if(temp)
		printf("\nKey is Found using Improved Linear Search Method: %d is the Key.\n", temp->data);
	else
		printf("\nKey not Found\n");
	printf("\nDisplaying Linked List after Improved Linear Search Key element comes at first.\n");
	RecursiveDisplay(first);


	// Insert Fxn
	Insert(first,0,2);
	printf("\nDisplaying Linked List after Inserting element at first pos.\n");
	Display(first);
	Insert(first,6,40);
	printf("\nDisplaying Linked List after Inserting element after 3 pos.\n");
	Display(first);

	if(isSorted(first))
		printf("\n\nLinked List is Sorted\n");
	else
		printf("\n\nLinked List is Not Sorted\n");
	

	printf("\nDisplaying Linked List after Element element at 2 pos.\n");
	Delete(first,2);
	Display(first);

	if(isSorted(first))
		printf("\n\nLinked List is Sorted\n");
	else
		printf("\n\nLinked List is Not Sorted\n");
	
	Insert(first,0,2);
	printf("\nDisplaying Linked List after Inserting element at first pos.\n");
	Display(first);
	
	printf("\n\nRemoving Duplicate elements from LinkedList using RemovingDuplicate function:\n");
	RemoveDuplicate(first);
	Display(first);
	
	printf("\n\nReversing elements of LinkedList using Auxilary Array:\n");
	Reverse1(first);
	Display(first);
	printf("\n\nReversing elements of LinkedList using Sliding Pointer:\n");
	Reverse2(first);
	Display(first);
	printf("\n\nReversing elements of LinkedList using Recursion:\n");
	Reverse3(NULL,first);
	Display(first);
	

	
	return 0;
	
	
}
