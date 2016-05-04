#include<stdio.h>
int gcd(int,int);
int mul(int,int,int);
int main()
{
    int a,b,gcdab,mulab;
    scanf("%d%d",&a,&b);
    gcdab=gcd(a,b);
    mulab=mul(a,b,gcdab);
    printf("gcd: %d\nmul: %d\n",gcdab,mulab);
    return 0;
}
int gcd(int a,int b)
{
    if(a%b==0) return b;
    return gcd(b,a%b);
}
int mul(int a,int b,int c)
{
    return a*b/c;
}
