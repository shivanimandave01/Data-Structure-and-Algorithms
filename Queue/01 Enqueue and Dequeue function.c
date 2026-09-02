#include<stdio.h>
#include<conio.h>
#define Max 7

int Queue[Max];
int Front = 0;
int Rear = 0;

int Is_Queue_Empty()
{
    if(Rear == Front)
    {
        return 1;
    }
    return 0;
}

int Is_Queue_Full()
{
    if(Rear == Max)
    {
        return 1;
    }
    return 0;
}

void Enqueue(int No)
{
    if(Is_Queue_Full())
    {
        printf("\n Queue is Full.... Not Inssert into Queue. ");
    }
    else
    {
        Queue[Rear] = No;
        Rear++;
    }
}
void Dequeue()
{
    if(Is_Queue_Empty())
    {
        printf("\n Queue is Already Empty.... ");
    }
    else
    {
        printf("\n %d Element is Deleted from Queue",Queue[Front]);

        Queue[Front] = 0;
        Front++;
    }
}
int main()
{
    Enqueue(12);
    Dequeue();

    getch();
    return 0;
}
