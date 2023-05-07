//program of binary search
#include<stdio.h>
#include"btree.h"
#include<stdlib.h>
void main()
{
    struct bst *root=NULL,*temp,*copyroot,*mirrorroot;
    int ch,n,i,val,x;
    printf("\n1.create");
    printf("\n2.insert");
    printf("\n3.preorder");
    printf("\n4.inorder");
    printf("\n5.postorder");
    printf("\n6.search");
    printf("\n7.no.of leaf");
    printf("\n8.no.of nonleaf");
    printf("\n9.no.of Node");
    printf("\n10.copy tree");
    printf("\n11.delete");
    printf("\n12.mirror tree");
    printf("\n13.compare");
    printf("\n14.sum of even node");
    printf("\n15.sum of odd node");
    printf("\n16.exit");
    while(1){
        printf("\nenter your choice :");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: 
            root=NULL;
            printf("\nenter number of node:");
            scanf("%d",&n);
            for(i=1;i<=n;i++)
            {
                printf("\nenter data for node %d :",i);
                scanf("%d",&val);
                root=create(root,val);
            }
            break;
            case 2:
            printf("\nenter the data to insert:");
            scanf("%d",&val);
            root=insert(root,val);
            break;
            case 3:preorder(root);
            break;
            case 4:inorder(root);
            break;
            case 5:postorder(root);
            break;
            case 6:printf("\nenter number to search:");
            scanf("%d",&val);
            temp=search(root,val);
            if(temp==NULL)
            printf("\n%d is not found",val);
            else
            printf("\n%d is found",val);
            break;
            case 7:
            x=CountLeaf(root);
            printf("\nleaf node in the trees are:  %d",x);
            break;
            case 8:
            x=countNonLeaf(root);
            printf("\nNon leaf node in the trees are:  %d",x);
            break;
            case 9:
            x=CountNode(root);
            printf("\nall node in the trees are:  %d",x);
            break;
            case 10:
            copyroot=(struct bst *)malloc(sizeof(struct bst));
            copyroot->lchild=NULL;
            copyroot->rchild=NULL;
            copytree(root,copyroot);
            inorder(copyroot);
            break;
            case 11:
            printf("\nenter thr node to be deleted");
            scanf("%d",&val);
            root=delete(root,val);
            break;
            case 12:
            mirrorroot=(struct bst*)malloc(sizeof(struct bst));
            mirrorroot->lchild=NULL;
            mirrorroot->rchild=NULL;
            mirror(root,mirrorroot);
            inorder(mirrorroot); 
            break;
            case 13:i=compare(root,copyroot);
            if(i==1)
            printf("\ntree is equal");
            else
            printf("\ntree is not equal");
            break;
            case 14:x=sumeven(root);
            printf("\nsum of even node: %d",x);
            break;
            case 15:x=sumodd(root);
            printf("\nsum of odd node: %d",x);
            break;
            case 16:exit(0);
            default:
            printf("\nenter valid choice");
            break;
        }
    }
}

#include<stdio.h>
#include<stdlib.h>
struct bst
{
    int data;
    struct bst *lchild,*rchild;
};
int addeven=0,addodd=0,rcnt=0,lcnt=0,nlcnt=0;
struct bst *create(struct bst *root,int val)
{
    if(root == NULL)
    {
        root=(struct bst *)malloc(sizeof(struct bst));
        root->lchild=root->rchild=NULL;
        root->data=val;
        return root;
    }
    else
    {
        if(val<root->data)
            root->lchild=create(root->lchild,val);
        else if(val>root->data)
            root->rchild=create(root->rchild,val);
        else
            printf("\ndublicate number not allow");
        return(root);
    }
}
struct bst *insert(struct bst *root,int key)
{
    if(root==NULL)
    {
        root=(struct bst*)malloc(sizeof(struct bst));
        root->data=key;
        root->lchild=root->rchild=NULL;
        return(root);
    }
    if(key<root->data)
    root->lchild=insert(root->lchild,key);
    else
    root->rchild=insert(root->rchild,key);
    return root;
}
void preorder(struct bst *root)
{
    if(root != NULL)
    {
        printf("%d ",root->data);
        preorder(root->lchild);
        preorder(root->rchild);
    }
}
void inorder(struct bst *root)
{
    if(root != NULL)
    {
        inorder(root->lchild);
        printf("%d ",root->data);
        inorder(root->rchild);
    }
}
void postorder(struct bst *root)
{
    if(root != NULL)
    {
        postorder(root->lchild);
        postorder(root->rchild);
        printf("%d ",root->data);
    }
}
int CountNode(struct bst *root)
{
    if(root!=NULL)
    {
        rcnt++;
        CountNode(root->lchild);
        CountNode(root->rchild);
    }
    return rcnt;
}

int CountLeaf(struct bst *root)
{
    if(root!=NULL)
    {
        if(root->lchild==NULL && root->rchild==NULL)
        lcnt++;
        CountLeaf(root->lchild);
        CountLeaf(root->rchild);
    }
    return lcnt;
}
int countNonLeaf(struct bst *root)
{
    if(root!=NULL)
    {
        if(root->lchild!=NULL || root->rchild!=NULL)
        nlcnt++;
        countNonLeaf(root->lchild);
        countNonLeaf(root->rchild);
    }
    return nlcnt;
}

struct bst *search(struct bst *root,int data)
{
    if(root==NULL)
    {
        return(NULL);
    }
    if(root->data==data)
    {
        return(root);
    }
    else if(data<root->data)
    return(search(root->lchild,data));
    else
    return(search(root->rchild,data));
}
void copytree(struct bst *root,struct bst *copyroot)
{
    if(root==NULL)
    return;
    copyroot->data=root->data;
    if(root->lchild)
    {
        copyroot->lchild=(struct bst*)malloc(sizeof(struct bst));
        copyroot->lchild->lchild=NULL;
        copyroot->lchild->rchild=NULL;
        copytree(root->lchild,copyroot->lchild);
    }
    if(root->rchild)
    {
        copyroot->rchild=(struct bst*)malloc(sizeof(struct bst));
        copyroot->rchild->lchild=NULL;
        copyroot->rchild->rchild=NULL;
        copytree(root->rchild,copyroot->rchild);
    }
}
struct bst *min1(struct bst *root)
{
    struct bst *copyroot=root;
    while(copyroot&&copyroot->lchild!=NULL)
    {
        copyroot=copyroot->lchild;
    }
    return copyroot;
}
struct bst *delete(struct bst *root,int data)
{
    if(root==NULL)
    return root;
    if(data<root->data)
    root->lchild=delete(root->lchild,data);
    else if(data>root->data)
    root->rchild=delete(root->rchild,data);
    else
    {
        if(root->lchild==NULL)
        {
            struct bst *temp=root->rchild;
            free(root);
            return temp;
        }
        else if(root->rchild==NULL)
        {
            struct bst *temp=root->lchild;
            free(root);
            return temp;
        }
        struct bst *temp=min1(root->rchild);
        root->data=temp->data;
        root->rchild=delete(root->rchild,data);
    }
    return root;
}
void mirror(struct bst *r,struct bst *copyroot)
{
    if(r==NULL)
        return ;
    copyroot->data=r->data;
    if(r->lchild)
    {
        copyroot->rchild=(struct bst *)malloc(sizeof(struct bst));
        copyroot->rchild->lchild=NULL;
        copyroot->rchild->rchild=NULL;
        mirror(r->lchild,copyroot->rchild);
    }    
    if(r->rchild)
    {
        copyroot->lchild=(struct bst*)malloc(sizeof(struct bst));
        copyroot->lchild->lchild=NULL;
        copyroot->lchild->rchild=NULL;
        mirror(r->rchild,copyroot->lchild);
    }
}
int compare(struct bst *r,struct bst *copyroot)
{
    if(r==NULL && copyroot==NULL)
    return 1;
    if(r==NULL || copyroot==NULL)
    return 0;
    if(compare(r->lchild,copyroot->lchild)&&compare(r->rchild,copyroot->rchild)&&r->data==copyroot->data)
    return 1;
    else
    return 0;
}
int sumeven(struct bst *root)
{
    if(root!=NULL)
    {
        if(root->data%2==0)
        addeven=addeven+root->data;
        sumeven(root->lchild);
        sumeven(root->rchild);
    }
    return addeven;
}
int sumodd(struct bst *root)
{
    if(root!=NULL)
    {
        if(root->data%2!=0)
        addodd=addodd+root->data;
        sumodd(root->lchild);
        sumodd(root->rchild);
    }
    return addodd;
}


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



//C Program to sort an array based on heap sort algorithm(MAX heap)
#include <stdio.h>
void main()
{
    int heap[10], n, i, j, c, root, temp;
    printf("\n Enter no of elements :");
    scanf("%d", &n);
    printf("\n Enter the nos : ");
    for (i = 0; i < n; i++)
        scanf("%d", &heap[i]);
    for (i = 1; i < n; i++)
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
    for (i = 0; i < n; i++)
        printf("%d\t ", heap[i]);
    for (j = n - 1; j >= 0; j--)
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
    for (i = 0; i < n; i++)
    printf("\t %d", heap[i]);
}

//Read a graph as adjacency matrix and and print it
#include<stdio.h>
int mat[5][5];
void display();
int main()
{
    int i, j,n;
    char reply;
    printf("How many vertices:");
    scanf("%d",&n);//n=4
    for ( i = 0 ; i < n ; i++ )
    {
        for ( j = 0 ; j < n ; j++ )
        {
            printf("\n Is there edge between %d & %d ? (Y/N) :",i+1,j+1);
            scanf(" %c", &reply);
            if ( reply == 'y' || reply == 'Y' )
                mat[i][j] = 1;
            else
                mat[i][j] = 0;
        }
    } 
    display(n);
    return 0;
}

void display(int size)
{
    int i,j;
    printf("\n--------------------------------------------------------------------\n");
    printf("\nAdjecency Matrix is:\n\n");
    for(i=0;i<size;i++)
    {
        for(j=0;j<size;j++)
        {
            printf("%d\t",mat[i][j]);
        }
        printf("\n");
    }
}



//Read a graph as adjacency matrix and and print it and find
//out indegree,outdegree and total degree of each node
#include<stdio.h>
int mat[10][10];
void display(int);
void degree(int);
int main()
{
    int i, j,n;
    char reply;
    printf("How many vertices:");
    scanf("%d",&n);
    for ( i = 0 ; i < n ; i++ )
    {
        for ( j = 0 ; j < n ; j++ )
        {
            printf("\n Is there edge between %d & %d ? (Y/N) :",i+1,j+1);
            scanf(" %c", &reply);
            if ( reply == 'y' || reply == 'Y' )
                mat[i][j] = 1;
            else
                mat[i][j] = 0;
        }
    }
    display(n);
    degree(n);
    return 0;
}

void display(int size)
{
    int i,j;
    printf("\n--------------------------------------------------------------------\n");
    printf("\nAdjecency Matrix is:\n\n");
    for(i=0;i<size;i++)
    {
        for(j=0;j<size;j++)
        {
            printf("%d\t",mat[i][j]);
        }
        printf("\n");
    }
}

void degree(int n)
{
    int i,j,indegree=0,outdegree=0;
    for (i = 0; i < n ; i++ )//i=0 0<4T
    {
        for(j=0;j<n;j++)//j=0 0<4T
        {
            if (mat[i][j]==1)
                outdegree++;
            if (mat[j][i]==1)
                indegree++;
        }
        printf("\nIndegree, Outdegree and Total Degree of vertex %d is %d, %d, %d",i+1,indegree,outdegree,indegree+outdegree);  
        indegree=0;
        outdegree=0;
    } // for
    printf("\n\n");
}



//adjacency matrix BFS
#include<stdio.h>
#include<stdlib.h>

#define MAX 100  

#define initial 1
#define waiting 2
#define visited 3

int n;    
int mat[MAX][MAX];
int state[MAX]; 
void accept();
void BF_Traversal();
void BFS(int v);

int queue[MAX], front = -1,rear = -1;
void insert_queue(int vertex);
int delete_queue();
int isEmpty_queue();

int main()
{
    accept();
    BF_Traversal();
    return 0;
}

void accept()
{
    int i, j;
    char reply;
    printf("How many vertices:");
    scanf("%d",&n);
    for ( i = 0 ; i < n ; i++ )
    {
        for ( j = 0 ; j < n ; j++ )
        {
            printf("\n Is there edge between %d & %d ? (Y/N/y/n) :",i,j);
            scanf(" %c", &reply);
            if ( reply == 'y' || reply == 'Y' )
                mat[i][j] = 1;
            else
                mat[i][j] = 0;
        }
    } 
}

void BF_Traversal()
{
    int v;
    
    for(v=0; v<n; v++) 
        state[v] = initial;
    
    printf("\nEnter Start Vertex for BFS: ");
    scanf("%d", &v);
    printf("\nBFS Traversal is: ");
    BFS(v);
    printf("\n\n");
}

void BFS(int v)
{
    int i;
    
    insert_queue(v);
    state[v] = waiting;
    
    while(!isEmpty_queue())
    {
        v = delete_queue( );
        printf("%d ",v);
        state[v] = visited;
        
        for(i=0; i<n; i++)
        {
            if(mat[v][i] == 1 && state[i] == initial) 
            {
                insert_queue(i);
                state[i] = waiting;
            }
        }
    }
    printf("\n");
}

void insert_queue(int vertex)
{
    if(front == -1) 
        front = 0;
    rear = rear+1;
    queue[rear] = vertex ;
}

int isEmpty_queue()
{
    if(front == -1 || front > rear)
        return 1;
    else
        return 0;
}

int delete_queue()
{
    int delete_item;
    delete_item = queue[front];
    front = front+1;
    return delete_item;
}


//adjacency matrix DFS
#include<stdio.h>
void DFS(int);
int mat[10][10],visited[10],n;
void main()
{
    int i,j,v;
    char reply;
    printf("How many vertices:");
    scanf("%d",&n);
    for ( i = 0 ; i < n ; i++ )
    {
    for ( j = 0 ; j < n ; j++ )
    {
        printf("\nIs there edge between %d & %d ? (Y/N/y/n) :",i,j);
        scanf(" %c", &reply);
        if ( reply == 'y' || reply == 'Y' )
            mat[i][j] = 1;
        else
            mat[i][j] = 0;
        }
    } 

    for(i=0;i<n;i++)
    visited[i]=0;
    printf("\nEnter the start vertex: ");
    scanf("%d",&v);
    printf("\nDFS Traversal is:");
    DFS(v);
    printf("\n\n");
}

void DFS(int i)
{
    int j;
    printf("%d ",i);
    visited[i]=1;
    for(j=0;j<n;j++)
    if(!visited[j] && mat[i][j]==1)
        DFS(j);
}
//read graph as adjacency list and print it.
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int vertex;
    struct node *next;
}node;

//heads of linked list
node *ll[20];   
int n;
//create adjacency list
void read_graph(); 
//insert an edge (vi,vj) in te adjacency list
void insert(int,int);  
//print adjacency list
void printlist(); 

void main()
{
    read_graph();
    printf("\nAdjacency List is:\n");
    printlist();
    printf("\n");
}

void read_graph()
{
    int i,vi,vj,no_of_edges;
    printf("\nEnter number of vertices:");
    scanf("%d",&n);//n=3
    //initialise ll[] with a null
    ll[0]=NULL;
        //read edges and insert them in G[]
    
    printf("\nEnter number of edges:");
    scanf("%d",&no_of_edges);

    for(i=0;i<no_of_edges;i++)
    {
        printf("Enter an edge(initial_vertex end_vertex):");
        scanf("%d%d",&vi,&vj);  
        insert(vi,vj);  
    }           
}               

void insert(int vi,int vj)
{            
    node *p,*q;       
    q=(node*)malloc(sizeof(node));
    q->vertex=vj;
    q->next=NULL;

    //insert the node in the linked list number vi
    if(ll[vi]==NULL)
        ll[vi]=q; 
    else
    {
        //go to end of the linked list
        p=ll[vi];
        while(p->next!=NULL)
        p=p->next;
        p->next=q;
    }
}//insert()

void printlist()
{
    struct node *p; 
    int i;
    for (i = 0; i < n ; i++ )
    {
            printf("\n%d=",i);
            p=ll[i];
            while(p!=NULL)
            {
                printf("%d->",p->vertex);
                p=p->next;
            }
            printf("NULL\n");   
    } // for             
}                    



//read graph as adjacency list and find out indegree,outdegree
//and total degree of each node in graph.
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    struct node *next;
    int vertex;
}node;

//heads of linked list
node *ll[20];
int n;
//create adjacency list
void read_graph(); 
//insert an edge (vi,vj) in the adjacency list
void insert(int,int);  
void degree();

void main()
{
    int i,v;
    read_graph();
    degree(n);
    printf("\n\n");
}

void read_graph()
{
    int i,vi,vj,no_of_edges;
    printf("\nEnter number of vertices:");
    scanf("%d",&n);

        //initialise ll[] with a null
    ll[0]=NULL;
        //read edges and insert them in G[]
    
    printf("\nEnter number of edges:");
    scanf("%d",&no_of_edges);

    for(i=0;i<no_of_edges;i++)
    {
        printf("Enter an edge(u v):");
        scanf("%d%d",&vi,&vj);
        insert(vi,vj);
    }
}

void insert(int vi,int vj)
{
    node *p,*q;
    
    //acquire memory for the new node
    q=(node*)malloc(sizeof(node));
    q->vertex=vj;
    q->next=NULL;

    //insert the node in the linked list number vi
    if(ll[vi]==NULL)
        ll[vi]=q;
    else
    {
        //go to end of the linked list
        p=ll[vi];
    
        while(p->next!=NULL)
        p=p->next;
        p->next=q;
    }
}

void degree(int n)//n=3
{
    int i,indegree[10],outdegree[10];
    struct node *p; 
    for(i=0;i<10;i++)
    {
        indegree[i]=0;
    }
    for(i=0;i<10;i++)outdegree[i]=0;
    for (i = 0; i < n ; i++ )
    {
            p=ll[i];
            while(p!=NULL)
            {
                indegree[p->vertex]+=1;
                outdegree[i]+=1; 
                p=p->next;
            }
    } // for
    for(i=0;i<n;i++)
        printf("\nIndegree, Outdegree and Total Degree of vertex %d is %d, %d, %d",i,indegree[i],outdegree[i],indegree[i]+outdegree[i]);
}


//adjacency list DFS
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    struct node *next;
    int vertex;
}node;

node *ll[20];   
//heads of linked list
int visited[20];
int n;
void read_graph(); 
//create adjacency list
void insert(int,int);  
//insert an edge (vi,vj) in te adjacency list
void DFS(int);

void main()
{
    int i,v;
    read_graph();
    //initialised visited to 0
    for(i=0;i<n;i++)
        visited[i]=0;
    printf("\nEnter the start vertex:");
    scanf("%d",&v);
    printf("\nDFS Traversal is:");
    DFS(v);
    printf("\n\n");
}

void DFS(int i)
{
    node *p;
    printf("%d ",i);
    p=ll[i];
    visited[i]=1;
    while(p!=NULL)
    {
        i=p->vertex;
        if(!visited[i])
        DFS(i);
        p=p->next;
    }
}

void read_graph()
{
    int i,vi,vj,no_of_edges;
    printf("\nEnter number of vertices:");
    scanf("%d",&n);

    //initialise G[] with a null
    ll[0]=NULL;
    //read edges and insert them in G[]
    
    printf("\nEnter number of edges:");
    scanf("%d",&no_of_edges);
    for(i=0;i<no_of_edges;i++)
    {
        printf("Enter an edge(u,v):");
        scanf("%d%d",&vi,&vj);
        insert(vi,vj);
    }
}

void insert(int vi,int vj)
{
    node *p,*q;
    
    //acquire memory for the new node
    q=(node*)malloc(sizeof(node));
    q->vertex=vj;
    q->next=NULL;
    //insert the node in the linked list number vi
    if(ll[vi]==NULL)
        ll[vi]=q;
    else
    {
        //go to end of the linked list
        p=ll[vi];
    
        while(p->next!=NULL)
        p=p->next;
        p->next=q;
    }
}


// Adjacency list BFS

#include <stdio.h>
#include <stdlib.h>
#define SIZE 40

struct queue {
    int items[SIZE];
    int front;
    int rear;
};

struct queue* createQueue();
void enqueue(struct queue* q, int);
int dequeue(struct queue* q);
void display(struct queue* q);
int isEmpty(struct queue* q);
void printQueue(struct queue* q);

struct node {
    int vertex;
    struct node* next;
};

struct node* createNode(int);

struct Graph {
    int numVertices;
    struct node** adjLists;
    int* visited;
};

// BFS algorithm
void bfs(struct Graph* graph, int startVertex) {
    struct queue* q = createQueue();
    graph->visited[startVertex] = 1;
    enqueue(q, startVertex);
    while (!isEmpty(q)) {
    printQueue(q);
    int currentVertex = dequeue(q);
    printf("Visited %d\n", currentVertex);

    struct node* temp = graph->adjLists[currentVertex];

    while (temp) {
    int adjVertex = temp->vertex;

    if (graph->visited[adjVertex] == 0) {
        graph->visited[adjVertex] = 1;
        enqueue(q, adjVertex);
    }
    temp = temp->next;
    }
}
}

// Creating a node
struct node* createNode(int v) {
    struct node* newNode = malloc(sizeof(struct node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Creating a graph
struct Graph* createGraph(int vertices) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

  graph->adjLists = malloc(vertices * sizeof(struct node*));
  graph->visited = malloc(vertices * sizeof(int));

    int i;
    for (i = 0; i < vertices; i++) {
    graph->adjLists[i] = NULL;
    graph->visited[i] = 0;
    }

    return graph;
}

// Add edge
void addEdge(struct Graph* graph, int src, int dest) {
    // Add edge from src to dest
    struct node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Add edge from dest to src
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Create a queue
struct queue* createQueue() {
    struct queue* q = malloc(sizeof(struct queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

// Check if the queue is empty
int isEmpty(struct queue* q) {
    if (q->rear == -1)
    return 1;
    else
    return 0;
}

// Adding elements into queue
void enqueue(struct queue* q, int value) {
    if (q->rear == SIZE - 1)
    printf("\nQueue is Full!!");
    else {
    if (q->front == -1)
    q->front = 0;
    q->rear++;
    q->items[q->rear] = value;
    }
}

// Removing elements from queue
int dequeue(struct queue* q) {
    int item;
    if (isEmpty(q)) {
    printf("Queue is empty");
    item = -1;
    }
    else {
    item = q->items[q->front];
    q->front++;
    if (q->front > q->rear) {
    printf("Resetting queue ");
    q->front = q->rear = -1;
    }
}
return item;
}

// Print the queue
void printQueue(struct queue* q) {
    int i = q->front;

    if (isEmpty(q)) {
    printf("Queue is empty");
    }
    else {
    printf("\nQueue contains \n");
    for (i = q->front; i < q->rear + 1; i++) {
    printf("%d ", q->items[i]);
    }
    }
}

int main() {
    struct Graph* graph = createGraph(4);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 0);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 3);
    //addEdge(graph, 3, 4);

    bfs(graph, 0);

    return 0;
}
