#include<stdio.h>
int main()
{
    int n,a[11][11],b,i,j,max=-10000000,maxn,min=100000000,minn;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
            if(a[i][j]>max)
            {
                maxn=i;
                max=a[i][j];
            }
            if(a[i][j]<min)
            {
                minn=i;
                min=a[i][j];
            }
        }
    for(i=0;i<n;i++)
    {
        b=a[maxn][i];
        a[maxn][i]=a[minn][i];
        a[minn][i]=b;
    }
    for(i=0;i<n;i++)
        {for(j=0;j<n-1;j++) printf("%d ",a[i][j]);printf("%d\n",a[i][n-1]);}
    return 0;
}
