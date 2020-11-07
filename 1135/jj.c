#include <stdio.h>
#include <math.h>
#include <string.h>
int main()
{
    int m, n, i, j, k, h = 0, x, y, maxx = 0, maxy = 0;
    scanf("%d%d", &m, &n);
    int a[m][n];
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
            if (a[i][j] > h)
                h = a[i][j];
        }
    char s[500][500];
    for (i = 0; i < 500; i++)
        for (j = 0; j < 500; j++)
            s[i][j] = '.';
    for (k = 0; k < h; k++)
        for (i = 0; i < m; i++)
            for (j = 0; j < n; j++)
            {
                if (a[i][j])
                {
                    a[i][j]--;
                    x = 4 * j + 2 * (m - i - 1);
                    y = 2 * (m - i - 1) + 3 * k;
                    s[x][y] = '+';
                    s[x + 1][y] = '-';
                    s[x + 2][y] = '-';
                    s[x + 3][y] = '-';
                    s[x + 4][y] = '+';
                    s[x][y + 1] = '|';
                    s[x + 1][y + 1] = ' ';
                    s[x + 2][y + 1] = ' ';
                    s[x + 3][y + 1] = ' ';
                    s[x + 4][y + 1] = '|';
                    s[x + 5][y + 1] = '/';
                    s[x][y + 2] = '|';
                    s[x + 1][y + 2] = ' ';
                    s[x + 2][y + 2] = ' ';
                    s[x + 3][y + 2] = ' ';
                    s[x + 4][y + 2] = '|';
                    s[x + 5][y + 2] = ' ';
                    s[x + 6][y + 2] = '+';
                    s[x][y + 3] = '+';
                    s[x + 1][y + 3] = '-';
                    s[x + 2][y + 3] = '-';
                    s[x + 3][y + 3] = '-';
                    s[x + 4][y + 3] = '+';
                    s[x + 5][y + 3] = ' ';
                    s[x + 6][y + 3] = '|';
                    s[x + 1][y + 4] = '/';
                    s[x + 2][y + 4] = ' ';
                    s[x + 3][y + 4] = ' ';
                    s[x + 4][y + 4] = ' ';
                    s[x + 5][y + 4] = '/';
                    s[x + 6][y + 4] = '|';
                    s[x + 2][y + 5] = '+';
                    s[x + 3][y + 5] = '-';
                    s[x + 4][y + 5] = '-';
                    s[x + 5][y + 5] = '-';
                    s[x + 6][y + 5] = '+';
                    if (x + 6 > maxx)
                        maxx = x + 6;
                    if (y + 5 > maxy)
                        maxy = y + 5;
                }
            }
    for (i = maxy; i >= 0; i--)
    {
        for (j = 0; j <= maxx; j++)
            printf("%c", s[j][i]);
        printf("\n");
    }
    return 0;
}