#include <stdio.h>
#include <stdlib.h>
#define maxnum 5
typedef struct a
{
    char stack[maxnum];
    int top;

} sqStack;
void push(sqStack *s, char x) //ÈëÕ»
{
    if (s->top > maxnum - 1)
    {
        printf("ÉÏÒç \n");
    }
    else
    {
        s->top++;
        s->stack[s->top] = x;
    }
}
char pop(sqStack *s) //³öÕ»
{
    char num;
    if (s->top < 0)
    {
        printf("ÏÂÒç \n");
        num = '0';
    }
    else
    {
        num = s->stack[s->top];
        s->top--;
    }
    return (num);
}
struct a *px(sqStack *s)
{
    sqStack *l;
    l = (sqStack *)malloc(sizeof(struct a));
    l->top = -1;
    char temp;
    while (s->top >= 0)
    {
        s->stack[s->top] = temp;
        if (l->top < 0)
        {
            l->top++;
            l->stack[l->top] = temp;
            s->top--;
        }
        else
        {
            if (temp < l->stack[l->top])
            {
                l->top++;
                l->stack[l->top] = temp;
                s->top--;
            }
            else
            {
                s->stack[s->top] = l->stack[l->top];
                l->top--;
                while (temp > l->stack[l->top])
                {
                    s->top++;
                    s->stack[s->top] = l->stack[l->top];
                    l->top--;
                }
                l->top++;
                l->stack[l->top] = temp;
            }
        }
    }
    return (l);
}

int main()
{
    void push(sqStack * s, char x);
    char pop(sqStack * s);
    struct a *px(sqStack * s);
    int max;
    max = 0;
    sqStack *s;

    s = (sqStack *)malloc(sizeof(struct a));

    char x;
    s->top = -1;
    //while(x=getchar()!='\n')
    for (int t = 0; t < maxnum; t++)
    {
        scanf("%c", &x);
        push(s, x);
        max++;
    }

    for (int i = 0; i < max; i++)
    {
        printf("%c", pop(px(s)));
    }
    return 0;
}