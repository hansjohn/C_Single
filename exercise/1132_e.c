
#include <stdio.h>
#include <math.h>
int leapyear(int a)
{
    int flag = 0;
    if (a % 4 == 0)
    {
        if (a % 100 != 0)
        {
            return 1;
            flag = 1;
        }
        else
        {
            if (a % 400 == 0)
            {
                return 1;
                flag = 1;
            }
        }
    }
    if (flag == 0)
    {
        return 0;
    }
}
int main()
{
    int year, month, day, month_day[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    while (scanf("%d", &year) != EOF)
    {

        if (leapyear(year))
        {
            month = 1;
            day = 1;
            int i = 1;
            while (1)
            {
                if (((sqrt(year + month * 31 + day)) == (int)sqrt(year + month * 31 + day)))
                {
                    printf("%d %d %d\n", year, month, day);
                    break;
                }
                else
                {

                    if (month == 12 && day == 31)
                    {
                        printf("no leap day\n");
                        break;
                    }
                    else if (day == month_day[i])
                    {
                        day = 1;
                        i++;
                        month++;
                    }
                    else
                    {
                        day++;
                    }
                }
            }
        }
        else
        {
            printf("no leap day\n");
        }
    }
    return 0;
}