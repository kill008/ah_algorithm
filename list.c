//链表
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int value;
    struct node *next;
};

int main(int argc, char const *argv[])
{
    struct node *head=NULL;
    struct node *p,*q,*t,*s;
    int n,i;
    scanf("%d",&n);
    for (i=0;i<n;i++)
    {
        p=(struct node*)malloc(sizeof(struct node));
        scanf("%d",&p->value);
        p->next=NULL;
        if (head==NULL)
        {
            head=p;
        }
        else
        {
            q->next=p;
        }
        q=p;
    }
    t=head;
    while (t != NULL)
    {
        printf("%d ",t->value);
        t=t->next;
    }
    s=(struct node*)malloc(sizeof(struct node));
    scanf("%d",&s->value);
    s->next=NULL;
    t=head;
    while(t!=NULL)
    {
        if (t->next->value > s->value)
        {
            s->next=t->next;
            t->next=s;
            break;
        }
        t=t->next;
    }
    t=head;
    while (t != NULL)
    {
        printf("%d ",t->value);
        t=t->next;
    }
    system("pause");
    return 0;
}
