#include <stdio.h>
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int cnt=0;
        char c;
        getchar();
        for(int i=0;i<n;i++)
        {
            scanf("%c",&c);
            if(c=='(')
            {
                cnt++;
            }
            else if(c==')')
            {
                cnt--;
            }
            if(cnt<0)
                for(;i<n;i++)
                    getchar();
        }
        if(cnt==0)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
    return 0;
}