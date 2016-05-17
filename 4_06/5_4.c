#include<stdio.h>
#include<math.h>
int main()
{
    int n[4]={20,50,100,200};
    int i,j;
    float pi,sum;
    for(i=0;i<4;i++)
    {
        sum=0;
        for(j=1;j<=n[i];j++) sum+=1.0/j/j;
        printf("n=%d,pi=%f\n",n[i],sqrt(sum*6));
    }
    return 0;
}
