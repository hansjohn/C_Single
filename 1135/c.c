#include <stdio.h>
#include <string.h>
int main()
{
    int n,x;
    char name[100];
    scanf("%d",&n);
    for(int j=0;j<n;j++)
    {
        scanf("%d",&x);
        for(int i=0;i<x;i++)
        {
            int flag=1;
            scanf("%s",name);
            int len=strlen(name);
            if(name[0]=='_'||(name[0]>='A'&&name[0]<='Z')||(name[0]>='a'&&name[0]<='z'))
            {
                for(int k=1;k<len;k++)
                {
                    if(name[k]=='_'||(name[k]>='A'&&name[k]<='Z')||(name[k]>='a'&&name[k]<='z')||(name[k]>='0'&&name[k]<='9'));
                    else
                    {
                        flag=0;
                    }
                    
                }
                
                
            }
            else
                {
                    flag=0;
                }
            if(flag==1)
            {
                printf("1");
            }
            else printf("0");
            if(i<x-1)
            {printf(" ");}
            else if(i==x-1)
            {
                printf("\n");
            }
            flag=1;
        }
    }
    return 0;
}