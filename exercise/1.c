#include<stdio.h>
int add(int a,int n,int Y)   //函数求上车的人数，参数：a第一站上车人数，第n站，第二站上车人数为Y；
{
    if(n==1)
        return a;
    else if(n==2)
        return 0;
    else if(n==3)
        return a;
    else if(n==4)
        return Y;
    else if(n>=5)
        return (add(a,n-1,Y)+add(a,n-2,Y));   //递归算法
}
int main()
{
    int a,n,m,x,sum=0,i,j,Y;
    scanf("%d%d%d%d",&a,&n,&m,&x);
    for(Y=1;;Y++)       //第二站上车人数从1个人开始循环，一个一个试，直到试出来；
    {
        sum=0;
        for(i=1;i<n;i++)
        {
            sum+=add(a,i,Y);
        }
        if(sum==m)     //如果满足条件，Y就是第二站上车人数；
            break;
    }
    sum=0;
    for(i=1;i<=x;i++)
    {
        sum+=add(a,i,Y);     //求出第x站车上的人数
    }
    printf("%d\n",sum);
    return 0;
}