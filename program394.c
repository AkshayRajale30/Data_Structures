#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;       // $
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void InsertFirst(PPNODE first,int no)
{}

void InsertLast(PPNODE first,int no)
{}

void InsertAtPos(PPNODE first,int no,int pos)
{}

void DeleteFirst(PPNODE first)
{}

void DeleteLast(PPNODE first)
{}

void DeleteAtPos(PPNODE first,int pos)
{}

void Display(PNODE first)
{}

void Count(PNODE first)
{
    return;
}

int main()
{
    PNODE head = NULL;

    return 0;
}