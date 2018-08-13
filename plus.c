#include<stdio.h>
#include<stdlib.h>

int book[10];
int ar[10];

void plus(int step)
{
    int i;
    for (i=1;i<10;i++)
    {
        if (book[i]==0)
        {
            ar[step]=i;
            book[i]=1;
            plus(step+1);
            book[i]=0;
        }
    }
    if (step == 10)
    {
        if (100*ar[1]+10*ar[2]+ar[3]+100*ar[4]+10*ar[5]+ar[6] == 100*ar[7]+10*ar[8]+ar[9])
        {
            printf("%d %d %d + %d %d %d=%d %d %d\n",ar[1],ar[2],ar[3],ar[4],ar[5],ar[6],ar[7],ar[8],ar[9]);
            //return;
        }
        return;
    }
}
int main(int argc, char const *argv[])
{
    plus(1);
    system("pause");
    return 0;
}
