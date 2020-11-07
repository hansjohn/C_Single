#include <stdio.h>
#include <string.h>
char huabu[1000][1000];

char block[6][7] =
    {
        "..+---+",
        "./   /|",
        "+---+ |",
        "|   | +",
        "|   |/.",
        "+---+.."};
void paint(int x, int y)
{
    for(int i=0;i<7;i++)
        for(int j=0;j<6;j++)
        {
            if(block[5-j][i] != '.')
            huabu[y+j][x+i]=block[5-j][i];
        }
}
int main()
{
    int m, n, j,yy=0;
    memset(huabu, '.', sizeof(huabu));
    scanf("%d %d", &m, &n);
    for (int a = 0; a < m; a++)
    {
        for (int b = 0; b < n; b++)
        {
            scanf("%d", &j);
            yy=yy>(m-1-a)*2+3*j+2?yy:(m-1-a)*2+3*j+2;
            for (int c = 0; c < j; c++)
            {
                paint(4* b+(m - a - 1) *2, (m - a - 1) *2 + 3 * c);
            }
        }
    }
    for(int i=yy;i>=0;i--)
    {
        int xx=1+4*n+2*m;
        for(int j=0;j<xx;j++)
        {
            printf("%c",huabu[i][j]);
        }
        printf("\n");
    }
    return 0;

}