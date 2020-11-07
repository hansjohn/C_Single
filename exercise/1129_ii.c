#include <stdio.h>
int main()
{
    long a,b,n,last,i;
    long temp;
    while(scanf("%ld%ld%ld",&a,&b,&n)!=EOF)
    {
        int p[105]={0};
        p[0]=a/b;
        temp=a%b;
        for(i=1;i<=n+1;i++)
        {
            temp*=10;
            if(temp/b!=0)
            {
                p[i]=temp/b;
                temp=temp%b;
            }
            else
            {
                p[i]=0;
            }
        }
        i=n;
        if(p[n+1]>=5)
        {
            while(++p[i]>9&&i>0)
            {
                p[i]=p[i]%10;
                i--;
            }
            if(i=0)    //注意while退出有两种情况
            {
                p[0]++;
            }
        }
        printf("%ld",p[0]);
        if(n==0)
        {
            printf("\n");
        }
        else
        {
            printf(".");
            for(i=1;i<=n;i++)
            {
                printf("%ld",p[i]);
            }
        printf("\n");
        } 
    }
    return 0;
}