#include<stdio.h>
int mulNum(int,int);
int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    if(mulNum(a,b)) printf("%d is a multiple of %d\n",a,b);
    else printf("%d is not a multiple of %d\n",a,b);
    return 0;
}
int mulNum(int a,int b)
{
    if(a%b) return 0;
    else return 1;
}
