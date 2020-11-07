#include <stdio.h>
#include <math.h>
#include <string.h>
int main()
{
    int strcmpp(char *a, char *b);
    void jian(char *x, char *y);
    char a[505], b[255], q[255];
    while (scanf("%s %s", a, b) != EOF)
    {
        char s[505] = {'\0'};
        int i = 0, ii = 0, l, shang = 0;
        if (a[0] == '0')
        {
            printf("0 0\n");
            continue;
        }
        if (b[0] == '0')
        {
            printf("%s 0\n", a);
            continue;
        }
        if (strcmpp(a, b) < 0)
        {
            printf("%s 0\n", a);
            continue;
        }
        while (strcmpp(s, b) < 0)
        {
            s[i] = a[i];
            i++;
        }
        s[i] = '\0';
        while (strcmpp(s, b) >= 0)
        {
            jian(s, b);
            shang++;
        }
        q[ii++] = shang + '0';
        q[ii] = '\0';
        while (a[i] != '\0')
        {
            shang = 0;
            l = strlen(s);
            s[l] = a[i++];
            s[l + 1] = '\0';
            while (strcmpp(s, b) >= 0)
            {
                jian(s, b);
                shang++;
            }
            q[ii++] = shang + '0';
            q[ii] = '\0';
        }
        if (s[0] == '\0')
            printf("0 %s", q);
        else
            printf("%s %s", s, q);
        printf("\n");
    }
    return 0;
}
void jian(char *x, char *y)
{
    int a[505] = {0}, b[505] = {0}, i, j = 0;
    int la = strlen(x), lb = strlen(y);
    for (i = 0; i < la; i++)
        a[i] = x[la - 1 - i] - '0';
    for (i = 0; i < lb; i++)
        b[i] = y[lb - 1 - i] - '0';
    for (i = 0; i < la; i++)
        a[i] -= b[i];
    for (i = 0; i < la; i++)
    {
        if (a[i] < 0)
        {
            a[i] += 10;
            a[i + 1]--;
        }
    }
    for (; i >= 0; i--)
        if (a[i])
            break;
    for (; i >= 0; i--)
        x[j++] = a[i] + '0';
    x[j] = '\0';
}
int strcmpp(char *a, char *b)
{
    int i, la, lb;
    la = strlen(a);
    lb = strlen(b);
    if (a[0] == '0' && b[0] == '0')
        return 0;
    if (a[0] == '0')
    {
        for (i = 0; i < la; i++)
            a[i] = a[i + 1];
        la--;
    }
    if (la > lb)
        return 1;
    if (la < lb)
        return -1;
    for (i = 0; i < la; i++)
    {
        if (a[i] > b[i])
            return 1;
        if (a[i] < b[i])
            return -1;
    }
    return 0;
}