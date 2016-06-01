#include<stdio.h>
void catStr(char *,char *);
int main ()
{
    char a[100],b[100];
    scanf("%s%s",a,b);
    printf("%s\n%s\n",a,b);
    catStr(a,b);
    printf("\n%s\n",a);
    return 0;
}
void catStr(char a[],char b[])
{
    int na,nb,i,j;
    for(na=0;*(a+na)!='\0';na++);
    for(nb=0;*(b+nb)!='\0';nb++);
    for(i=0;i<nb;i++) *(a+i+na)=*(b+i);
    *(a+na+nb)='\0';
    return ;
}
