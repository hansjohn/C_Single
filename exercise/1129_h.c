//长整数乘法
#include <stdio.h>
#include <string.h>
int num(char a)
{
    return a-48;
}
int main ()
{
    char a[21],b[21];
    int c[22],a1,b1,i,j,temp,flag=0;
    while(scanf("%s%s",a,b)!=EOF)
    {
        getchar();
        a1=strlen(a);
        b1=strlen(b);
        for(i=0;a1>0&&b1>0;a1--,b1--,i++)
        {
            temp=num(a[a1-1])+num(b[b1-1])+flag;
            if(temp>=10)
            {
                c[i]=temp-10;
                flag=1;
            }
            else
            {
                c[i]=temp;
                flag=0;
            }  
        }
        if(flag==1&&a1==b1)
        {
            c[i]=1;
            flag=0;
        }
        else{
        if(a1>b1)
        {
            for(;a1>0;a1--,i++)
            {
                c[i]=(num(a[a1-1])+flag)%10;
                flag=num(a[a1-1])+flag>9;
            }
        }
        if(a1<b1)
        {
            for(;b1>0;b1--,i++)
            {
                c[i]=(num(b[b1-1])+flag)%10;
                flag=num(b[b1-1])+flag>9;
            }
        }
            if(flag==1)
            {
                c[i]=1;
                flag=0;
            }
            else
            {
                i-=1;
            }
        }
        for(;i>=0;i--)
        {
            printf("%d",c[i]);
        }
        printf("\n");
    }
    return 0;
}