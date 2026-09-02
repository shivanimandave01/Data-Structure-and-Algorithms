#include<stdio.h>
#include<conio.h>
#define Size 7

int Student[Size];
int Front = 0;
int Rear = 0;

int Is_Admission_Full()
{
    if(Rear == Front)
    {
        return 1;
    }
    return 0;
}

int Is_Admission_None()
{
    if(Rear == Size)
    {
        return 1;
    }
    return 0;
}

void Add_Student(int No)
{
    if(Is_Admission_Full())
    {
        printf("\n Queue is Full.... Not Inssert into Queue. ");
    }
    else
    {
        Student[Rear] = No;
        Rear++;
    }
}
void Delete_Student()
{
    if(Is_Admission_None())
    {
        printf("\n Queue is Already Empty.... ");
    }
    else
    {
        printf("\n %d Element is Deleted from Queue",Student[Front]);

        Student[Front] = 0;
        Front++;
    }
}

void Show_List()
{
    int i = 0;

    printf("\n Elements in Queue is: \n\t\t");

    for(i = Front;i < Rear;i++)
    {
        printf("\t %d",Student[i]);
    }
}

int main()
{
    Add_Student(12);
    Add_Student(20);
    Show_List();
    Delete_Student();

    getch();
    return 0;
}
