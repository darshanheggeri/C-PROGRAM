#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define size 10
void push(int);
void pop();
void display();
int stack[size],top=-1;
void main()
{
    int choice,value;
    while(1){
        printf("enter your choice");
        printf("\n1.push\n2.pop\n3.display\n4.exit\n");
        scanf("%d",&choice);
        switch(choice){
        case 1:
            printf("enter the value to insert\n");
            scanf("%d",&value);
            push(value);
            break;
        case 2 :
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("invalid choice");
        }
    }
}
void push(int value)
{
    if(top==size-1)
    {
        printf("stack is full");
    }
    else
    {
        top++;
        stack[top]=value;
        printf("insertion success\n");
    }
}
void pop()
{
    if(top==-1)
        printf("stack is empty");
    else
    {
        printf("\ndeleted:%d",stack[top]);
        top--;
    }
}
void display()
{
    if(top==-1)
        printf("stack is empty");
    else
    {
        int i;
        printf("stack elements are:\n");
        for(i=top;i>0;i--)
            printf("%d",stack[i]);
    }

}
