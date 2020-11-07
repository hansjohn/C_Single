#include <stdio.h>
int main()
{
    int one=0 ,zero=0,a=0;
    int i=1,num,temp;
    for ( i = 1; i < 1001; i++)
    {
        one=0 ;zero=0;
        num=i;
        while(num!=0)
        {
            temp=num%2;
            num/=2;
            if(temp==1)
            {
                one++;
            }
            else zero++;
        }
        if (one>zero)
        {
            a++;
        }

    }
    printf("%d %d\n",a,1000-a);
    
}