#include <stdio.h>
int Leapyear(int a)
{
	int flag=0;
	if(a%4==0)
	{
		if(a%100!=0)
		{
			return 1;
			flag=1;
		}
		else
		{

			if(a%400==0)
			{
				return 1;
				flag=1;
			}
		}

	}
	if(flag==0)
	{
		return 0;
	}
}
int main()
{
	int year,month,day,i,j,sum=0;
	int mon[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	while(scanf("%d%d%d",&year,&month,&day)!=EOF)
	{
		sum=0;
		if(Leapyear(year))
		{
			mon[2]=29;
		}
		else
		{
			mon[2]=28;
		}
		
		for(i=1;i<month;i++)
		{
			sum+=mon[i];
		}
		sum+=day;
		printf("%d\n",sum);
	}
	return 0;
}