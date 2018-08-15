//走迷宫
#include<stdio.h>
#include<stdlib.h>


struct node
{
    int x;
    int y;
    int step;
};

int main(int argc, char const *argv[])
{
    int map[5][4]={0},book[5][4]={0};//地图和已经走过的点
    int i,j,k,n=0;
    for (i=0;i<5;i++)
    {
        for (j=0;j<4;j++)
        {
            printf("%d ",map[i][j]);
        }
        printf("\n");
    }
    struct node que[21];
    int head=0,tail=0,tx=0,ty=0,flag=0;
    que[tail].x=0;
    que[tail].y=0;
    que[tail].step=0;
    tail++;
    book[0][0]=1;
    int next[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
    while (head<tail)
    {
        for (k=0;k<4;k++)
        {
            tx=que[head].x+next[k][0];
            ty=que[head].y+next[k][1];
            if (tx<0 || tx>4 || ty<0 || ty>4)
            {
                continue;
            }
            if (book[tx][ty] == 0)
            {
                que[tail].x=tx;
                que[tail].y=ty;
                que[tail].step=que[head].step+1;
                tail++;
                book[tx][ty]=1;
            }
            if (tx==2 && ty==2)
            {
                flag=1;
                break;
            }
        }
        head++;
        if (flag==1)
        {
            break;
        }
    }
    printf("%d\n",que[tail-1].step);
    system("pause");
    return 0;
}
