#include <stdio.h>

int main ()
{
    freopen("in.txt","w",stdout);
        for (int i=0; i<4; i++)
            for (int i2=0; i2<4; i2++)
                for (int i3=0; i3<4; i3++)
                    for (int i4=0; i4<4; i4++)
                        printf("%d %d %d %d\n",i,i2,i3,i4);
}