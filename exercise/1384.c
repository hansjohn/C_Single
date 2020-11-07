/* 
描述
火车从始发站（称为第1站）开出，在始发站上车的人数为a，然后到达第2站，在第2站有人上、下车，但上、下车的人数相同，
因此在第2站开出时（即在到达第3站之前）车上的人数保持为a人。从第3站起（包括第3站）上、下车的人数有一定规律：上车
的人数都是前两站上车人数之和，而下车人数等于上一站上车人数，一直到终点站的前一站（第n-1站），都满足此规律。现给
出的条件是：共有N个车站，始发站上车的人数为a，最后一站下车的人数是m（全部下车）。试问x站开出时车上的人数是多少？
输入
每个测试文件只包含一组测试数据，每组输入四个整数a、n、m和x。
输出
对于每组输入数据，输出从x站开出时车上的人数。 */

#include <stdio.h>
int Add(int a,int b,int x)
{
    if(x==1) return a;
    else if(x==2) return 0;
    else if(x==3) return a;
    else if(x==4) return b;
    else if(x>=5) return (Add(a,b,x-1)+Add(a,b,x-2));
}

int main(void)
{
    int a,n,m,x;
    int sum=0;
    scanf("%d %d %d %d",&a,&n,&m,&x);
    int i;
    int b;
    
    for(b=1;sum!=m;b++)
    {
        sum=0;
        for(i=1;i<n;i++)
        {
            sum+=Add(a,b,i);
        }
        
    }
    b--;
    sum=0;
    for(i=1;i<=x;i++)
    {
        sum+=Add(a,b,i);     
    }
    printf("%d\n",sum);
    return 0;

}