1. Write a C program that accepts the vertices and edges of a graph.
Create and display adjacency list also print indegree, outdegree and
total degree of all vertex of graph.

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int vertex;
    struct node *next;
};

// Create adjacency list
int read_graph(struct node *adj_list[10], int n)
{
    int i, j, reply;
    struct node *temp, *nw;

    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            if(i == j)
                continue;

            printf("\nVertices %d and %d are adjacent? (1/0): ", i, j);
            scanf("%d", &reply);

            if(reply == 1)
            {
                nw = (struct node*)malloc(sizeof(struct node));
                nw->vertex = j;
                nw->next = NULL;

                if(adj_list[i] == NULL)
                {
                    adj_list[i] = nw;
                }
                else
                {
                    temp = adj_list[i];
                    while(temp->next != NULL)
                        temp = temp->next;

                    temp->next = nw;
                }
            }
        }
    }
    return 0;
}

// Display adjacency list
int dislist(struct node *adj_list[10], int n)
{
    struct node *temp;
    int i;

    for(i = 1; i <= n; i++)
    {
        printf("\nv[%d] -> ", i);
        temp = adj_list[i];

        while(temp)
        {
            printf("v[%d] -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL");
    }
    return 0;
}

// In-degree, Out-degree
int inout_degree(struct node *adj_list[10], int n)
{
    struct node *temp;
    int in_deg, out_deg, i, j;

    printf("\n\nVertex\tIn-Degree\tOut-Degree\tTotal");

    for(i = 1; i <= n; i++)
    {
        in_deg = out_deg = 0;

        // Out-degree
        temp = adj_list[i];
        while(temp)
        {
            out_deg++;
            temp = temp->next;
        }

        // In-degree (FIXED)
        for(j = 1; j <= n; j++)
        {
            temp = adj_list[j];
            while(temp)
            {
                if(temp->vertex == i)
                    in_deg++;
                temp = temp->next;
            }
        }

        printf("\nV[%d]\t%d\t\t%d\t\t%d",
               i, in_deg, out_deg, in_deg + out_deg);
    }
    return 0;
}

// Main
void main()
{
    struct node *adj_list[10];
    int n, i;

    printf("\nDirected Graph");
    printf("\nHow many vertices: ");
    scanf("%d", &n);

    for(i = 1; i <= n; i++)
        adj_list[i] = NULL;

    read_graph(adj_list, n);
    dislist(adj_list, n);
    inout_degree(adj_list, n);
}


Q1) Write a C program that accepts the vertices and edges of a graph 
and stores it as an adjacency matrix. Display the adjacency matrix

#include<stdio.h>
#include<stdlib.h>

struct node
{
 int vertex;
 struct node *next;
};

struct node *v[10];   // adjacency list

// Create adjacency matrix
void creamat(int m[10][10], int n)
{
 int i, j;

 for(i = 0; i < n; i++)
 {
     for(j = 0; j < n; j++)
     {
         m[i][j] = 0;

         if(i != j)
         {
             printf("\nIs there an edge between %d and %d (1/0): ", i+1, j+1);
             scanf("%d", &m[i][j]);
         }
     }
 }
}

// Display adjacency matrix
void dismat(int m[10][10], int n)
{
 int i, j;

 printf("\nAdjacency Matrix:\n");

 for(i = 0; i < n; i++)
 {
     for(j = 0; j < n; j++)
         printf("%4d", m[i][j]);

     printf("\n");
 }
}

// Create adjacency list from matrix
void crelist(int m[10][10], int n)
{
 int i, j;
 struct node *temp, *nw;

 for(i = 0; i < n; i++)
 {
     v[i] = NULL;

     for(j = 0; j < n; j++)
     {
         if(m[i][j] == 1)
         {
             nw = (struct node *)malloc(sizeof(struct node));
             nw->vertex = j + 1;
             nw->next = NULL;

             if(v[i] == NULL)
             {
                 v[i] = nw;
                 temp = nw;
             }
             else
             {
                 temp->next = nw;
                 temp = nw;
             }
         }
     }
 }
}

// Display adjacency list
void dislist(int n)
{
 struct node *temp;
 int i;

 printf("\nAdjacency List:\n");

 for(i = 0; i < n; i++)
 {
     printf("V[%d] -> ", i+1);
     temp = v[i];

     while(temp)
     {
         printf("%d -> ", temp->vertex);
         temp = temp->next;
     }
     printf("NULL\n");
 }
}

// Main function
int main()
{
 int m[10][10], n;

 printf("How many vertices: ");
 scanf("%d", &n);

 creamat(m, n);
 dismat(m, n);
 crelist(m, n);
 dislist(n);

 return 0;
}


 Q1) Write a program to sort n randomly generated elements using 
Heapsort method.

#include<stdio.h>
void heapsort(int arr[], int n);
void heapify(int arr[], int n, int i);
void swap(int *a, int *b);

int main()
{
    int arr[20], i, n;

    printf("\nEnter how many elements :- ");
    scanf("%d", &n);

    printf("\nEnter Array Elements : ");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    heapsort(arr, n);

    printf("\nSorted Elements are : ");
    for(i = 0; i < n; i++)
        printf("%d\t", arr[i]);

    return 0;
}

// Swap function
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify function
void heapify(int arr[], int n, int i)
{
    int largest = i;          
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && arr[left] > arr[largest])
        largest = left;

    if(right < n && arr[right] > arr[largest])
        largest = right;

    if(largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

// Heap sort
void heapsort(int arr[], int n)
{
    int i;

    // Build max heap
    for(i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extract elements
    for(i = n - 1; i > 0; i--)   
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}


 Q1) Write a C program to find the height of the tree and check 
whether given tree is balanced or not.

#include<stdio.h>
#include<stdlib.h>

// Structure of Tree Node
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

// Create new node
struct node* newNode(int data)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// Find height of tree
int height(struct node* root)
{
    if(root == NULL)
        return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// Check if tree is balanced
int isBalanced(struct node* root)
{
    if(root == NULL)
        return 1;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    int diff = leftHeight - rightHeight;
    if(diff < 0)
        diff = -diff;

    if(diff <= 1 && isBalanced(root->left) && isBalanced(root->right))
        return 1;

    return 0;
}

// Main
int main()
{
    struct node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("Height of tree = %d\n", height(root));

    if(isBalanced(root))
        printf("Tree is Balanced\n");
    else
        printf("Tree is NOT Balanced\n");

    return 0;
}

Q1) Write a C program for the Implementation of Kruskal’s 
Minimum spanning tree algorithm

#include<stdio.h>
#include<stdlib.h>

int i, j, k, a, b, u, v, n, e = 1;
int min, mincost = 0, cost[9][9], parent[9];

int find(int);
int uni(int, int);

int main()
{
    printf("\nImplementation of Kruskal's Algorithm");
    printf("\nEnter number of vertices: ");
    scanf("%d", &n);

    // Initialize parent array
    for(i = 1; i <= n; i++)
        parent[i] = 0;

    printf("\nEnter cost adjacency matrix:\n");
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            printf("Enter cost of %d to %d: ", i, j);
            scanf("%d", &cost[i][j]);

            if(cost[i][j] == 0)
                cost[i][j] = 999;   // no edge
        }
    }

    printf("\nEdges of Minimum Cost Spanning Tree:\n");

    while(e < n)
    {
        for(i = 1, min = 999; i <= n; i++)
        {
            for(j = 1; j <= n; j++)
            {
                if(cost[i][j] < min)
                {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        u = find(u);
        v = find(v);

        if(uni(u, v))
        {
            printf("Edge %d: (%d - %d) = %d\n", e++, a, b, min);
            mincost += min;
        }

        cost[a][b] = cost[b][a] = 999;   // remove edge
    }

    printf("\nMinimum Cost = %d\n", mincost);

    return 0;
}

// Find function
int find(int i)
{
    while(parent[i])
        i = parent[i];
    return i;
}

// Union function
int uni(int i, int j)
{
    if(i != j)
    {
        parent[j] = i;
        return 1;
    }
    return 0;
}


Q1) Write a C program for the Implementation of Prim’s Minimum 
spanning tree algorithm.

#include<stdio.h>

int a, b, u, v, n, i, j, ne = 1;
int visited[10] = {0}, min, mincost = 0, cost[10][10];

int main()
{
    printf("\nEnter number of nodes: ");
    scanf("%d", &n);

    printf("\nEnter adjacency matrix:\n");
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            printf("Enter cost of %d to %d: ", i, j);
            scanf("%d", &cost[i][j]);

            if(cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }

    printf("\nAdjacency Matrix:\n");
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
            printf("%5d", cost[i][j]);
        printf("\n");
    }

    visited[1] = 1;   // start from vertex 1

    while(ne < n)
    {
        min = 999;

        for(i = 1; i <= n; i++)
        {
            if(visited[i])
            {
                for(j = 1; j <= n; j++)
                {
                    if(!visited[j] && cost[i][j] < min)
                    {
                        min = cost[i][j];
                        a = u = i;
                        b = v = j;
                    }
                }
            }
        }

        visited[v] = 1;
        printf("\nEdge %d: (%d - %d) cost = %d", ne++, a, b, min);
        mincost += min;

        cost[a][b] = cost[b][a] = 999;
    }

    printf("\n\nMINIMUM COST = %d\n", mincost);

    return 0;
}


 Q1) Write a C program for the implementation of Topological 
sorting.

#include<stdio.h>
#define MAX 50

typedef struct
{
    int data[MAX];
    int top;
} stack;

// Initialize stack
void initstack(stack *ps)
{
    ps->top = -1;   
}

// Push
void push(stack *ps, int num)
{
    ps->data[++ps->top] = num;
}

// Pop
int pop(stack *ps)
{
    return ps->data[ps->top--];
}

// Check empty
int isempty(stack *ps)
{
    return (ps->top == -1);
}

// Topological Sort
void topological_sort(int m[10][10], int n)
{
    int i, j, v, w;
    int visited[20] = {0};
    int indeg[10] = {0};
    stack ps;

    // Calculate indegree
    for(i = 0; i < n; i++)
    {
        indeg[i] = 0;   // important
        for(j = 0; j < n; j++)
        {
            indeg[i] += m[j][i];
        }
    }

    initstack(&ps);

    printf("\nTopological Order:\n");

    while(1)
    {
        for(v = 0; v < n; v++)
        {
            if(visited[v] == 0 && indeg[v] == 0)
            {
                visited[v] = 1;
                push(&ps, v);
                printf("v[%d] ", v + 1);
            }
        }

        if(isempty(&ps))
            break;

        v = pop(&ps);

        for(w = 0; w < n; w++)
        {
            if(m[v][w] == 1)
                indeg[w]--;
        }
    }
}

// Main
int main()
{
    int m[10][10], n, i, j;

    printf("\nHow many vertices: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(i == j)
                m[i][j] = 0;
            else
            {
                printf("Edge between %d and %d (1/0): ", i+1, j+1);
                scanf("%d", &m[i][j]);
            }
        }
    }

    printf("\nAdjacency Matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
            printf("%5d", m[i][j]);
        printf("\n");
    }

    topological_sort(m, n);

    return 0;
}



 Q1) Write a C program to find the minimum and maximum values 
in a Binary Search Tree.

#include<stdio.h>
#include<stdlib.h>

typedef struct BSTnode
{
    int data;
    struct BSTnode *left, *right;
} BSTnode;

// Insert function
BSTnode *insert(BSTnode *T, int x)
{
    BSTnode *nw, *temp;

    nw = (BSTnode *)malloc(sizeof(BSTnode));
    nw->data = x;
    nw->left = nw->right = NULL;

    if(T == NULL)
        return nw;

    temp = T;

    while(1)
    {
        if(x < temp->data)
        {
            if(temp->left == NULL)
            {
                temp->left = nw;
                break;
            }
            else
                temp = temp->left;
        }
        else
        {
            if(temp->right == NULL)
            {
                temp->right = nw;
                break;
            }
            else
                temp = temp->right;
        }
    }
    return T;
}

// Create BST
BSTnode *create()
{
    int i, n, x;
    BSTnode *root = NULL;

    printf("\nEnter how many nodes: ");
    scanf("%d", &n);

    printf("Enter tree values: ");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &x);
        root = insert(root, x);
    }

    return root;
}

// Find minimum
int min(BSTnode *T)
{
    BSTnode *temp = T;

    while(temp->left != NULL)
        temp = temp->left;

    return temp->data;
}

// Find maximum
int max(BSTnode *T)
{
    BSTnode *temp = T;

    while(temp->right != NULL)
        temp = temp->right;

    return temp->data;
}

// Main function
int main()
{
    BSTnode *root = NULL;

    root = create();

    if(root != NULL)
    {
        printf("\nMinimum value in BST: %d", min(root));
        printf("\nMaximum value in BST: %d", max(root));
    }

    return 0;
}


 Write a C program to maintain a phonebook using Binary Search 
Tree by name where each node contains contact name and phone 
number

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
    char name[50];
    char phone[15];
    struct node *left, *right;
} node;

// Create node
node* createNode(char name[], char phone[])
{
    node* newnode = (node*)malloc(sizeof(node));
    strcpy(newnode->name, name);
    strcpy(newnode->phone, phone);
    newnode->left = newnode->right = NULL;
    return newnode;
}

// Insert BST
node* insert(node* root, char name[], char phone[])
{
    if(root == NULL)
        return createNode(name, phone);

    if(strcmp(name, root->name) < 0)
        root->left = insert(root->left, name, phone);

    else if(strcmp(name, root->name) > 0)
        root->right = insert(root->right, name, phone);

    else
        printf("\nContact already exists!");

    return root;
}

// Search
void search(node* root, char name[])
{
    if(root == NULL)
    {
        printf("\nContact not found!");
        return;
    }

    int cmp = strcmp(name, root->name);

    if(cmp == 0)
    {
        printf("\nContact Found!");
        printf("\nName  : %s", root->name);
        printf("\nPhone : %s", root->phone);
        return;
    }

    if(cmp < 0)
        search(root->left, name);
    else
        search(root->right, name);
}

// Display (Inorder)
void display(node* root)
{
    if(root != NULL)
    {
        display(root->left);
        printf("\nName: %s\tPhone: %s", root->name, root->phone);
        display(root->right);
    }
}

// Main
int main()
{
    node* root = NULL;
    int choice;
    char name[50], phone[15];

    while(1)
    {
        printf("\n\n--- PHONEBOOK MENU ---");
        printf("\n1. Insert Contact");
        printf("\n2. Search Contact");
        printf("\n3. Display Contacts");
        printf("\n4. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("\nEnter Name: ");
                scanf("%49s", name);
                printf("Enter Phone: ");
                scanf("%14s", phone);
                root = insert(root, name, phone);
                break;

            case 2:
                printf("\nEnter Name to Search: ");
                scanf("%49s", name);
                search(root, name);
                break;

            case 3:
                printf("\nPhonebook Contacts:");
                display(root);
                break;

            case 4:
                exit(0);

            default:
                printf("\nInvalid choice!");
        }
    }

    return 0;
}




Q1)  Menu Driven Program :- Create, Insert, Search, Inorder, Preorder, 
Postorder, Count Node, Count Leaf. 

#include<stdio.h>
#include<stdlib.h>

typedef struct BSTnode
{
    int data;
    struct BSTnode *left, *right;
} BSTnode;

// Create BST
BSTnode *create();
BSTnode *insert(BSTnode *, int);
BSTnode *search(BSTnode *, int);
void inorder(BSTnode *);
void preorder(BSTnode *);
void postorder(BSTnode *);
int count(BSTnode *);
int countLeaf(BSTnode *);

// Create
BSTnode *create()
{
    int i, n, x;
    BSTnode *root = NULL;

    printf("\nEnter how many nodes: ");
    scanf("%d", &n);

    printf("\nEnter tree values: ");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &x);
        root = insert(root, x);
    }
    return root;
}

// Insert
BSTnode *insert(BSTnode *T, int x)
{
    BSTnode *nw, *temp;

    nw = (BSTnode *)malloc(sizeof(BSTnode));
    nw->data = x;
    nw->left = nw->right = NULL;

    if(T == NULL)
        return nw;

    temp = T;

    while(1)
    {
        if(x < temp->data)
        {
            if(temp->left == NULL)
            {
                temp->left = nw;
                break;
            }
            temp = temp->left;
        }
        else
        {
            if(temp->right == NULL)
            {
                temp->right = nw;
                break;
            }
            temp = temp->right;
        }
    }
    return T;
}

// Search
BSTnode *search(BSTnode *root, int x)
{
    while(root != NULL)
    {
        if(x == root->data)
            return root;

        if(x < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return NULL;
}

// Inorder
void inorder(BSTnode *T)
{
    if(T != NULL)
    {
        inorder(T->left);
        printf("%d ", T->data);
        inorder(T->right);
    }
}

// Preorder
void preorder(BSTnode *T)
{
    if(T != NULL)
    {
        printf("%d ", T->data);
        preorder(T->left);
        preorder(T->right);
    }
}

// Postorder
void postorder(BSTnode *T)
{
    if(T != NULL)
    {
        postorder(T->left);
        postorder(T->right);
        printf("%d ", T->data);
    }
}

// Count nodes
int count(BSTnode *T)
{
    if(T == NULL)
        return 0;

    return 1 + count(T->left) + count(T->right);
}

// Count leaf nodes
int countLeaf(BSTnode *T)
{
    if(T == NULL)
        return 0;

    if(T->left == NULL && T->right == NULL)
        return 1;

    return countLeaf(T->left) + countLeaf(T->right);
}

// Main
int main()
{
    BSTnode *root = NULL, *p;
    int x, op;

    do
    {
        printf("\n\n1.Create");
        printf("\n2.Insert");
        printf("\n3.Search");
        printf("\n4.Inorder");
        printf("\n5.Preorder");
        printf("\n6.Postorder");
        printf("\n7.Count Nodes");
        printf("\n8.Count Leaf Nodes");
        printf("\n9.Exit");
        printf("\nEnter choice: ");
        scanf("%d", &op);

        switch(op)
        {
            case 1:
                root = create();
                break;

            case 2:
                printf("\nEnter value: ");
                scanf("%d", &x);
                root = insert(root, x);
                break;

            case 3:
                printf("\nEnter key: ");
                scanf("%d", &x);
                p = search(root, x);
                if(p == NULL)
                    printf("\nNOT FOUND");
                else
                    printf("\nFOUND");
                break;

            case 4:
                inorder(root);
                break;

            case 5:
                preorder(root);
                break;

            case 6:
                postorder(root);
                break;

            case 7:
                printf("\nTotal nodes = %d", count(root));
                break;

            case 8:
                printf("\nLeaf nodes = %d", countLeaf(root));
                break;
        }

    } while(op != 9);

    return 0;
}







----------------------------------------------------- SLIP  - 1 ------------------------------------------------------------------ 
Section II: Database Management Systems-II      
Consider the following Entities and their Relationships for Project-Employee database. 
Project (pno integer, pname char (30), ptype char (20), duration integer) 
Employee (eno integer, ename char (20), qualification char (15), joining_date date) 
[15 Marks] 
The Relationship between Project and Employee is many to many with descriptive attribute 
start_date date, no_of_hours_worked integer. 
Constraints: Primary Key, duration should be greater than zero, pname should not be null. 
Q2) Using above Database Solve the following 
[10 Marks] 
1) Write a stored function to accept eno as input parameter and count number of projects on 
which that employee is working. 
OR 
1) Write a trigger before inserting into a project table to check duration should be always greater 
than zero. Display appropriate message 
2) Write a procedure to accept three numbers from user and display addition, subtraction and 
multiplication of three numbers. 
[


create table pro1(pno int primary key,pname varchar(30) not null,ptype varchar(20),duration int, check(duration > 0)); 
create table emp1(eno int primary key,ename varchar(20),qualification varchar(15),joinig_date date); 
create table pro_emp1(pno int,eno int,start_date date,no_of_hours_worked int,foreign key(pno) references pro1(pno),foreign key(eno) references emp1(eno)); 
insert into pro1 values(1,'Library System','software',6),(2,'banking app','software',8),(3,'website developement','web',4); 
select * from pro1; 
insert into emp1 values(101,'amit','Bsc','2022-06-10'),(102,'neha','Msc','2021-08-15'),(103,'rahul','Bca','2023-01-05'); 
select * from emp1; 
insert into pro_emp1 values(1,101,'2024-01-10',120),(2,101,'2024-02-05',90),(3,101,'2024-03-01',110),(1,103,'2024-02-15',80); 
select * from pro_emp1;

 ------------------- Trigger -----------------------------------  
create or replace function check_duration() returns trigger as $$ 
begin 
if NEW.duration <=0 then 
raise exception 'Duration must be greater then zero'; 
end if; 
return NEW; 
end; 
$$ language plpgsql; 

create trigger duration_check 
before insert on pro1 
for each row 
execute function check_duration(); 
insert into pro1 values(4,'test','software',0); 
---------------------- Q2 ------------------------------------------- 
create or replace procedure arithmetic_op(a int,b int,c int) language plpgsql as $$ 
begin 
raise notice 'Addition = %',a+b+c; 
raise notice 'Subtraction = %',a-b-c; 
raise notice 'Multiplication = %',a*b*c; 
end; 
$$; 
call arithmetic_op(5,3,2); 

----------------------------------------------------- SLIP  - 2 ------------------------------------------------------------------ 
Q1):- Section II: Database Management Systems-II      
Consider the following Entities and their Relationships 
Person (pno integer, pname varchar (20), birthdate date, income money) 
Area (aname varchar (20), area_type varchar (5)) 
[15 Marks] 
An area can have one or more persons living in it, but a person belongs to exactly one area. 
Constraints: Primary Key,area_type can be either ‘urban’ or ‘rural’. 
Q2) Using above Database Solve the following  
[10 Marks] 
1) Write a stored function to print total number of persons of a particular area. Accept area name as 
input parameter. 
OR 
1) Write a stored function to print sum of income of person living in “ ” area type. (Accept area type 
as input parameter). Display appropriate message for invalid area type. 
2) Write a procedure to accept two numbers from user and display division of two numbers. Use 
raise to display error messages for division by zero error. 



create table area2(aname varchar(20) primary key,area_type varchar(5)); 
create table person2(pno int primary key,pname varchar(20),birthdate date,income money,aname varchar(20),foreign key(aname) references area2(aname)); 
insert into area2 values ('nashik','urban'),('sinner','rural'),('pune','urban'); 
insert into person2 values (101,'amit','1998-05-12',25000,'nashik'),(102,'amit','1999-07-15',30000,'pune'),(103,'amit','2000-02-10',20000,'sinner'),(104,'pooja','1998
11-20',28000,'nashik'); 

create or replace function count_person(area_name varchar) returns int as $$ 
declare  
total int; 
begin 
select count(*) into total from person2 where aname=area_name; 
return total; 
end; 
$$ language plpgsql; 
select count_person('nashik'); 
Q2]  

create or replace procedure divide_num(a int,b int) language plpgsql as $$ 
declare 
result numeric; 
begin  
if b= 0 then 
raise exception 'Division by zero error'; 
end if; 
result := a/b; 
raise notice 'Division Result = %',result; 
end; 
$$; 
call divide_num(10,2); 
call divide_num(5,0); 

----------------------------------------------------- SLIP  - 3 ------------------------------------------------------------------ 
Q1]Section II: Database Management Systems-II      
Consider the following Entities and their Relationship. 
Student (s_no integer, s_name char (20), address char (25), class char (10)) 
Teacher (t_no integer,t_name char (10), qualification char (10),experience integer) 
[15 Marks] 
Relationship between Student and Teacher is Many to Many with descriptive attribute subject 
and marks_scored. 
Constraints: Primary Key,s_name,t_name should not be null,marks_scored> 0 
Q2) Using above Database Solve the following  
[10 Marks] 
1) Write a cursor which will accept student number from the user and display student name along 
with teacher name who taught ‘RDBMS’ subject. 
OR 
1) Write a trigger before insert the record of student. If student number is less than or equal to zero  
give message “Invalid Number”. 
2) Write a procedure accept two numbers from user and display minimum and maximum from 
two numbers.       


create table stud3(s_no int primary key,s_name varchar(20) not null,address varchar(30),class varchar(10)); 
create table tea3(t_no int primary key,t_name varchar(20) not null,qualification varchar(15),experience int); 
create table stud_tea3(s_no int,t_no int,subject varchar(15),marks_scored int,check (marks_scored > 0),primary key(s_no,t_no),foreign key(t_no) references 
tea3(t_no)); 
insert into stud3 values(1,'amit','nashik','SYBSC'),(2,'priya','pune','SYBSC'),(3,'rohit','mumbai','FYBSC'); 
insert into tea3 values(101,'patil','MSC',10),(102,'sharma','MCA',8); 
insert into stud_tea3 values(1,101,'RDBMS',80),(2,101,'RDBMS',75),(3,102,'JAVA',70); 

create or replace function student_insert_msg() returns trigger as $$ 
begin 
if NEW.s_no<=0 then raise notice 'Invalid Number'; 
return NULL; 
end if; 
return NEW; 
end; 
$$ language plpgsql; 
create trigger trg_student_insert 
before insert on stud3  
for each row 
execute function student_insert_msg(); 
insert into stud3 values(-1,'tejal','nashik','SYBSC'); 
Q2]  
create or replace procedure find_min_max(a int,b int) language plpgsql as $$ 
begin 
if a > b then 
raise notice 'Maximum Number :- % ',a; 
raise notice 'Minimum Number :- % ',b; 
else 
raise notice 'Maximum Number :- % ',b; 
raise notice 'Minimum Number :- % ',a; 
end if; 
end; 
$$; 
call find_min_max(2,10); 


----------------------------------------------------- SLIP  - 4------------------------------------------------------------------ 
Q1]  Section II: Database Management Systems-II      
Consider the following Entities and their Relationships . 
[15 Marks] 
Movies (m_name varchar (25), release_year integer, budget money) 
Actor (a_name char (30), role char (30), charges money, a_address varchar(30)) 
Producer (producer_id integer, name char (30), p_address varchar (30)) 
The relationships are as follows: 
Each actor has acted in one or more movies. Each producer has produced many movies 
and each movie can be produced by more than one producers. Each movie has one or 
more actors acting in it, in different roles. 
Q2) Using above Database Solve the following  
[10 Marks] 
1) Write a cursor to pass actor name as input parameter and return total number of movies in 
which given actor is acting. 
OR 
1) Write a trigger before inserting into movie table to check budget. Budget should be 
minimum 50 lakh. Display appropriate message. 
2) Write a procedure to accept a number from user and check the number is positive, negative 
or zero.  

create table movies4(m_name varchar(20) primary key,release_yr int,budget money); 
create table actor4(a_name varchar(30) primary key ,role varchar(20),charges money,a_address varchar(30)); 
create table producer4(producer_id int primary key, name varchar(20),p_address varchar(30)); 
create table movies_actor4(m_name varchar(20),a_name varchar(30),primary key(m_name,a_name),foreign key(m_name) references movies4(m_name),foreign 
key(a_name) references actor4(a_name)); 
create table movies_producer4(m_name varchar(20),producer_id int,primary key(m_name,producer_id),foreign key(m_name) references movies4(m_name),foreign 
key(producer_id) references producer4(producer_id)); 
insert into movies4 values('RRR',2022,70000000),('Bahubali',2017,60000000),('KGF',2018,55000000); 
insert into actor4 values('Ram Charan','Hero',2000000,'Hyderabad'),('Prabhas','Hero',2500000,'Chennai'),('Yash','Hero',2200000,'Banglore'); 
insert into producer4 values(1,'Raju','Mumbai'),(2,'Karan','Delhi'); 
insert into movies_actor4 values('RRR','Ram Charan'),('Bahubali','Prabhas'),('KGF','Yash'),('RRR','Prabhas'); 
insert into movies_producer4 values('RRR',1),('Bahubali',2),('KGF',1);
 
create or replace function check_movie_budget() returns trigger as $$ 
begin 
if NEW.budget < 5000000 ::money then raise notice 'Budget should be minimum 50 lakh'; 
return null; 
end if; 
return NEW; 
end; 
$$ language plpgsql; 
create trigger trg_movie_budget 
before insert on movies4 
for each row 
execute function check_movie_budget(); 
insert into movies4 values('DDLJ',2007,4500000); 
insert into movies4 values('DDLJ',2007,5500000);
 
Q2] 
create or replace procedure check_num(n int) language plpgsql as $$ 
begin 
if n>0 then raise notice 'Number is positive'; 
elsif n<0 then raise notice 'number is negative'; 
else raise notice 'number is zero'; 
end if; 
end; 
$$; 
call check_num(5);

----------------------------------------------------- SLIP  - 05 ------------------------------------------------------------------ 
Q1]Section II: Database Management Systems-II      
[15 Marks] 
Consider the following Entities and their Relationships for Student-Competition 
Student (sreg_no int ,s_name varchar(20), s_class char(10)) 
Competition (c_no int ,c_name varchar(20), c_type char(10)) 
Relationship between Student and Competition is many to many with descriptive 
attributes rank and year. 
Constraints: Primary Key, c_type should not be null, c_type can be ‘sport’ or 
‘academic’. 
Q2) Using above Database Solve the following  
1. write a function using cursor to accept year and class to display student name, 
competition name and rank. 
OR 
1. Define a trigger before updating a competition table. Raise a notice and 
display message “competition record is being updated”. 
[10 Marks] 
2. Write a procedure to accept three numbers from user and find maximum and minimum 
from it.      

create table stude5(sreg_no int primary key,s_name varchar(30),s_class varchar(10)); 
create table compe5(c_no int primary key,c_name varchar(20),c_type varchar(15)); 
create table stud_comp5(sreg_no int,c_no int,rank int,year int,primary key(sreg_no,c_no),foreign key(sreg_no) references stude5(sreg_no),foreign key(c_no) 
references compe5(c_no)); 
insert into stude5 values(1,'amit','SYBSC'),(2,'priya','SYBSC'),(3,'rohit','FYBSC'); 
insert into compe5 values(101,'cricket','sport'),(102,'quiz','academic'),(103,'chess','sport'); 
insert into stud_comp5 values(1,101,1,2023),(2,102,2,2023),(3,103,1,2024),(1,102,3,2024); 
create or replace function comp_update_msg() returns trigger as $$ 
begin 
raise notice 'Competition record is being updated'; 
return NEW; 
end; 
$$ language plpgsql; 
create trigger trg_comp_update 
before update on compe5 
for each row 
execute function comp_update_msg(); 
update compe5 set c_name = 'football' where c_no = 103; 
select * from compe5;
 
Q2]  
create or replace procedure find_min(a int,b int, c int) language plpgsql as $$ 
declare  
min_val int := a; 
begin  
if b  < min_val then  
min_val := b; 
end if; 
if c < min_val then 
min_val := c; 
end if; 
raise notice ' Minimum number :- %',min_val; 
end ; 
$$; 
call find_min(10,1,4); 

create or replace procedure find_max(a int,b int,c int) language plpgsql as $$ 
declare  
max_val int := a; 
begin  
if b>max_val then  
max_val := b; 
end if; 
if c>max_val then  
max_val := c; 
end if; 
raise notice ' Maximum number :- %',max_val; 
end ; 
$$; 
call find_max(4,30,33);



----------------------------------------------------- SLIP  - 06 ------------------------------------------------------------------ 
Q1]Section II: Database Management Systems II      
Consider the following Entities and their Relationships 
BUS (bus_no int , capacity int , depot_name varchar(20)) 
[15 Marks] 
ROUTE (route_no int, source char(20), destination char(20),no_of_stations int) 
DRIVER (driver_no int , driver_name char(20), license_no int, address char(20), 
d_ageint , salary float) 
The relationships are as: BUS_ROUTE: M-1 
BUS_DRIVER: M-M with descriptive attributes Date of duty allotted and Shift itcan 
be 1 (Morning) or 2 (Evening). 
Constraints: 1. License_no is unique. 
2. Bus capacity is not null 
Q2) Using above Database Solve the following  
[10 Marks] 
1. Write a stored function to accept the bus number and print driver name allotted to that 
bus. 
OR 
1. Write a stored function to accept depot name and display driver details having age 
more than 50. 
2. Write a procedure that accept any number from user and find number is even or odd.  



create table route6(route_no int primary key,source varchar(20),dest varchar(20),no_of_stations int); 
create table bus6(bus_no int primary key,capacity int,depot_name varchar(20),route_no int,foreign key(route_no) references route6(route_no)); 
create table driver6(driver_no int primary key,d_name varchar(20),license_no int,address varchar(15),d_age int,salary float); 
create table bus_driver6(bus_no int,driver_no int,date_of_duty date,shift int check(shift in(1,2)),primary key(bus_no,driver_no),foreign key(bus_no) references 
bus6(bus_no),foreign key(driver_no) references driver6(driver_no)); 
insert into route6 values(1,'nashik','pune',10),(2,'pune','mumbai',12); 
insert into bus6 values(101,50,'nashik',1),(102,40,'pune',2),(103,45,'mumbai',1); 
insert into driver6 values(201,'amit',111,'nashik',45,20000),(202,'rohit',222,'pune',55,22000),(203,'suresh',333,'mumbai',48,21000); 
insert into bus_driver6 values(101,201,'10-jan-2024',1),(102,202,'11-jan-2024',2),(103,203,'12-jan-2024',1); 
create or replace function driver_of_bus(v_bus int) returns void as $$ 
declare 
dname varchar(20); 
cur1 cursor for 
select d_name from driver6 d join bus_driver6 bd on d.driver_no = bd.driver_no where bd.bus_no=v_bus; 
begin 
open cur1; 
loop 
fetch cur1 into dname; 
exit when not found; 
raise notice 'Driver name %',dname; 
end loop; 
close cur1; 
end; 
$$ language plpgsql; 
select driver_of_bus(102); 
select * from bus6; 
select * from driver6; 
Q2]  
create or replace procedure even_odd(a int) language plpgsql as $$ 
begin 
if a % 2 = 0 then  
raise notice 'Number is EVEN'; 
else 
raise notice 'Number is ODD'; 
end if; 
end; 
$$; 
call even_odd(225);


 ----------------------------------------------------- SLIP  - 07 ------------------------------------------------------------------ 
Q1]  Section II: Database Management Systems II      
Consider the following Entities and their Relationships 
Branch (br_id integer, br_name char (30), br_city char (10)) 
[15 Marks] 
Customer (cno integer, c_name char (20), caddr char (35), city char (20)) 
Loan_application(lno integer, l_amt_required money, l_amt_approved money, l_date 
date) 
Relationship between Branch, Customer and Loan_application is Ternary. 
Ternary (br_id integer, cno integer, lno integer) Constraints: Primary Key, 
l_amt_required should be greater than zero. 
Q2) Using above Database Solve the following  
1. Write a stored function using cursor to count the number of customers of 
particular branch. (Accept branch name as input parameter). 
OR 
[10 Marks] 
1. Write a trigger before insert record of customer. If the customer number is less than or 
equal to zero, then give the appropriate message. 
2. Write a procedure to accept value of n and display sum of first n numbers.


create table branch7(br_id int primary key,br_name varchar(20),br_city varchar(20)); 
create table cust7(cno int primary key,c_name varchar(10),caddre varchar(20),city varchar(15)); 
create table loan_app7(lno int primary key,l_amt_required money,l_amt_approved money,l_date date); 
create table ternary7(br_id int,cno int,lno int,primary key(br_id,cno,lno),foreign key(br_id) references branch7(br_id),foreign key(cno) references cust7(cno),foreign 
key(lno) references loan_app7(lno)); 
insert into branch7 values(1,'SBI','nashik'),(2,'BOI','pune'),(3,'HDFC','pune'); 
insert into cust7 values(101,'amit','nashik road','nashik'),(102,'riya','college road','nashik'),(103,'neha','fc road','pune'); 
insert into loan_app7 values(201,50000,45000,'10-01-2024'),(202,45000,30000,'11-05-2023'); 
insert into ternary7 values(1,101,201),(2,103,202),(3,103,201),(2,101,201); 
create or replace function check_cust_no() returns trigger as $$ 
begin 
if NEW.cno<=0 then raise notice 'INVALID CUSTOMER NUMBER'; 
return null; 
end if; 
return NEW; 
end; 
$$ language plpgsql; 
create trigger trg_customer 
before  insert on cust7 
for each row 
execute function check_cust_no(); 
insert into cust7 values(0,'priya','pavan ngr','nsk'); 
Q2]  
create or replace procedure sum_20_num() language plpgsql as $$ 
declare  
i int := 1; 
total int = 0; 
begin 
loop 
exit when i > 20; 
total := total + i; 
i := i + 1; 
end loop; 
raise notice 'Sum of first 20 numbers :- %',total; 
end; 
$$; 
call sum_20_num(); 



----------------------------------------------------- SLIP  - 08 ------------------------------------------------------------------ 
Q1]  Section II: Database Management Systems II      
Consider the following Entities and their Relationships 
[15 Marks] 
TRAIN: (train_no int, train_name varchar(20), depart_time time , arrival_time time, 
source_stn varchar (20),dest_stn varchar (20), no_of_res_bogies int ,bogie_capacity int) 
PASSENGER : (passenger_id int, passenger_name varchar(20), address varchar(30), 
age int ,gender char) 
Relationships: 
Train _Passenger: M-M relationship named ticket with descriptive attributes as follows 
TICKET: ( train_no int, passenger_id int, ticket_no int ,bogie_no int, no_of_berths int 
,tdate date , ticket_amt decimal(7,2),status char) 
Constraints:The status of a berth can be 'W' (waiting) or 'C' (confirmed). 
Q2) Using above Database Solve the following  
[10 Marks] 
1. Write a stored function to display the ticket details of a train. (Accept train name as 
input parameter). Raise an exception in case of invalid train name. 
OR 
1.Write a trigger after insert on passenger to display message “Age above 5 will be charged 
full fare” if age of passenger is more than 5. 
2. Write a procedure that accept two numbers and display addition, subtraction and multiplication of 
two numbers.      


create table train8(train_no int primary key,train_name varchar(50),depart_time time,arrival_time time,source_stn varchar(20),dest_stn 
varchar(20),no_of_res_bogies int,bogie_capacity int); 
create table pass8(pass_id int primary key,pass_name varchar(15),address varchar(20),age int,gender varchar(15)); 
create table ticket(train_no int,pass_id int,ticket_no int,bogie_no int,no_of_berths int,tdate date,ticket_amt decimal(7,2),status char,primary 
key(train_no,pass_id),foreign key(train_no) references train8(train_no),foreign key(pass_id) references pass8(pass_id)); 
insert into train8 values(1,'rajdhani','10:00','18:00','mumbai','delhi',5,72),(2,'express','09:00','16:00','pune','nagpur',4,70); 
insert into pass8 values(101,'amit','nashik',25,'M'),(102,'sneha','pune',20,'F'); 
insert into ticket values(1,101,1001,2,1,'10-02-2024',2000,'C'),(2,102,1002,1,2,'12-05-2024',2200,'W'); 
create or replace function age_check() returns trigger as $$ 
begin 
if NEW.age>5 then raise notice 'Age above 5 will be charged full fare'; 
return null; 
end if; 
return NEW; 
end ; 
$$ language plpgsql; 
create trigger trg_pass_age 
before insert on pass8  
for each row 
execute function age_check(); 
insert into pass8 values(103,'riya','pune',10,'F'); 
insert into pass8 values(104,'rohan','mumbai',2,'M'); 
Q2]  
create or replace procedure add_2_num(a int, b int) language plpgsql as $$ 
begin 
raise notice 'Addition of % and % is:- %',a,b,a+b; 
end; 
$$; 
call add_2_num(5,4); 


----------------------------------------------------- SLIP  - 10 ------------------------------------------------------------------ 
Q1]  Section II: Database Management Systems II      
Consider the following Entities and their Relationships 
[15 Marks] 
Book(b_no int, b_name varchar (20), pub_name varchar (10), b_price float) 
Author (a_no int, a_name varchar (20), qualification varchar (15), address varchar (15)) 
Relationship between Book and Author is many to many. 
Constraints: Primary Key,pub_name should not be null. 
Q2) Using above Database Solve the following  
[10 Marks] 
1. Write a stored function to display the book details written by author . (Accept Author name 
as input parameter). Raise an exception in case of invalid author name. 
OR 
1. Write a trigger after insert on book to display message “prize is so high” if book price is 
more than 1000. 
2. Write a procedure to display all even numbers from 1 to 50. 


create table book10 (b_no int primary key,b_name varchar(20),pub_name varchar(20) not null,b_price float); 
create table author10(a_no int primary key,a_name varchar(20),qualification varchar(20),address varchar(15)); 
create table book_author10 (b_no int references book10(b_no),a_no int references author10(a_no)); 
insert into book10 values(1,'DBMS','pearson',900),(2,'java','McGraw',1200); 
insert into author10 values(101,'Korth','PhD','USA'),(102,'James','MCA','UK'); 
insert into book_author10 values(1,101),(2,102),(2,101); 
create or replace function dis_msg_of_prize() returns trigger as $$ 
begin 
if NEW.b_price > 1000 then 
raise notice 'Book Price is so High'; 
end if; 
return NEW; 
end;  
$$ language plpgsql; 
create trigger trg_book_insert 
after insert on book10 
for each row 
execute function dis_msg_of_prize(); 
insert into book10 values(4,'DS','pearson',1500); 
Q2]  
create or replace procedure even_num() language plpgsql as $$ 
declare 
i int := 2; 
begin 
while i <= 50 
loop  
raise notice '%',i; 
i := i + 2; 
end loop; 
end;  
$$;




 ----------------------------------------------------- SLIP  - 11 ------------------------------------------------------------------ 
Q1] Section II: Database Management Systems II      
Consider the following Entities and their Relationships 
Student (rollno, s_name , class)  
Subject (scode , subject_name)  
[15 Marks] 
Relationship between Student and Subject is many to many with descriptive attribute marks. 
Q2) Using above Database Solve the following  
1. Write a stored function using cursor to calculate total marks of each student and 
display it. 
OR 
[10 Marks] 
1. Define a trigger before deleting a student record from student table. Raise a notice and 
display message “student record is being deleted”. 
2. Write a procedure to accept value of n and find sum and average of first n number. 



create table stud11(rollno int primary key,s_name varchar(20),class varchar(20)); 
create table sub11(scode int primary key,sub_name varchar(15)); 
create table stud_sub11(rollno int references stud11(rollno),scode int references sub11(scode),marks int); 
insert into stud11 values(1,'amit','SY'),(2,'riya','TY'),(3,'neha','FY'); 
insert into sub11 values(101,'DS'),(102,'DBMS'); 
insert into stud_sub11 values(1,101,75),(2,102,80),(3,101,50); 
create or replace function del_stud_rec() returns trigger as $$ 
begin 
raise notice 'Student record is being deleted'; 
return old; 
end; 
$$ language plpgsql; 
create trigger trg_del_stud_rec 
before delete on stud11 
for each row 
execute function del_stud_rec(); 
delete from stud11 where rollno = 1; 
Q2]  
create or replace procedure sum_avg(n int) language plpgsql as $$ 
declare  
i int := 1; 
total int := 0; 
avge float; 
begin 
while i <= n loop 
total :=  total + i; 
i := i + 1; 
end loop; 
avge := total/n; 
raise notice ' Sum = % and Average = %',total,avge; 
end; 
$$; 
call sum_avg(10);



 ----------------------------------------------------- SLIP  - 12 ------------------------------------------------------------------ 
Q2]  Section II: Database Management Systems II      
[15 Marks] 
Consider the following Project-Employee database maintained by a company which stores 
the details of the projects assigned to the employees. 
Following are the tables: 
PROJECT (pno integer, p_name char (30), ptype char(20),duration integer) 
EMPLOYEE (eno integer, e_name char (20), qualification char (15), joindate date)  
The relationships are as follows: 
PROJECT-EMPLOYEE:M-M Relationship, with descriptive attributes as start_date (date), 
no_of_hours_worked (integer). 
Q2) Using above Database Solve the following  
[10 Marks] 
1. Write a trigger before inserting into a project table to check duration should be always 
greater than zero. Display appropriate message. 
OR 
1. Write a stored function to accept project name as input and print the names of 
employees working on the project. Raise an exception for an invalid project name. 
2. Write a procedure to accept value of m and n and display the total count of odd numbers      
from m to n. 


create or replace procedure cnt_odd ( m int , n int) language plpgsql as $$ 
declare  
i int; 
cnt int := 0; 
begin 
for i in m..n loop 
if i % 2 <> 0 then 
cnt := cnt + 1; 
end if; 
end loop; 
raise notice ' Total odd numbers :- %',cnt; 
end; 
$$; 
call cnt_odd(10,50);



 ----------------------------------------------------- SLIP  - 13 ------------------------------------------------------------------ 
Q1]  Section II: Database Management Systems II       
[15 Marks] 
Consider the following database of Bus transport system. Many buses run on one route. Drivers are 
allotted to the buses shift-wise. 
Following are the tables: 
BUS (bus_no int , capacity int , depot_name varchar(20)) 
ROUTE (route_no int, source char(20), destination char(20),no_of_stations int) 
DRIVER (driver_no int , driver_name char(20), license_no int, address char(20), 
d_age int , salary float) 
The relationships are as follows: 
BUS_ROUTE : M-1 
BUS_DRIVER : M-M with descriptive attributes Date of duty allotted and Shift – it can 
be 1 (Morning) 0r 2 ( Evening ). 
Constraints: 1. License no is unique. 
2. Bus capacity is not null. 
Q2) Using above Database Solve the following  
[10 Marks] 
1. Define a trigger before insert the record of driver if the age is not between 18 and 50, raise 
an error message “invalid entry”. 
OR 
1. Write a stored function to accept the bus_no and date and print its allotted drivers. 
Raise an exception in case of invalid bus number. 
2. Write a procedure to accept value of n and display all odd numbers from 1 to n. 


create table route13(route_no int primary key,source varchar(20),dest varchar(20),no_of_stations int); 
create table bus13(bus_no int primary key,capacity int,depot_name varchar(20),route_no int,foreign key(route_no) references route6(route_no)); 
create table driver13(driver_no int primary key,d_name varchar(20),license_no int,address varchar(15),d_age int,salary float); 
create table bus_driver13(bus_no int,driver_no int,date_of_duty date,shift int check(shift in(1,2)),primary key(bus_no,driver_no),foreign key(bus_no) references 
bus6(bus_no),foreign key(driver_no) references driver6(driver_no)); 
insert into route13 values(1,'nashik','pune',10),(2,'pune','mumbai',12); 
insert into bus13 values(101,50,'nashik',1),(102,40,'pune',2),(103,45,'mumbai',1); 
insert into driver13 values(201,'amit',111,'nashik',45,20000),(202,'rohit',222,'pune',55,22000),(203,'suresh',333,'mumbai',48,21000); 
insert into bus_driver13 values(101,201,'10-jan-2024',1),(102,202,'11-jan-2024',2),(103,203,'12-jan-2024',1); 
create or replace function chk_age() returns trigger as $$ 
begin 
if NEW.d_age < 18 or NEW.d_age > 50 then 
raise exception ' Invalid Entry'; 
end if; 
return NEW; 
end; 
$$ language plpgsql; 
create trigger trg_chk_age 
before insert on  driver13 
for each row 
execute function chk_age(); 
insert into driver13 values(205,'kunal',444,'pune',55,25000); 
Q2]  
create or replace function search_in_range (num int, m int , n int) returns varchar language plpgsql as $$ 
begin  
if num between m and n then 
raise notice 'Number is in the range'; 
else 
raise notice 'Number is not int the range '; 
end if; 
end; 
$$; 
select search_in_range(110,1,20);




 ------------------------------------------------------- SLIP  - 14 ------------------------------------------------------------------ 
Q2]  Section II: Database Management Systems-II      
[15 Marks] 
Consider the following Project-Employee database maintained by a company which stores 
the details of the projects assigned to the employees. 
Following are the tables: 
PROJECT (pno integer, p_name char (30), ptype char(20),duration integer) 
EMPLOYEE (eno integer, e_name char (20), qualification char (15), joindate date)  
The relationships are as follows: 
PROJECT-EMPLOYEE: M-M Relationship, with descriptive attributes as start_date (date), 
no_of_hours_worked (integer). 
Q2) Using above Database Solve the following  
[10 Marks] 
1. Write a trigger before inserting into a project table to check duration should be always 
greater than zero. Display appropriate message. 
OR 
1. Write a stored function to accept project name as input and print the names of 
employees working on the project. Raise an exception for an invalid project name. 
2.  Write a procedure to insert the values in project table.



create or replace function number_in_words(n int) returns text language plpgsql as $$ 
declare 
temp int := n; 
digit int; 
result text := ''; 
begin 
if n = 0 then 
return 'zero'; 
end if; 
while temp > 0 loop 
digit := temp % 10; 
case digit  
when 0 then result := ' zero' || result; 
when 1 then result := 'one' || result; 
when 2 then result := 'two' || result; 
when 3 then result := 'three' || result; 
when 4 then result := 'four' || result; 
when 5 then result := 'five' || result; 
when 6 then result := 'six' || result; 
when 7 then result := 'seven' || result; 
when 8 then result := 'eight' || result; 
when 9 then result := 'nine' || result; 
end case; 
temp := temp / 10; 
end loop; 
return trim(result); 
end ; 
$$; 
select number_in_words(789);


 ----------------------------------------------------- SLIP  - 15 ------------------------------------------------------------------ 
Q1]  Section II: Database Management Systems II      
Consider the following Person–Area database 
Person (pnumber integer, pname varchar (20), birthdate date, income money) 
Area ( aname varchar (20), area-type varchar (5) ) 
The relationships are as follows: 
Person-Area: M-1 
The attribute ‘area_type’ can have values either ‘urban’ or ‘rural’. 
Q2) Using above Database Solve the following  
[15 Marks] 
[10 Marks] 
1. Write a cursor to update the income of all people living in ‘Urban’ area by 10%. 
OR 
1. Write a trigger before insert the record of person if the person number is negative raise 
the message    “Invalid Number”. 
2. Write a procedure to display all odd numbers from 1 to 100.   



create table area15(aname varchar(20) primary key,area_type varchar(5) check (area_type in ('urban','rural'))); 
create table person15(pno int primary key,pname varchar(20),birthdate date,income money,aname varchar(20),foreign key(aname) references area2(aname)); 
insert into area15 values ('nashik','urban'),('sinner','rural'),('pune','urban'); 
insert into person15 values (101,'amit','1998-05-12',25000,'nashik'),(102,'amit','1999-07-15',30000,'pune'),(103,'amit','2000-02
10',20000,'sinner'),(104,'pooja','1998-11-20',28000,'nashik'); 
create or replace function chk_pno_neg() returns trigger as $$ 
begin 
if NEW.pno < 0 then 
raise exception 'Invalid Number'; 
end if; 
return NEW; 
end; 
$$ language plpgsql; 
create trigger trg_chk_pno_neg 
before insert on person15 
for each row 
execute function chk_pno_neg(); 
insert into person15 values (-104,'rahul','1995-01-12',30000,'nashik'); 
Q2]  
create or replace procedure odd_numbers() language plpgsql as $$ 
declare 
i int := 1; 
begin 
while i<=100 loop 
if i%2 <> 0 then 
raise notice '%',i; 
end if; 
i := i+1; 
end loop; 
end; 
$$; 
call odd_numbers();



 ----------------------------------------------------- SLIP  - 18 ------------------------------------------------------------------ 
Q1]  Section II: Database Management Systems II      
Consider the following Item-Supplier database 
Item(itemno integer, itemname varchar(20)) 
Supplier(supplier_no integer, supplier_name varchar(20), city varchar(20)) 
The relationship is as, 
[15 Marks] 
Item-Supplier: M-M relationship with rate(money) and quantity (integer) as descriptive attributes. 
Q2) Using above Database Solve the following  
1. Write a cursor to display the names of items whose rate is more than 500. 
OR 
[10 Marks] 
1. Write a trigger before insert or update on rate field. If the rate is less than 50 then raise the 
appropriate exception. 
2. Write a procedure to accept three numbers and find the maximum number from it. 


create table item18(itemno int primary key,itemname varchar(20)); 
create table supplier18(supplier_no int primary key,supplier_name varchar(20), city varchar(15)); 
create table item_supplier_18(itemno int references item18(itemno),supplier_no int references supplier18(supplier_no),rate int,quantity int); 
insert into item18 values(1,'biscuits'),(2,'soap'),(3,'washing powder'); 
insert into supplier18 values(101,'amit traders','nashik'),(102,'neha suppliers','pune'); 
insert into item_supplier18 values(1,101,600,100),(2,102,500,50),(3,102,1000,250); 
create or replace function chk_rate_dismsg() returns trigger as $$ 
begin 
if NEW.rate < 50 then 
raise exception 'Rate should not be less than 50'; 
end if; 
return NEW; 
end; 
$$ language plpgsql; 
create trigger trg_chk_rate_msg18 
before insert or update on item_supplier_18 
for each row 
execute function chk_rate_dismsg(); 
insert into item_supplier_18 values(2,101,45,100); 




----------------------------------------------------- SLIP  - 20 ------------------------------------------------------------------ 
Q1]  Section II: Database Management Systems II      
Consider the following Department-employee database. 
Department (dno integer, dname varchar(20),city varchar(20)) 
Employee (eno integer, ename varchar(20), salary money) 
Department and Employee are related with a one to many relationships. 
Q2) Using above Database Solve the following  
[15 Marks] 
[10 Marks] 
1) Write a function to accept department name and display the maximum salary of an employee 
in that department. 
OR 
1) Write a trigger before insert/update on an employee record. Raise exception if salary <0. 
2) Write a procedure to accept a number and display multiplication table of a number



create table dept20 (dno int primary key,dname varchar(15),city varchar(10)); 
create table emp20 (eno int primary key, ename varchar(20),salary int,dno int references dept20(dno)); 
insert into dept20 values(1,'sales','nashik'),(2,'HR','pune'); 
insert into emp20 values(101,'amit',20000,1),(102,'neha',35000,1),(103,'rahul',80000,2); 
create or replace function sal_chk() returns trigger as $$ 
begin  
if NEW.salary <= 0 then 
raise exception 'Salary Should Not be ZERO'; 
end if; 
return NEW; 
end; 
$$ language plpgsql; 
create trigger trg_sal_chk 
before insert or update on emp20 
for each row 
execute function sal_chk(); 
insert into emp20 values(104,'priya',-225,2);



 ----------------------------------------------------- SLIP  - 21 ------------------------------------------------------------------ 
Q1]  Section II: Database Management Systems II      
Consider the following database 
[15 Marks] 
Doctor(d_no int, d_name varchar(30), specialization varchar(35), phone_no int, charges int) 
Hospital(h_no int, h_name varchar(20), city varchar(10)) 
Doctor and Hospital are related with many to one relationship. 
Q2) Using above Database Solve the following  
[10 Marks] 
1) Write a function which will accept the name of the hospital and calculate the average charges 
of doctors visiting that hospital. 
OR 
1) Write a trigger before insert/update on Doctor. Raise exception if charges are <0. 
2) Write a procedure to insert the values in Doctor table.

create table hos21(h_no int primary key,h_name varchar(20),city varchar(15)); 
create table doc21(d_no int primary key,d_name varchar(20),specialization varchar(20),phone_no int, charges int,h_no int references hos21(h_no)); 
insert into hos21 values(1,'lilavati hospital','mumbai'),(2,'samarth hospital','nashik'); 
insert into doc21 values(101,'dr.patil','dentist',0563448,2000,1),(102,'dr.sharma','cardiologist',8485464,1800,2); 
create or replace function chk_charges() returns trigger as $$ 
begin 
if NEW.charges < 0 then  
raise exception ' charges must be greater than zero'; 
end if; 
return NEW; 
end; 
$$ language plpgsql; 
create trigger trg_chk_charges 
before insert or update on doc21 
for each row 
execute function chk_charges(); 
insert into doc21 values(101,'dr.patil','dentist',0889448,-200,1); 





----------------------------------------------------- SLIP  - 23 ------------------------------------------------------------------ 
Q1]  Section II: Database Management Systems II      
Consider the following database 
[15 Marks] 
Car (c_no int, owner varchar(20), model varchr(10), color varchar(10) 
Driver (driver_no int, driver_name varchar(20), license_no int, d_age int, salary float) 
Car and Driver are related with many to many relationship 
Q2) Using above Database Solve the following  
[10 Marks] 
1) Write a cursor which accepts the driver name and prints the details of all cars that this 
driver has driven, if the driver name is invalid, print an appropriate message. 
OR 
1) Write a trigger before insert/update on Driver. Raise exception if driver age is < 21. 
2) Write a procedure to find sum of first 100 numbers. 


create table car23(c_no int primary key,owner varchar(20),model varchar(20),colour varchar(20)); 
create table driver23(driver_no int primary key,driver_name varchar(10),license_no int,d_age int,salary float); 
create table car_driver23(c_no int references car23(c_no), driver_no int references driver23(driver_no)); 
insert into car23 values(1,'amit','swift','white'),(2,'neha','i20','black'); 
insert into driver23 values(101,'rahul',111,23,15000),(102,'suresh',222,20,10000); 
insert into car_driver23 values(1,101),(2,102),(2,101); 
create or replace function chk_driver_age() returns trigger as $$ 
begin 
if NEW.d_age < 21 then 
raise exception 'driver age must be greater than 21'; 
end if; 
return NEW; 
end; 
$$ language plpgsql; 
create trigger trg_chk_driver_age 
before insert or update on driver23 
for each row 
execute function chk_driver_age(); 
insert into driver23 values(103,'rahul',333,19,15000); 
insert into driver23 values(104,'rohit',444,25,15000);



 ----------------------------------------------------- SLIP  - 24 ------------------------------------------------------------------ 
Q1]  Section II: Database Management Systems II      
Consider the following Department-employee database. 
Department (dno integer, dname varchar(20),city varchar(20)) 
Employee (eno integer, ename varchar(20), salary money) 
Department and Employee are related with a one to many relationship 
Q2) Using above Database Solve the following  
[15 Marks] 
[10 Marks] 
1) Write a function to accept department name as input and display employee name along 
with salary of that department. 
OR 
1) Write a trigger after insert on an employee record. Display appropriate message when the 
record is inserted. 
2)  Write a stored procedure to accept value of n and display first n even numbers



create table dept24 (dno int primary key,dname varchar(15),city varchar(10)); 
create table emp24 (eno int primary key, ename varchar(20),salary int,dno int references dept24(dno)); 
insert into dept24 values(1,'sales','nashik'),(2,'HR','pune'); 
insert into emp24 values(101,'amit',20000,1),(102,'neha',35000,1),(103,'rahul',80000,2); 
create or replace function insert_emp() returns trigger as $$ 
begin 
raise notice ' Employee Record in Successfully Inserted.'; 
return NEW; 
end; 
$$ language plpgsql; 
create trigger trg_insert_emp 
after insert on emp24 
for each row 
execute function insert_emp(); 
insert into emp24 values(104,'rohit',26000,1); 
Q2]  
create or replace procedure even_num_20() language plpgsql as $$ 
declare 
i int := 2; 
cnt int := 0; 
begin 
while  i <= 20 
loop  
raise notice '%',i; 
i := i + 2; 
end loop; 
end;  
$$; 
call even_num_20();




 ----------------------------------------------------- SLIP  - 25 ------------------------------------------------------------------ 
Q1] Section II: Database Management Systems-II       
Consider the following database 
Customer (cno integer, cname varchar(20), city varchar(20)) 
Account (a_no int, a_type varchar(10), opening_date date, balance money) 
Customer and Account are related with one to many relationship 
Q2) Using above Database Solve the following  
[15 Marks] 
[10 Marks] 
1. Write a function using cursor which accepts city name as input and prints the details of all 
customers in that city. 
OR 
1. Write a trigger which does not allow deletion of accounts of  --- type
2.Write a procedure to display all customers from ‘Pune’ city.   



create table cust25(cno int primary key,cname varchar(20),city varchar(10)); 
create table acc25(a_no int primary key,a_type varchar(15),opening_date date,balance money,cno int references cust25(cno)); 
insert into cust25 values(1,'amit','nashik'),(2,'neha','mumbai'),(3,'payal','pune'); 
insert into acc25 values(101,'saving','2024-04-11',45000,1),(102,'current','2024-06-12',30000,2); 
create or replace function prevent_delete() returns trigger as $$ 
begin  
if OLD.a_type = 'saving ' then 
raise exception 'Deletion of Saving Account is not Allowed.'; 
end if; 
return OLD; 
end; 
$$ language plpgsql; 
create trigger trg_prevent_delete 
before delete on acc25 
for each row 
execute function prevent_delete(); 
delete from acc25 where a_type = 'saving'; 
select * from acc25; 
create or replace procedure pune_cust() language plpgsql as $$ 
declare  
rec record; 
begin 
for rec in select * from cust25 where city ='pune' 
loop  
raise notice 'Customer No :- % , Name :- %',rec.cno,rec.cname; 
end loop; 
end; 
$$; 
call pune_cust();





 ----------------------------------------------------- SLIP  - 26 ------------------------------------------------------------------ 
Q1]  Section II: Database Management Systems II      
Consider the following database : 
Item (itemno integer, Itemname varchar(20), quantity integer) 
Supplier(supplierno integer ,Supplier name varchar(20),city varchar(20)) 
[15 Marks] 
Item and supplier are related with many to many relationship. Rate is descriptive attribute. 
Q2) Using above Database Solve the following  
[10 Marks] 
1) Write a stored function using cursors, to accept Item name from the user and display the 
Rate and Supplier Name for that Item. 
OR 
2) Write a trigger before update on rate field. If the difference in the old rate and new rate is 
more than Rs 2000, raise an exception and display the corresponding message. 
3) Write a procedure to accept and display addition, subtraction, multiplication and division of 
two numbers.      


create table item26(itemno int primary key,itemname varchar(20),quantity int); 
create table supplier26(supplier_no int primary key,supplier_name varchar(20), city varchar(15)); 
create table item_supplier_26(itemno int references item18(itemno),supplier_no int references supplier18(supplier_no),rate int); 
insert into item26 values(1,'biscuits',100),(2,'soap',50),(3,'washing powder',250); 
insert into supplier26 values(101,'amit traders','nashik'),(102,'neha suppliers','pune'); 
insert into item_supplier_26 values(1,101,600),(2,102,500),(3,102,1000); 
create or replace function chk_rate() returns trigger as $$ 
begin  
if abs(NEW.rate - OLD.rate ) > 2000 then 
raise exception ' rate difference cannot exceed Rs.2000'; 
end if; 
return NEW; 
end; 
$$ language plpgsql; 
create trigger trg_chk_rate 
before update on item_supplier_26 
for each row 
execute function chk_rate(); 
update item_supplier_26  
set rate = 5000 
where itemno = 1; 
-



---------------------------------------------------- SLIP  - 27 ------------------------------------------------------------------ 
Q1]  Section II: Database Management Systems II      
Consider the following database : 
Student (rollno integer, name varchar(30),class varchar(10)) 
Subject(Scode varchar(10),subject name varchar(20)) 
[15 Marks] 
Student and subject are related with M-M relationship with attributes marks_scored. 
Q2) Using above Database Solve the following  
[10 Marks] 
1. Write a stored function using cursors, to accept class from the user and display the details of the 
students of that class. 
OR 
1. Write a trigger before insert/update the marks_scored. Raise exception if Marks are 
negative. 
2. Write a procedure to accept and display addition, subtraction and division of two numbers. Handle 
division by zero error for division operation. (Use raise). 


create table stud27(rollno int primary key,s_name varchar(20),class varchar(20)); 
create table sub27(scode int primary key,sub_name varchar(15)); 
create table stud_sub27(rollno int references stud11(rollno),scode int references sub11(scode),marks int); 
insert into stud27 values(1,'amit','SY'),(2,'riya','TY'),(3,'neha','FY'); 
insert into sub27 values(101,'DS'),(102,'DBMS'); 
insert into stud_sub27 values(1,101,75),(2,102,80),(3,101,50); 
create or replace function chk_marks() returns trigger as $$ 
begin 
if NEW.marks < 0 then 
raise exception 'Marks Cannot be Negative'; 
end if; 
return NEW; 
end; 
$$ language plpgsql; 
create trigger trg_chk_marks 
before insert or update on stud_sub27 
for each row 
execute function chk_marks(); 
insert into stud_sub27 values(2,101,-70); 



----------------------------------------------------- SLIP  - 28 ------------------------------------------------------------------ 
Q1]  Section II: Database Management Systems-II      
[15 Marks] 
Consider the following database : 
Company (Name varchar(30),address (50),city varchar(20), share_value money) 
Person (pname varchar(30),pcity varchar (20)) 
Company and Person are related with M to M relationship with descriptive attribute No_of_shares 
Q2) Using above Database Solve the following  
[10 Marks] 
1) Write a stored function to update the share_values by 20% for Person “ ”. 
OR 
1) Write a trigger before deleting company record. Display appropriate message to the user. 
2) Write a procedure to insert the values in person table. 


create table comp28(name varchar(20) primary key,address varchar(25),city varchar(20),share_value money); 
create table person28 (pname varchar(20) primary key,pcity varchar(20)); 
create table comp_person28(name varchar(20) references comp28(name),pname varchar(20) references person28(pname),no_of_shares int); 
insert into comp28 values('TCS','mumbai road','mumbai',1000),('Infosys','hinjewadi','pune',1200); 
insert into person28 values('amit','nashik'),('sneha','pune'); 
insert into comp_person28 values('TCS','amit',50),('Infosys','sneha',30),('TCS','sneha',20); 
create or replace function del_record() returns trigger as $$ 
begin 
raise notice 'Company Record is Deleted Successfully'; 
return OLD; 
end; 
$$ language plpgsql; 
create trigger trg_del_record 
before delete on comp28 
for each row 
execute function del_record(); 
select * from comp28; 
delete from comp28 where name = 'TCS';



 ----------------------------------------------------- SLIP  - 29 ------------------------------------------------------------------ 
Q1]  Section II: Database Management Systems II       
Consider the following database 
Person (pno int, pname varchar (20), birthdate date, income money) 
Area (aid int,aname varchar (20), area_type varchar (5) ) 
[15 Marks] 
The person and area related to many to one relationship. The attribute ‘area_type’ can 
have values either ‘urban’ or ‘rural’. 
Q2) Using above Database Solve the following  
1) Write a cursor to display the names of persons living in urban area. 
OR 
[10 Marks] 
1) Write a trigger before deleting a person's record from the person's table. Raise a notice and display 
the message “person record is being deleted”. 
2) Write a procedure to accept three numbers from user and display maximum and minimum of 
three numbers.     


create table area29(aid int primary key,aname varchar(20),area_type varchar(5) check (area_type in ('urban','rural'))); 
create table person29(pno int primary key,pname varchar(20),birthdate date,income money,aid int,foreign key(aid) references area29(aid)); 
insert into area29 values (1,'nashik','urban'),(2,'sinner','rural'),(3,'pune','urban'); 
insert into person29 values (101,'amit','1998-05-12',25000,1),(102,'amit','1999-07-15',30000,2),(103,'amit','2000-02-10',20000,3),(104,'pooja','1998-11
20',28000,1); 
create or replace function del_record() returns trigger as $$ 
begin 
raise notice 'Person Record is Deleted Successfully'; 
return OLD; 
end; 
$$ language plpgsql; 
create trigger trg_del_record 
before delete on person29 
for each row 
execute function del_record(); 
select * from person29; 
delete from person29 where pno = 101;




 ----------------------------------------------------- SLIP  - 30 ------------------------------------------------------------------ 
Q1]  Section II: Database Management Systems II      
Consider the following database 
Student (Roll_No int, Sname varchar (20), Sclass char (10)) 
Teacher (T_No int, Tname char (20), Experience int) 
[15 Marks] 
Student and Teacher are related with many to many relationship with the descriptive attribute 
Subject. 
Q2) Using above Database Solve the following  
[10 Marks] 
1) Write a stored function to count the number of teachers having experience > 10 years 
OR 
1) Write a trigger before insert the record of the student in the Student table. If the Roll_No is less 
than or equal to zero then the trigger gets fired and displays the message “Invalid Roll Number”. 
2) Write a procedure to accept value of n from user and find sum and average of first n 
numbers.      

create table stud30(rollno int primary key,sname varchar(20),sclass varchar(10)); 
create table tea30(t_no int primary key,tname varchar(20),experience int); 
create table stud_sub30(rollno int references stud30(rollno),t_no int references tea30(t_no),subject varchar(15)); 
insert into stud30 values(1,'amit','FY'),(2,'neha','SY'),(3,'rohit','TY'); 
insert into tea30 values(101,'yogesh chavan',10),(102,'madhuri patil',5); 
insert into stud_sub30 values(1,101,'DS'),(2,102,'DBMS'),(3,101,'Maths'); 
create or replace function chk_roll_no() returns trigger as $$ 
begin 
if NEW.rollno <= 0 then 
raise exception 'Invalid Roll Number'; 
end if; 
return NEW; 
end; 
$$ language plpgsql; 
create trigger trg_chk_roll_no 
before insert on stud30 
for each row 
execute function chk_roll_no(); 
select * from stud30; 
insert into stud30 values(-20,'megha','FY');

