#include <stdio.h>
int main()
{
    char c[100];
    while(scanf("%s",c)!=EOF)
    {
        if(c[0]='#')
        {
            int cnt=0;int i;
            fgets(c,100,stdin);
            while(c[0]!='#')
            {
                i=0 ;
                while (c[i]!='\n')
                {
                    if((c[i]>='a'&&c[i]<='z')||(c[i]>='A'&&c[i]<='Z'))
                    {cnt++;
                    break;}
                    i++;
                }
                
                fgets(c,100,stdin);
            }
            printf("%d\n",cnt);
        }
    }
    return 0;
}