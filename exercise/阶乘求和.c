#include <stdio.h>

int factorial(int n)
{
    int i;
    int sum = 1;
    for(i=1;i<=n;i++)
    {
        sum *= i;
    }
    return sum;
}
int main()
{
    int n;
    int sum = 0;
    scanf("%d",&n);
    if(n>0)
    {
        while(n>0)
        {
            sum += factorial(n);
            n--;
        }
    }
    printf("%d",sum);
    return 0;
}

