#include<stdio.h>
#define max 5
int push(int arr[],int top)
{
    if(top==max-1)
        printf("OVERFLOW\n");
    else
    {
        printf("Enter element:\n");
        scanf("%d",&arr[++top]);
    }
    return top;
}

int pop(int arr[],int top)
{
    if(top==-1)
        printf("UNDERFLOW\n");
    else
    {
        int x;
        x=arr[top];
        top--;
    }
    return top;
}

void display(int arr[],int top)
{
    if(top==-1)
        printf("UNDERFLOW\n");
    else
    {
        while(top!=-1)
        {
            printf("%d ",arr[top]);
            top--;
        }
        printf("\n");
    }
}

void peek(int arr[],int top)
{
    if(top==-1)
        printf("UNDERFLOW\n");
    else
        printf("Top most value is : %d\n",arr[top]);
}

int main()
{
    int ch,top=-1,arr[max];
    do
    {
        printf("1.INSERT\n2.DELETE\n3.DISPLAY\n4.PEEK\n\5.EXIT\n");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            top=push(arr,top);
            break;
        case 2:
            top=pop(arr,top);
            break;
        case 3:
            display(arr,top);
            break;
        case 4:
            peek(arr,top);
            break;
        }
    }while(ch!=5);
    return 0;
}
