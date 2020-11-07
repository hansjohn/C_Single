#include <stdio.h>
#include <string.h>
void PutBlank(int n)
{
    int i=0;
	for(i=0;i<n;i++)
    {
        printf(" ");
    }
}
void WriteIn(char * str)
{
    int blank;
    printf("|");
    if((38-strlen(str)+1)%2==0)
    {
        blank=(38-strlen(str)+1)/2;
        PutBlank(blank);
        while(*str!='\n')
        {
            printf("%c",*str);
            str++;
        }
        PutBlank(blank);
        printf("|\n");
        return;
    }
    else
    {
         blank=(38-strlen(str))/2;
         PutBlank(blank+1);
        while(*str!='\n')
        {
            printf("%c",*str);
            str++;
        }
        PutBlank(blank);
        printf("|\n");
        return;
    }
    
    
}
void Underline(void)
{
	int i;
	for(i=0;i<40;i++)
	{
		printf("=");
	}
	printf("\n");
 } 

int main ()
{
    int zip_code;
    char recipient[42];
    char address[42];
    char sender[42];
    int blank;
    
    scanf("%d",&zip_code);
    getchar();
    fgets(recipient,40,stdin);
    fgets(address,40,stdin);
    fgets(sender,40,stdin);
    Underline();
    blank=40-printf("| %d",zip_code)-1;
    PutBlank(blank);

    printf("|\n");        //完成第二行
    WriteIn(recipient);  //写第三行
    WriteIn(address);

    printf("|");
    PutBlank(37-strlen(sender)+1);
    char *str=sender;
    while(*str!='\n')
        {
            printf("%c",*str);
            str++;
        }
    printf(" |\n");
    Underline();
    return 0;

}
