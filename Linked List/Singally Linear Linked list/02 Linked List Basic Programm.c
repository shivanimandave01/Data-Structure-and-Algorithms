#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Node{
    int Data;
    struct Node *Next;
};

void Insert_Last(struct Node **sPtr,int No)
{
    struct Node *NewN = NULL;

    NewN = (struct Node*) malloc (sizeof(struct Node));

    NewN -> Data = No;
    NewN -> Next = NULL;


    if(*sPtr == NULL)
    {
        printf("\nAdd %d When Linked list is already empty.",NewN->Data);
        *sPtr = NewN;
    }
    else
    {
        struct Node *Temp = *sPtr;

        while(Temp->Next != NULL)
        {
            Temp = Temp -> Next;
        }
        Temp -> Next = NewN;

        printf("\nAdd %d in linked list.",NewN->Data);
    }
    return;
}
int main()
{
    struct Node *Head = NULL;

    Insert_Last(&Head,200);
    Insert_Last(&Head,400);
    getch();
    return 0;
}
