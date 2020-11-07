#include <stdio.h>
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
    int mon[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    int year,month,day,hour,min,second,dif_day,dif_hour,dif_min,dif_second,flag;
    char fuhao;
    while(scanf("%d-%d-%d %d:%d:%d%*c%c%*c%d %d:%d:%d",&year,&month,&day,&hour,&min,&second,&fuhao,&dif_day,&dif_hour,&dif_min,&dif_second))
    {
        if(fuhao=='+')
        {
            //秒
            if(second+dif_second>=60)
            {
                min++;
                second=(second+dif_second)%60;
            }
            else{second=(second+dif_second)%60;}
            //分
            if(min+dif_min>=60)
            {
                hour++;
                min=(min+dif_min)%60;
            }
            else{min=(min+dif_min)%60;}
            hour+=dif_hour;
            if(hour>=24)
            {
                hour%=24;
                day++;
            }
            day+=dif_day;
        while (day > mon[month])
        {
            day -= mon[month];
            month += 1;
            if (month >= 13)
            {
                month -= 12;
                month += 1;
                if(leapyear(year))
            {
                mon[2]=29;
            }
            else
            {
                mon[2]=28;
            }
            }
        }
        }
        if(fuhao=='-')
        {
            //秒
            if(second-dif_second<0)
            {
                min--;
                second=(second-dif_second)%60;
            }
            else{second=(second-dif_second)%60;}
            //分
            if(min-dif_min<0)
            {
                hour--;
                min=(min-dif_min)%60;
            }
            else{min=(min-dif_min)%60;}
            hour-=dif_hour;
            if(hour<0)
            {
                hour%=24;
                day--;
            }
            day-=dif_day;
        while (day <= mon[month])
        {
            
            month--;
            if (month >= 13)
            {
                month += 12;
                year--;
                if(leapyear(year))
            {
                mon[2]=29;
            }
            else
            {
                mon[2]=28;
            }
            }
            if(leapyear(year))
            {
                mon[2]=29;
            }
            else
            {
                mon[2]=28;
            }
        }
        }
        printf("%04d-%02d-%02d %02d:%02d:%02d\n",year,month,day,hour,min,second);

    }
}




