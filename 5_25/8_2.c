#include<stdio.h>
#include<math.h>
void cha(int *,int);
int main()
{
    int a[20],b,i;
    for (i=0;i<7;i++) a[i]=-1*pow(10,7-i);
    for (i=7;i<15;i++) a[i]=pow(10,i-7);
    for(i=0;i<15;i++) printf("%d ",a[i]);
    printf("\n");
    scanf("%d",&b);
    cha(a,b);
    for(i=0;i<16;i++) printf("%d ",a[i]);
    printf("\n");
    return 0;
}
void cha(int a[],int b)
{
    int t,tt,i,j;
    for(i=0;i<15;i++)
    {
        if(a[i]<b&&a[i+1]>=b)
        {
            t=b;
            for(j=i+1;j<16;j++)
            {
                tt=a[j];
                a[j]=t;
                t=tt;
            }

        }
    }
    return ;
}
