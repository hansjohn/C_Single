#include <stdio.h>
#include <string.h>
#include <math.h>
struct memu
{
    char name[30];
    int number;
};
void line(int n)
{
    int i = 1;
    for (; i <= n; i++)
    {
        printf("-");
    }
}
void print_memu(struct memu a, float* fee)
{
    switch (a.name[0])
    {
    case 'D':
        printf("Dried bean curd     x");
        printf("%-2d%5.1f\n", a.number, a.number * 3.0);
        *fee += a.number * 3.0;
        break;
    case 'P':
        printf("Potato              x");
        printf("%-2d%5.1f\n", a.number, a.number * 2.5);
        *fee += a.number * 2.5;
        break;
    case 'F':
        printf("Fried beef pepper   x");
        printf("%-2d%5.1f\n", a.number, a.number * 7.0);
        *fee += a.number * 7.0;
        break;
    case 'L':
        printf("Lotus root soup     x");
        printf("%-2d%5.1f\n", a.number, a.number * 4.0);
        *fee += a.number * 4.0;
        break;
    case 'S':
        printf("Sauteed lettuce     x");
        printf("%-2d%5.1f\n", a.number, a.number * 2.5);
        *fee += a.number * 2.5;
        break;
    case 'R':
        printf("Rice                x");
        printf("%-2d%5.1f\n", a.number, a.number * 1.0);
        *fee += a.number * 1.0;
        break;
    default:
        break;
    }
}
int main()
{
    char rest_name[30];
    struct memu MEMU[6];
    int i = 0, j = 0, len;
    float fee=0;
    fgets(rest_name, 31, stdin);
    while (rest_name[j] != '\n')
    {
        j++;
    }
    rest_name[j] = '\0';
    while (fgets(MEMU[i].name, 29, stdin) != NULL)
    {
        len = strlen(MEMU[i].name);
        MEMU[i].number = 0;
        int s = len - 2, count = 0;
        while (MEMU[i].name[s] != ' ')
        {
            MEMU[i].number += (MEMU[i].name[s] - '0') * pow(10, count);
            count++;
            s--;
        }
        while (MEMU[i].name[len] != ' ')
        {
            MEMU[i].name[len] = '\0';
            len--;
        }
        MEMU[i].name[len] = '\0';
        i++;
    }
    printf("        #1 MT Takeaway\n\n");
    if (strlen(rest_name) % 2 == 0)
    {
        line((28 - strlen(rest_name)) / 2);
        printf(" %s ", rest_name);
        line((28 - strlen(rest_name)) / 2);
        printf("\n");
    }
    else
    {
        line((28 - strlen(rest_name)) / 2 );
        printf(" %s ", rest_name);
        line((28 - strlen(rest_name)) / 2+ 1);
        printf("\n");
    }
    int k = 0;
    for (; k <= i; k++)
    {
        print_memu(MEMU[k], &fee);
    }
    printf("Delivery fees: 4\n");
    fee += 4;
    printf("------------------------------\n");
    printf("                Total:");
    printf("%6.1f\n", fee);
    return 0;
}