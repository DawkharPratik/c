//Create a Binary Search Tree & Display Nodes level wise

#include<stdio.h>
#include<stdlib.h>
#define MAX 20
struct Btree
 {
	struct Btree *lchild;
	int data;
	struct Btree *rchild;
 };
 
typedef struct Btree BNODE;

struct Queue
{
 	struct Btree *Q[MAX];
 	int front,rear;
};
typedef struct Queue QUEUE;

void Addq(QUEUE *q,BNODE *t)
{
	q->Q[++q->rear]=t;
}

BNODE * Delq(QUEUE *q)
{
   	return(q->Q[++q->front]);
}

int isempty(QUEUE *q)
{
	if(q->front==q->rear)
		return 1;
	else
		return 0;
}

void LevelDisp(BNODE *h)
{
   	QUEUE q;
   	BNODE *temp;
   	int total=0,cnt=0,level=0;
   	q.front=q.rear=-1;
   	temp=h;

   	Addq(&q,temp);
   	Addq(&q,NULL);
   	while(!isempty(&q))
   	{
		temp=Delq(&q);
		if(temp==NULL)
		{
			if(!isempty(&q))
			{
				printf(" = %d Level-%d\n",cnt,level);
				cnt=0;
				level++;
				Addq(&q,NULL);
			}
		}
		else
		{
			total++;
			cnt++;
			printf("%d ",temp->data);
			if(temp->lchild!=NULL)
				Addq(&q,temp->lchild);
			if(temp->rchild!=NULL)
				Addq(&q,temp->rchild);
		}
   	}
   	printf("=%d Level-%d\n",cnt,level);
   	printf("\nTotal Nodes:%d",total);
   	printf("\nTotal Levels:%d\n",level+1);
 }

BNODE* newNode(int data)
{
	BNODE* node = (BNODE*)malloc(sizeof(BNODE));
	node->data = data;
	node->lchild = NULL;
	node->rchild = NULL;

	return(node);
}

void main()
{
	BNODE *header = newNode(100);
	header->lchild = newNode(50);
	header->rchild = newNode(200);
	header->rchild->lchild=newNode(150);
	header->lchild->lchild = newNode(20);
	header->lchild->rchild = newNode(80);
	header->lchild->rchild->lchild = newNode(70);
    	LevelDisp(header);
}
//2nd
//C Program to sort an array based on heap sort algorithm(MAX heap)
#include <stdio.h>
void main()
{
    int heap[10], no, i, j, c, root, temp;
    printf("\n Enter no of elements :");
    scanf("%d", &no);
    printf("\n Enter the nos : ");
    for (i = 0; i < no; i++)
       scanf("%d", &heap[i]);
    for (i = 1; i < no; i++)
    {
        c = i;
        do
        {
            root = (c - 1) / 2;             
            if (heap[root] < heap[c])   /* to create MAX heap array */
            {
                temp = heap[root];
                heap[root] = heap[c];
                heap[c] = temp;
            }
            c = root;
        } while (c != 0);
    }
 
    printf("Heap array : ");
    for (i = 0; i < no; i++)
        printf("%d\t ", heap[i]);
    for (j = no - 1; j >= 0; j--)
    {
        temp = heap[0];
        heap[0] = heap[j];    /* swap max element with rightmost leaf element */
        heap[j] = temp;
        root = 0;
        do 
        {
            c = 2 * root + 1;    /* left node of root element */
            if ((heap[c] < heap[c + 1]) && c < j-1)
                c++;
            if (heap[root]<heap[c] && c<j)    /* again rearrange to max heap array */
            {
                temp = heap[root];
                heap[root] = heap[c];
                heap[c] = temp;
            }
            root = c;
        } while (c < j);
    } 
    printf("\n The sorted array is : ");
    for (i = 0; i < no; i++)
       printf("\t %d", heap[i]);
}