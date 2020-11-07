#include <stdio.h>
int y[13] = {31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int pand(int nian)
{
    if (nian % 4 == 0 && nian % 100 != 0 || nian % 400 == 0)
        y[2] = 29;
    else
        y[2] = 28;
    return 0;
}
int zhenchangnian(char c, int a)
{
    switch (c)
    {
    case 'M':
        return 1868 + a;
        break;
    case 'T':
        return 1912 + a;
        break;
    case 'S':
        return 1926 + a;
        break;
    case 'H':
        return 1989 + a;
        break;
    case 'R':
        return 2019 + a;
        break;
    default:
        break;
    }
}
int main()
{
    while()
}