#include <stdio.h>
int main()
{
    char ch;
    while (ch = getchar() != EOF)
    {
        getchar();
        char line[1005];
        char word[100];
        char zhuowen[10000];
        while (1)
        {
            fgets(line, 1000, stdin);
            if (line[0] == '#')
            {
                break;
            }
            else
            {
                int i = 0, j = 0;
                while (line[j] != '\n')
                {
                    if (line[j] == ' ')
                    {
                        i--;
                        for (; i >= 0; i--)
                        {
                            printf("%c", word[i]);
                        }
                        i = 0;
                        printf(" ");
                    }
                    else
                    {
                        word[i] = line[j];
                        i++;
                    }
                    j++;
                }
                i--;
                for (; i >= 0; i--)
                {
                    printf("%c", word[i]);
                }
                printf("\n");
            }
        }
    }
    return 0;
}