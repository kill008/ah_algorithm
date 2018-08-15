//放炸弹
#include<stdio.h>
#include<stdlib.h>


struct node
{
    int x;
    int y;
};

int ener(int map[][13],int x,int y)
{
    int count=0,m=x,n=y;
    while (map[m][n]!=1)//向右
    {
        if (map[m][n]==2)
        {
            count++;
        }
        n++;
    }
    n=y;
    while (map[m][n]!=1)//向下
    {
        if (map[m][n]==2)
        {
            count++;
        }
        m++;
    }
    m=x;
    while (map[m][n]!=1)//向左
    {
        if (map[m][n]==2)
        {
            count++;
        }
        n--;
 
    }
    n=y;
    while (map[m][n]!=1)//向上
    {
        if (map[m][n]==2)
        {
            count++;
        }
        m--;
        
    }

    return count;
}
int main(int argc, char const *argv[])
{
    //地图输入
    int map[13][13]={{1,1,1,1,1,1,1,1,1,1,1,1,1},
                     {1,2,2,3,2,2,2,1,2,2,2,3,1},
                     {1,1,1,3,1,2,1,2,1,2,1,2,1},
                     {1,3,3,3,3,3,3,3,1,3,3,2,1},
                     {1,2,1,3,1,1,1,3,1,2,1,2,1},
                     {1,2,2,3,2,2,2,3,1,3,2,2,1},
                     {1,2,1,3,1,2,1,3,1,3,1,3,1},
                     {1,1,2,3,3,3,2,3,3,3,3,3,1},
                     {1,2,1,3,1,2,1,1,1,3,2,2,1},
                     {1,3,3,3,2,1,2,2,2,3,2,2,1},
                     {1,2,1,3,1,2,1,2,1,3,1,2,1},
                     {1,2,2,3,2,2,2,1,2,3,2,2,1},
                     {1,1,1,1,1,1,1,1,1,1,1,1,1}};
    int i,j;
    //输入结束
    //炸弹初始化
    int book[13][13]={0};
    int head=1,tail=1,tx=0,ty=0,goal=0,k,x1=0,y1=0,num=0;
    struct node boom[170];
    boom[tail].x=3;
    boom[tail].y=3;
    tail++;
    book[0][0]=1;
    int next[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
    while (head<tail)
    {
        for (k=0;k<4;k++)
        {
            tx=boom[head].x+next[k][0];
            ty=boom[head].y+next[k][1];

            if (tx<0 || tx>13 || ty<0 || ty>13)
            {
                continue;
            }
            if (map[tx][ty]==3 && book[tx][ty]==0)//1是墙，2是人,3是空地
            {
                boom[tail].x=tx;
                boom[tail].y=ty;
                book[tx][ty]=1;
                tail++;
                num=ener(map,tx,ty);
                if (num>goal)
                {
                    goal=num;
                    x1=tx;
                    y1=ty;
                }
            }
        }
        head++;
    }
    printf("%d %d\n",x1,y1);
    printf("%d\n",goal);
    system("pause");
    return 0;
}
