/* 描述
写一函数，将两个字符串中的元音字母复制到另一个字符串，然后输出。

输入
一行由小写字符组成的字符串。

输出
顺序输出其中的元音字母（aeiuo）。 */
#include <stdio.h>
#include <string.h>
void get(char *a)
{
    int i=0,j=0;
    for(;i<strlen(a);i++)
    {
        if(a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u')
        {
            printf("%c",a[i]);
        }
    }
    printf("\n");
}
int main()
{
    char a[100];
    while(scanf("%s",a)!=EOF)
    {
        get(a);
        
    }
    
    return 0;
}