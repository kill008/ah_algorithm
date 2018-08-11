#include<stdio.h>
#include<stdlib.h>

struct cards
{
    int head;
    int tail;
    int ar[1000];
};

struct table
{
    int top;
    int ar[10];
};
void act(struct cards *player,struct table *now)
{
    now->ar[now->top]=player->ar[player->head];
    now->top++;
    player->head++;
    int i,t=0;
    for (i=0;i<now->top-1;i++)
    {
        if (now->ar[i] == now->ar[now->top-1])
        {
            t=i;
            win(player,now,t);
            break;
        }
    }
    //show(player,now);
}
void win(struct cards *player,struct table *now,int t)
{
    //把牌取走
    int i;
    for (i=0;i<(now->top)-t;i++)
    {
        player->ar[player->tail+i]=now->ar[t+i];
    }
    //取牌完成
    //队列和栈操作
    player->tail=player->tail+(now->top)-t;
    now->top=t;
    //show(player,now);
}
void show(struct cards *player,struct table *now)
{
    int i;
    printf("a cards:\n");
    for (i=player->head;i<player->tail;i++)
    {
        printf("%d",player->ar[i]);
    }
    printf("\n");
    printf("cards on the table:\n");
    for (i=0;i<now->top;i++)
    {
        printf("%d",now->ar[i]);
    }
    printf("\n");
}
int main(int argc, char const *argv[])
{
    struct cards a,b;
    struct table m;
    a.head=0;
    a.tail=6;
    b.head=0;
    b.tail=6;
    m.top=0;
    m.ar[m.top]=0;
    int i;
    for (i=0;i<6;i++)
    {
        scanf("%d",&a.ar[i]);
    }
    for (i=0;i<6;i++)
    {
        scanf("%d",&b.ar[i]);
    }
    while (a.head!=a.tail-1 && b.head != b.tail-1)
    {
        act(&a,&m);//a先出牌
        printf("a cards:\n");
        for (i=a.head;i<a.tail;i++)
        {
            printf("%d",a.ar[i]);
        }
        printf("\n");
        printf("cards on the table:\n");
        for (i=0;i<m.top;i++)
        {
            printf("%d",m.ar[i]);
        }
        printf("\n");
        act(&b,&m);//b后出牌
        printf("b cards:\n");
        for (i=b.head;i<b.tail;i++)
        {
            printf("%d",b.ar[i]);
        }
        printf("\n");
        printf("cards on the table:\n");
        for (i=0;i<m.top;i++)
        {
            printf("%d",m.ar[i]);
        }
        printf("\n");
    }

    if (a.head == a.tail-1)
    {
        printf("b win\n");
    }
    if (b.head == b.tail-1)
    {
        printf("a win\n");
    }
    system("pause");
    return 0;
}
