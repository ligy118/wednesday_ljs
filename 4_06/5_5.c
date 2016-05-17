#include<stdio.h>
#include<string.h>
int main()
{
    char a[100];
    int n,i;
    int shu=0,da=0,xiao=0,qita=0;
    printf("请输入待统计字符串,以回车键结束: ");
    scanf("%s",a);
    n=strlen(a);
    for(i=0;i<n;i++)
    {
        if(a[i]>=48&&a[i]<=57) shu++;
        else if(a[i]>=65&&a[i]<=90) da++;
                    else if(a[i]>=97&&a[i]<=122) xiao++;
                                else qita++;
    }
    printf("%d %d %d %d\n",shu,da,xiao,qita);
    return 0;
}
