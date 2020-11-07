#include <stdio.h>
#include <string.h>
int main()
{
    char a[4];
    int ge,shi,bai,num;
    while(scanf("%s",a)!=EOF)
    {
        int i = strlen(a);
        if (i==1)
            num=(a[0]-'0');
        else if(i==2)
            num=(a[1]-'0')*10+(a[0]-'0');
        else if(i==3)
            num=(a[2]-'0')*100+(a[1]-'0')*10+(a[0]-'0');
        printf("%d\n",num);
    }
    return 0;
}