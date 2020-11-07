#include <stdio.h>

int main()
{
    int limit1,limit2;
    int a,b;
    int i;
    int num[50];//用数组储存
    int count=0;//计数
    scanf("%d %d %d %d",&limit1,&limit2,&a,&b);
    for(i=limit1;i<=limit2;i++)
    {
        if(i%a==0||i%b==0)
        {
            count++;
            num[count]=i;
        }
    }
    if(count>0)
    {
        printf("Answer:");
        for(i=1;i<=count;i++)
        {
            printf(" %d",num[i]);
        }
        printf(".");
    }
    else 
        printf("NO SOLUTION.");
    return 0;
}
