#include <stdio.h>
int zhuanhuan(char *a,double *b);//返回-1转换失败,0成功
int main(){
    printf("请输入两个数字：\n");
    while(1)
    {
        int i;
        char aa[100],bb[100];
        double a,b;
        double c,d,e,f;
        int boola,boolb;
        scanf("%s%s",aa,bb);
        boola=zhuanhuan(aa,&a);
        boolb=zhuanhuan(bb,&b);
        if(boola==-1)  printf("字符串\"%s\"无法转换成数字！\n",aa);
        if(boolb==-1)  printf("字符串\"%s\"无法转换成数字！\n",bb);
        if(boola||boolb)
        {
            printf("请重新输入两个数字 ：\n");
            continue;
        }
        printf("%g+%g=%g\n%g-%g=%g\n%g*%g=%g\n%g/%g=%g\n",a,b,a+b,a,b,a-b,a,b,a*b,a,b,a/b);
        break;
    }
}
int zhuanhuan(char aa[],double *a)
{
    int i=0,n=0;
    int point=0;
    double df=0.1;// decimal fraction
    while(aa[n]!='\0') n++; //所得n为包括小数点在内的总长度
    point=n;
    for(i=0;i<n;i++)
    {
        if(aa[i]=='.')
        {
            point=i;
            break;
        }
    }
    //验证输入是否合法
    if(point<n) //有小数点的情况
    {
        for(i=0;i<point;i++) if(aa[i]<'0'||aa[i]>'9') return -1;
        for(i=point+1;i<n;i++) if(aa[i]<'0'||aa[i]>'9') return -1;
    }
    else for(i=0;i<n;i++) if(aa[i]<'0'||aa[i]>'9') return -1;   //无小数点的情况


    *a=0;
    for(i=0;i<point;i++) *a=*a*10+aa[i]-'0';
    if(point<n)
    {
        for(i=point+1;i<n;i++)
        {
            *a+=df*(aa[i]-'0');
            df*=0.1;
        }

    }
    return 0;
}
