#include<stdio.h>
void cat(char *,char *,char *);
int len(char *);
int main()
{
    char a[1000],b[1000],c[2005];
    int an,bn,cn;
    while(~scanf("%s%s",a,b))
    {
        cat(a,b,c);
        an=len(a);
        bn=len(b);
        cn=len(c);
        printf("%d %s\n%d %s\n%d %s\n",an,a,bn,b,cn,c);
    }
    return 0;
}
int len(char *a)
{
    int i;
    for(i=0;a[i]!='\0';i++) ;
    return i;
}
void cat(char *a,char *b,char *c)
{
    int an,bn,cn,i,j;
    an=len(a);
    bn=len(b);
    for(i=0;i<an;i++) c[i]=a[i];
    for(j=0;j<bn;j++) c[i+j]=b[j];
    c[i+j]='\0';
}
