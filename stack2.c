#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}sl;

sl* push(sl *top)
{
    sl *p=NULL;
    p=(sl*)malloc(sizeof(sl));
    if(p==NULL)
        printf("Memory Unavilable\n");
    else
    {
        printf("Enter data\n");
        scanf("%d",&p->data);
        p->next=top;
        top=p;
    }
    return top;
}

sl* pop(sl *top)
{
    sl *p=NULL;
    p=(sl*)malloc(sizeof(sl));
    if(top==NULL)
        printf("UNDERFLOW\n");
    else
    {
        p=top;
        top=top->next;
        printf("Data deleted : %d\n",p->data);
        free(p);
    }
    return top;
}

void display(sl *top)
{
    sl *p=NULL;
    p=(sl*)malloc(sizeof(sl*));
    if(p==NULL)
        printf("Memory Unavilable\n");
    if(top==NULL)
        printf("UNDERFLOW\n");
    else
    {
        p=top;
        while(p!=NULL)
        {
            printf("%d ",p->data);
            p=p->next;
        }
        printf("\n");
    }
}

void peek(sl *top)
{
    if(top==NULL)
        printf("UNDERFLOW\n");
    else
        printf("Topmost data is:%d\n",top->data);
}

void stack_in_queue(sl *top)
{
    if(top==NULL)
        printf("UNDRFLOW\n");
    else
    {
        if(top->next!=NULL)
            stack_in_queue(top->next);
        printf("%d ",top->data);
    }
    printf("\n");
}

sl* insert_atlast(sl *top)
{
    sl *p=NULL,*t=NULL;
    p=(sl*)malloc(sizeof(sl));
    t=(sl*)malloc(sizeof(sl));
    if(p==NULL)
        printf("MU\n");
    if(top==NULL)
    {
        printf("Enter data\n");
        scanf("%d",&p->data);
        p->next=NULL;
        top=p;
    }
    else
    {
        t=top;
        while(t->next!=NULL)
            t=t->next;
        printf("Enter data\n");
        scanf("%d",&p->data);
        p->next=NULL;
        t->next=p;
    }
    return top;
}

void alternate(sl *top)
{

    sl *p=top;
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
        if(p!=NULL)
            p=p->next;
    }
    printf("\n");
}

void search(sl *top,int x)
{
    sl *p=top;
    int f=0;
        while(p!=NULL)
        {
            if(p->data==x)
            {
                f=1;
                break;
            }
            p=p->next;
        }
        if(f==1)
            printf("Found\n");
        else
            printf("No\n");
}

int main()
{
    sl *top=NULL;
    int ch;
    do
    {
        printf("1.Push\n2.Pop\n3.Display\n4.Peek\n5.Stack in Queue form(FIFO)\n6.Insert at last\n7.Alternate\n8.Search\n");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            top=push(top);
            break;
        case 2:
            top=pop(top);
            break;
        case 3:
            display(top);
            break;
        case 4:
            peek(top);
            break;
        case 5:
            stack_in_queue(top);
            break;
        case 6:
            top=insert_atlast(top);
            break;
        case 7:
            alternate(top);
            break;
        case 8:
            int x;
            printf("Enter no to be searched:\n");
            scanf("%d",&x);
            search(top,x);
            break;
        }
    }while(ch!=0);
    return 0;
}
