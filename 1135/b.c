#include <stdio.h>
#include <string.h>
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    char a[1000];
    int xinhao = 0;
    while (scanf("%s", a) != EOF)
    {
        getchar();
        if (a[0] == '#' && a[2] == '#' && a[1] == '#')
        {
            fgets(a, 998, stdin);
            while (strlen(a)<3||(!(a[0] == '#' && a[2] == '#' && a[1] == '#')))
            {
                if (a[0] == '\n')
                {
                    fgets(a, 998, stdin);
                    continue;
                }
                for (int i = 0; i < strlen(a); i++)
                {
                    if (xinhao == 0)
                    {
                        if (a[i] == '/')
                        {
                            if (a[i + 1] == '/')
                            {
                                if(i!=0){a[i] = '\n';
                                a[i + 1] = '\0';}
                                else{a[i]='\0';}
                                printf("%s", a);
                                break;
                            }
                            else if (a[i + 1] == '*')
                            {
                                xinhao = 1;
                                if(i!=0){a[i] = '\n';
                                a[i + 1] = '\0';}
                                else{a[i]='\0';}
                                a[++i] = '\0';
                                i++;
                                printf("%s", a);
                            }
                        }
                        else if (a[i] == '\n')
                        {
                            printf("%s", a);
                        }
                    }
                    else
                    {
                        if (a[i] != '*')
                            continue;
                        else
                        {
                            if (a[++i] == '/')
                            {
                                xinhao = 0;int j=0;
                                for(;j+i+1<strlen(a);j++)
                                {
                                    a[j]=a[j+i+1];
                                }
                                a[j]='\0';
                            }
                        }
                    }
                }
                fgets(a, 998, stdin);
            }
        }
    }
    return 0;
}