#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
    int Data;
    struct node *Next;
};

void insert_First(struct node **SPtr,int Num)
{
    struct node *NewN = NULL;

    NewN = (struct node*)malloc(sizeof(struct node));

    NewN -> Data = Num;
    NewN -> Next = NULL;

    if(*SPtr == NULL)
    {
        *SPtr = NewN;
    }
    else
    {
        NewN -> Next = *SPtr;
        *SPtr = NewN;
    }
}
void Display(struct node *Show)
{
    if(Show == NULL)
    {
        printf("\n Linked List is Empty");
    }
    else
    {
        while(Show -> Next != NULL)
        {
            printf("| %d |->",Show -> Data);
            Show = Show-> Next;
        }
        printf("Null");
    }
}
int main()
{
    struct node *Head = NULL;

    insert_First(&Head,101);
    insert_First(&Head,26);
    insert_First(&Head,56);
    Display(Head);
    getch();
    return 0;
}
