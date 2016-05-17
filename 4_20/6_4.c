#include<stdio.h>
int zb(int,int,int,int *);
int main()
{
    int a[20],h,i,j,dc,ans;
    for(i=0;i<20;i++) scanf("%d",&a[i]);
    for(i=0;i<19;i++)
        for(j=i;j<19;j++) if(a[j]>a[j+1])
            {
                h=a[j];
                a[j]=a[j+1];
                a[j+1]=h;
            }
    scanf("%d",&dc);
    ans=zb(dc,0,19,a);
    if(ans<0) printf("Not found\n");
    else printf("%d\n",ans+1);
    return 0;
}
int zb(int dc,int left,int right,int a[])
{
//    printf("%d %d\n",left,right);
    if(a[(left+right)/2]==dc) return (left+right)/2;
    if(left==right) return -1;
    if(a[(left+right)/2]<dc) return zb(dc,(left+right)/2+1,right,a);
    if(a[(left+right)/2]>dc) return zb(dc,left,(left+right)/2-1,a);
}
