#include <stdio.h>
#include <math.h>
int main()
{
    int i=0,temp,min,pos;
    int a[10];
    for(i=0;i<10;i++)
    {
        scanf("%d",&temp);
        a[i]=temp;
        if(i==0)
        {
            min=temp;
            pos=0;
        }
        else
        {
            if(abs(temp)<abs(min))
            {
                min=temp;
                pos=i;
            }
        }
    }
    temp=a[9];
    a[9]=a[pos];
    a[pos]=temp;
    for(i=0;i<9;i++)
    {
        printf("%d ",a[i]);
    }
    printf("%d",a[9]);
    return 0;
}
