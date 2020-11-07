#include <stdio.h>
#include <stdlib.h>
int main() {
    int a,b,c,i,n;
    while(scanf("%d%d%d",&a,&b,&c)!=EOF) 
    {
        int p[102]={0},q[102]={0};
        n=a/b;
        p[0]=a%b;
        for(i=0;i<=c;i++)
        {
            if(10*p[i]>=b)
                {
                    q[i]=10*p[i]/b;
                    p[i+1]=10*p[i]%b;
                }
            else 
                {
                    q[i]=0;
                    p[i+1]=p[i];     
                }
        }
        if(c!=0)
        {
            if(q[c]>=5)
            {
                q[c-1]++;
                for(i=c-1;i>=0;i--)
        {
            if(i!=0&&q[i]>9)
            {
                q[i-1]++;
                q[i]=q[i]%10;
            }
            if(i==0&&q[0]>9){
                q[0]=q[0]%10;
            n++;break;
            }
        }    
            }
        printf("%d.",n);
        for(i=0;i<c;i++)
        {
            if(i!=c-1)
                printf("%d",q[i]);
            else 
                printf("%d\n",q[i]); 
        }
        }
        else if(q[0]>=5)
        printf("%d\n",n+1);
        else printf("%d\n",n);    
    }
    return 0;
}