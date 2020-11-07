#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int num(char a)//转化成数字
{
    return a-48;
}
int * mult(char a[],int alenth,int n)
{
    
    int i=alenth-1;
    int carry=0;
    int * p=(int *)malloc((alenth+1)*sizeof(int));
    for(;i>=0;i--)
    {
        p[i+1]=(num(a[i])*n+carry)%10;
        carry=(num(a[i])*n+carry)/10;
    }
    if(carry!=0)
    {
        p[0]=carry;
    }
    else
    {
        p[0]=0;
    }
    return p;
}
void add(int  c[],int b[],int alenth,int pos)//pos指从哪一位加
{
    int i=999-pos+1,j=alenth,temp;
    int carry=0;
    for(;j>=0;j--,i--)
    {
        temp=(b[j]+c[i]+carry);
        c[i]=temp%10;
        carry=temp/10;
    }
    if(carry!=0)
    {
        c[i]+=carry;
    }
}

int main()
{
    char a[501],b[501];
    int c[1000]={0};
    while(scanf("%s%s",a,b)!=EOF)
    {
        getchar();
        if(b[0]=='0')
        {
            printf("0\n");
            continue;
        }
        int c[1000]={0};
        int alenth,blenth;
        alenth=strlen(a);
        blenth=strlen(b);
        int * p;
        int i=blenth-1,j=1;
        for(;i>=0;i--,j++)
        {
            p=mult(a,alenth,num(b[i]));
            add(c,p,alenth,j);
        }
        i=0;
        while(c[i]==0)
        {
            i++;
        }
        for(;i<=999;i++)
        {
            printf("%d",c[i]);
        }
        printf("\n");
        free(p);
    }
    return 0;
}