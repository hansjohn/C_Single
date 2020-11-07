#include <stdio.h>
#include <math.h>
int main()
{
    
    int a,b,c,i,yushu,zhengshu;
    while(scanf("%d%d%d",&a,&b,&c)!=EOF)
    {
       int xiaoshudian[c+1];
       if(a%b==0)
       {
           printf("%d.",a/b);
           for(i=1;i<=c;i++)
           {
               printf("0");
           }
           printf("\n");
       }
       else
       {
            zhengshu=a/b;
            i=0;
            while(i!=c+1)
            {
                while(a/b>0 && i==0)
                {
                    a=a-(a/b)*b;
                }
                a*=10;
                xiaoshudian[i]=a/b;
                a=a-(a/b)*b;
                i++;
            }
            printf("%d.",zhengshu);
            for(i=0;i<c-1;i++)
           {
               printf("%d",xiaoshudian[i]);
           }
           if(xiaoshudian[c]>=5)
           {
           	printf("%d",xiaoshudian[c-1]+1);
		   }
		   else printf("%d",xiaoshudian[c-1]);
           printf("\n");
       }
    }
    return 0;
}
