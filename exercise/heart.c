#include <stdio.h>
#include <stdlib.h>
int main()
{
    /* system("color fc");//改成红色 */
    int i, j;
    printf("     ******       ******\n"
           "   **********   **********\n"
           " ************* *************\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 29; j++)
            printf("*");
        printf("\n");
    }
    for (i = 0; i < 7; i++)
    {
        for (j = 0; j < 2 * (i + 1) - 1; j++)
            printf(" ");
        for (j = 0; j < 27 - i * 4; j++)
            printf("*");
        printf("\n");
    }
    for (i = 0; i < 14; i++)
        printf(" ");
    printf("*\n");
    return 0;
}
