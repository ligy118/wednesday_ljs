#include<stdio.h>
void upCopy(char *,char *);
int main()
{
    char a[100],b[100];
    scanf("%s",a);
    upCopy(b,a);
    printf("%s\n%s\n",a,b);
    return 0;
}
void upCopy(char new[],char old[])
{
    int n=0,i;
    for(i=0;;i++)
    {
        if(old[i]!='\0')
        {
            if(old[i]>='A'&&old[i]<='Z') new[n++]=old[i];
        }
        else
        {
            new[n]='\0';
            return ;
        }
    }
}
