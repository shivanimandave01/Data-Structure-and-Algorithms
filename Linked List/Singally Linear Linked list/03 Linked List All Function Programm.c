#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int Cnt_Ele = 0;

struct Node{
    int Data;
    struct Node *Next;
};

void Insert_First(struct Node **sPtr,int No)
{
    struct Node *NewN = NULL;

    NewN = (struct Node*) malloc (sizeof(struct Node));

    NewN -> Data = No;
    NewN -> Next = NULL;

    if(*sPtr == NULL)
    {
        *sPtr = NewN;
        printf("\n %d inserted at first",NewN -> Data);
    }
    else
    {
        NewN -> Next = *sPtr;
        *sPtr = NewN;
        printf("\n %d inserted at first",NewN -> Data);

    }
    Cnt_Ele++;
    getch();
}


void Insert_Last(struct Node **sPtr,int No)
{
    struct Node *NewN = NULL;

    NewN = (struct Node*) malloc (sizeof(struct Node));

    NewN -> Next = NULL;
    NewN -> Data = No;

    if(*sPtr == NULL)
    {
        *sPtr = NewN;
        printf("\n %d inserted at Last",NewN -> Data);

    }
    else
    {
        struct Node *Temp = *sPtr;

        while(Temp -> Next != NULL)
        {
            Temp = Temp -> Next;
        }
        Temp -> Next = NewN;

        printf("\n %d inserted at Last\n",NewN -> Data);

        Cnt_Ele++;
    }
    getch();
    return;
}


void Delete_First(struct Node **sPtr)
{
    if(*sPtr == NULL)
    {
        printf("\n linked list is Already Empty.\n");
    }
    else
    {
        struct Node *Temp = *sPtr;

        if(Temp ->  Next == NULL)
        {
            *sPtr = NULL;
            free(Temp);
            printf("\n %d delete from first Position",Temp->Data);
        }
        else
        {
            *sPtr = Temp -> Next;
            printf("\n %d delete from first Position",Temp->Data);
            free(Temp);
        }
        Cnt_Ele--;
    }
}


void Delete_Last(struct Node **sPtr)
{
    if(*sPtr == NULL)
    {
        printf("\n linked list is Already Empty.\n");
    }
    else
    {
        struct Node *Temp = *sPtr;

        if(Temp ->  Next == NULL)
        {
            *sPtr = NULL;
            free(Temp);
        }
        else
        {
            while(Temp -> Next -> Next != NULL)
            {
                Temp = Temp -> Next;
            }
            printf("\n %d delete from last Position",Temp->Data);
            Temp -> Next = NULL;
            free(Temp);
        }
        Cnt_Ele--;
    }
}


void Insert_At_Position(struct Node ** sPtr,int Pos,int Val)
{
    struct Node *NewN = NULL;

    NewN = (struct Node*) malloc (sizeof(struct Node));

    if(Pos == 0 || Pos < 0)
    {
        printf("\n Invalid Position");
    }
    else if(Pos == 1)
    {
        Insert_First(sPtr,Val);
    }
    else if(Pos > Cnt_Ele)
    {   char Ch= 0;
        printf("\n No Such Position Exist Can link at %d Position",Cnt_Ele);
        scanf("%c",&Ch);

        if(Ch == "Yes")
        {
            Insert_Last(sPtr,Val);
        }
        else
        {
            return;
        }
    }
    else
    {
        struct Node *Temp = *sPtr;
        NewN -> Data = Val;

        while(Pos - 2 == 0)
        {
            Temp = Temp -> Next;
        }
        NewN -> Next = Temp -> Next;
        Temp -> Next = NewN;

        printf("\n %d insert at position %d",NewN->Data,Pos);

        Cnt_Ele++;
    }

}
void Delete_At_Position(struct Node **sPtr,int Pos)
{
     if(Pos == 0 || Pos < 0 || Pos > Cnt_Ele)
    {
        printf("\n Invalid Position");
    }
    else if(Pos == 1)
    {
        Delete_First(sPtr);
    }
    else if(Cnt_Ele == Pos)
    {
       Delete_Last(sPtr);
    }
    else
    {
       struct Node *Temp1 = *sPtr;
       struct Node *Temp2 = *sPtr;

       while(Pos - 2 == 0)
       {
           Temp1 = Temp1 -> Next;
       }
       Temp2 = Temp1 -> Next -> Next;

       printf("\n The %d is Delete from Position %d",Temp2-> Data,Pos);

       free(Temp2);
       Temp1 -> Next = Temp2 -> Next;


       Cnt_Ele--;
    }

}
void Display(struct Node *sPtr)
{
    printf("\n");
    while(sPtr -> Next != NULL)
    {
        printf("| %d | ->",sPtr -> Data);
        sPtr = sPtr ->Next;
    }
    printf("NULL \n");
}
int main()
{
    struct Node *Head = NULL;

    Insert_First(&Head,200);
    Insert_First(&Head,500);

    Insert_Last(&Head,600);
    Insert_Last(&Head,900);
    Display(Head);

    Insert_At_Position(&Head,3,6000);
    Insert_First(&Head,400);

    Display(Head);

    Delete_Last(&Head);
    Delete_At_Position(&Head,3);
    Display(Head);
    Delete_First(&Head);
    Display(Head);
    getch();
    return 0;
}
