 #include <stdio.h>
main()
{ int i,j,a=0;
for(i=0;i < 2;i++)
{ for (j=0; j < 4; j++)
{if (j%2) break;
a++;
}
a++;
}
printf("%d\n", a);
}