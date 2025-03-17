#include<stdio.h>
#include<stdlib.h>
typedef struct list
{
    int data;
    struct list *next;
}sl;
sl* insert(sl *head)
{
    sl *p=NULL;
    p=(sl*)malloc(sizeof(sl));
    if(p==NULL)
        printf("Memory unavilable\n");
    else
    {
        printf("Enter data:\n");
        scanf("%d",&p->data);
        p->next=head;
        head=p;
    }
    return head;
}
sl* del(sl *head)
{
    sl *p=NULL;
    p=head;
    head=head->next;
    free(p);
    return(head);
}
sl* del_rev(sl *head)
{
    sl *p=NULL;
    p=head;
    while(p!=NULL)
    {
        if(p->next==NULL)
        {
            p->next=NULL;
        }
        p=p->next;
    }
    return(head);
}
void display(sl *head)
{
    sl *p=NULL;
    p=(sl*)malloc(sizeof(sl));
    if(p==NULL)
        printf("Memory unavilable\n");
    else
    {
        p=head;
        while(p!=NULL)
        {
            printf("%d ",p->data);
            p=p->next;
        }
        printf("\n");
    }
}
void dis_rev(sl *head)
{
    if(head==NULL)
        return;
    else
    {
        int t=head->data;
        dis_rev(head->next);
        printf("%d\n",t);
    }
}
int main()
{
    sl *head=NULL;
    int ch;
    do
    {
        printf("1.Insert\n2.Delete\n3.Display\n4.Delete Reverse\n5.Display Reverse\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                head=insert(head);
                break;
            case 2:
                head=del(head);
                break;
            case 3:
                display(head);
                break;
            case 4:
                head=del_rev(head);
                break;
            case 5:
                dis_rev(head);
                break;
        }
    }while(ch!=6);
    return 0;
}
