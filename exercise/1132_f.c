#include <stdio.h>
int main()
{
    int a;
    while(scanf("%d",&a)!=EOF)
    {
        int count=0;
        while(a!=1)
        {
            if(a%2==0)
            {
                a/=2;
                count++;
            }
            else
            {
                a=a*3+1;
                count++;
            }
        }
        printf("%d\n",count);
    }
}