#include<stdio.h>
int main()
{
    char a[10][100];
    int b[10],i,sum=0;
    double ping=0;
    for(i=0;i<10;i++)
    {
        scanf("%s%d",a[i],&b[i]);
        sum+=b[i];
    }
    ping=sum/10.0;
    printf("平均成绩：%lf\n",ping);
    for(i=0;i<10;i++) if(b[i]>ping) printf("%s\n",a[i]);
    return 0;
}
