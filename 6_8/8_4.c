#include<stdio.h>
void wap(int *,int *);
int main()
{
    int a,b,c;
    int *aa=&a,*bb=&b,*cc=&c;
    scanf("%d%d%d",aa,bb,cc);
    if(*aa<*bb) wap(aa,bb);
    if(*bb<*cc) wap(bb,cc);
    if(*aa<*bb) wap(aa,bb);
    printf("%d %d %d\n",*aa,*bb,*cc);
    return 0;
}
void wap(int *a,int *b)
{
    int t;
    t=*a;
    *a=*b;
    *b=t;
}
