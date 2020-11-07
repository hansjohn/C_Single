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
int main()
{
    int nian = 0, yue = 0, ri = 0, h = 0, m = 0, s = 0;
    int ribian = 0, hbian = 0, mbian = 0, sbian = 0;
    char fuhao;
    scanf("%4d-%2d-%2d %2d:%2d:%2d %c %d %2d:%2d:%2d", &nian, &yue,
          &ri, &h, &m, &s, &fuhao, &ribian, &hbian, &mbian, &sbian);
    pand(nian);
    if (fuhao == '-')
    {
        s -= sbian;
        if (s < 0)
        {
            s += 60, m -= 1;
        }
        m -= mbian;
        if (m < 0)
        {
            m += 60;
            h -= 1;
        }
        h -= hbian;
        if (h < 0)
        {
            h += 24;
            ri -= 1;
        }
        ri -= ribian;
        while (ri <= 0)
        {
            yue -= 1;
            if (yue <= 0)
            {
                yue += 12;
                nian -= 1;
                pand(nian);
            }
            ri += y[yue];
        }
    }
    if (fuhao == '+')
    {
        s += sbian;
        if (s >= 60)
        {
            s -= 60, m += 1;
        }
        m += mbian;
        if (m >= 60)
        {
            m -= 60;
            h += 1;
        }
        h += hbian;
        if (h >= 24)
        {
            h -= 24;
            ri += 1;
        }
        ri += ribian;
        while (ri > y[yue])
        {
            ri -= y[yue];
            yue += 1;
            if (yue >= 13)
            {
                yue -= 12;
                nian += 1;
                pand(nian);
            }
        }
    }
    printf("%04d-%02d-%02d %02d:%02d:%02d\n", nian, yue, ri, h, m, s);
    return 0;
}