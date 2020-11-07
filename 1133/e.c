#include <stdio.h>
int shushu(long long a)
{
    if(a==1)
    {
        return 0;
    }
    else
    {
        for(int i=2;i<a;i++)
        {
            if(a%i==0)
            {
                return 0;
            }
        }
        return 1;
    }
}
int main()
{
    int a,d,n;
    while(scanf("%d%d%d",&a,&d,&n)!=EOF)
    {
        long long sum =a-d;
        int i=0;
        while(i<n)
        {
            if(shushu(sum+=d))
            {
                i++;
            }
        }
        printf("%lld\n",sum);
    }

}