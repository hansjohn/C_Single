#include <stdio.h>
#include <math.h>
#include <string.h>

int main()
{
    char s[10000],c,fw[1000];

    while(scanf("%s",s)!=EOF)
    {
        getchar();
        int i=-1,j=0;

        while(1)
        {
            scanf("%c",&s[++i]);
            if(s[i]=='#'&&s[i-1]=='#'&&s[i-2]=='#') break;
            if(s[i]=='\n')
            {
                if(s[i-1]=='\n'&&i-1>=0) s[i-1]='\0';
            }
            if(s[i]=='/'&&s[i-1]=='/')
            {
                gets(fw);
                if(s[i-2]!='\n') s[i-1]='\n';
                else i--;
                i--;
            }
            if(s[i]=='*'&&s[i-1]=='/')
            {
                while(1)
                {
                    if( (c=getchar())=='*' )
                        if( (c=getchar())=='/' )
                            break;
                }
                i-=2;
            }

        }

        if(s[0]=='\n') j=1;
        for(;j<=i-3;j++) if(s[j]!='\0') printf("%c",s[j]);
    }

    return 0;
}