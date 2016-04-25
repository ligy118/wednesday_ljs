#include<stdio.h>
int main()
{
    double cj[4][5];
    int i,j;
    for(i=0;i<3;i++)
    for(j=0;j<4;j++) scanf("%lf",&cj[i][j]);
    for(i=0;i<3;i++) cj[i][4]=cj[i][0]+cj[i][1]+cj[i][2]+cj[i][3];
    for(j=0;j<4;j++)  cj[3][j]=(cj[0][j]+cj[1][j]+cj[2][j])/3;
    for(i=0;i<3;i++)
    {
            for(j=0;j<3;j++) printf("%lf ",cj[i][j]);
            printf("%lf\n",cj[i][3]);
    }
    for(i=0;i<3;i++)
    {
        for(j=0;j<4;j++) printf("%lf ",cj[i][j]);
        printf("%lf\n",cj[i][4]);
    }
        for(j=0;j<3;j++) printf("%lf ",cj[3][j]);
        printf("%lf\n",cj[3][3]);
    return 0;
}
