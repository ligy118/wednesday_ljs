//乘法如果结果整数部分超过20位，小数部分超过10位，计算结果是不对的
//除法因为用到了乘法，因为其中一些运算，精度更低，又懒的算，直接限定了输入的范围
//啊啊啊老师后来改要求了 不用分开写整数除法，三个函数什么的额，把除法搞出来就行了
#include<stdio.h>
#include<string.h>
int cinnn(int *); //输入函数，返回-1程序结束 返回0输入成功
void coutt(int *); //输出函数
int com(int *,int *); // 比较函数 return 0 left大,1 right 大  范围两个正数
void add(int ,int ,int *,int *,int *);// +
void sub(int ,int ,int *,int *,int *);// -
void mul(int *,int *,int *);// *
int div(int *,int *,int *);// /    被除数为0 返回-1；除法正常运算 返回0；
//有关符号，0为正，1为负
//除法注释在最后
int q=1;
int main()
{
    int aaaaa;
    int status;
    int i,j,k;
    int left[31],right[31];
    int addans[31],subans[31],mulans[31],divans[31];
    int divstatus; //divstatus 除法的状态（除数为0的情况）
	printf("可以输入整数，小数，负数，但请不要输入错误的数据调戏~\n\n");
    while(1)
    {
        for(i=0;i<31;i++) left[i]=right[i]=addans[i]=subans[i]=mulans[i]=divans[i]=0;
        printf("输入两个大于/小于 正/负10^-4，小于/大于 正/负10^9的实数，以空格或者换行隔开，或者输入q离开\n");
        status=cinnn(left);
        if(status==-1) {printf("bye~\n");return 0;}
        cinnn(right);
        add(left[30],right[30],left,right,addans);
        printf("加法运算的结果: ");
        coutt(addans);
        printf("\n");
        sub(left[30],right[30],left,right,subans);
        printf("减法运算的结果: ");
        coutt(subans);
        printf("\n");
        mul(left,right,mulans);
        printf("乘法运算的结果: ");
        coutt(mulans);
        printf("\n");
        divstatus=div(left,right,divans);
        if(divstatus) printf("被除数不能为0!\n");
        else
        {
            printf("除法运算的结果: ");
            coutt(divans);
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}
int cinnn(int in[])
{
    char a[31];
    char *point;
    int n,intn;
    int i,j,k;
    scanf("%s",a);
    if(a[0]=='q'||a[0]=='Q') return -1;
    if(a[0]=='-')
    {
        in[30]=1;
        i=0;
        while(a[i]!='\0')
        {
            a[i]=a[i+1];
            i++;
        }
    }
    n=strlen(a);
    point=strchr(a,'.');
    if(point) intn=point-a;
    else intn=n;
    for(i=19-intn+1;i<=19;i++) in[i]=a[i-20+intn]-'0';
    for(i=20;i<20+n-intn-1;i++) in[i]=a[i-20+1+intn]-'0';
    return 0;
}
void coutt (int a[])
{
    int st=29,en=0;
    int i;
    if(a[30]) printf("-");
    for(i=0;i<30;i++) if(a[i]!=0) {st=i;break;}
    for(i=29;i>=0;i--) if(a[i]!=0) {en=i;break;}
    for(i=st;i<20;i++) printf("%d",a[i]);
    if(st>=20) printf("0");
    if(en>=20)
    {
        printf(".");
        for(i=20;i<30&&i<=en;i++) printf("%d",a[i]);
    }
}
int com(int a[],int b[])
{
    int i;
    for(i=0;i<30;i++)
    {
        if(a[i]>b[i]) return 0;
        else if(b[i]>a[i]) return 1;
    }
    return 0;
}
void add(int af,int bf,int a[],int b[],int ans[]) //a，b的符号此时由af,bf决定，a[30],b[30]在此函数中无效
{
    int jinwei=0;
    int i,j,k;
    if(af&&bf) ans[30]=1;//两个数都是负数，和一定为负数
    else
    {
        if(af)
        {
            sub(0,0,b,a,ans);
            return ;
        }
        if(bf)
        {
            sub(0,0,a,b,ans);
            return ;
        }

    }

    for(i=29;i>=0;i--)
    {
        ans[i]=a[i]+b[i]+jinwei;
        jinwei=ans[i]/10;
        ans[i]-=jinwei*10;
    }
}
void sub(int af,int bf,int a[],int b[],int ans[])//a，b的符号此时由af,bf决定，a[30],b[30]在此函数中无效
{
    int jinwei=0;
    int i,j,k;
    if(af)
    {
        if(bf)
        {
            sub(0,0,b,a,ans);
            return ;
        }
        else
        {
            add(1,1,a,b,ans);
            return ;
        }

    }
    else if(bf)
    {
        add(0,0,a,b,ans);
        return ;
    }
    else
    {
        ;// 什么事都没有发生，原样继续
    }

    if(com(a,b))
    {
        ans[30]=1;
        sub(0,0,b,a,ans);
        return ;
    }
    for(i=29;i>=0;i--)
    {
        ans[i]=jinwei+a[i];
//        cout<<"! "<<jinwei<<"  "<<a[i]<<" !"<<endl;
        if(ans[i]<b[i])
        {
            ans[i]+=10;
            ans[i]-=b[i];
            jinwei=-1;
        }
        else
        {
            ans[i]-=b[i];
            jinwei=0;
        }
    }
}
void mul(int a[],int b[],int ans[])
{
    int aans[30][200];
    int jinwei=0;
    int i,j,k;
    if(a[30]!=b[30]) ans[30]=1;

    for(i=0;i<30;i++) if(a[i]!=0) break;
    for(j=0;j<30;j++) if(b[j]!=0) break;
        if(i==30||j==30)
        {
            for(i=0;i<30;i++) ans[i]=0;
            return ;
        }
    //0乘任数都为0
    for(i=0;i<30;i++)
            for(j=0;j<200;j++) aans[i][j]=0;
    for(i=22;i>=11;i--)
    {
        jinwei=0;
        for(j=22;j>=11;j--)
        {
            aans[i][j+i-19]=a[j]*b[i]+jinwei;
            jinwei=aans[i][j+i-19]/10;
            aans[i][j+i-19]-=jinwei*10;
        }
    }
    for(i=0;i<30;i++) add(0,0,aans[i],ans,ans);
}
int div(int a[],int b[],int ans[])
{
    int i,j,k,l;
    int vvv[28][31]={0};
    int chengji[31]={0};
    int aans[31]={0};
    for(i=0;i<30;i++) if(b[i]!=0) break;
        if(i==30) return -1;    //0不能作为除数
    for(i=0;i<30;i++) if(a[i]!=0) break;
        if(i==30)
        {
            for(i=0;i<30;i++) ans[i]=0;
            return 0;
        }
    //0除以任何非零数都得零，除法函数成功，返回0
    if(a[30]!=b[30]) ans[30]=1;
    for(i=0;i<28;i++) for(j=0;j<31;j++) vvv[i][j]=0;
    for(i=1;i<28;i++) vvv[i][i]=1;
    for(i=11;i<23;i++)
    {
        for(l=0;l<9;l++)
        {
            add(0,0,aans,vvv[i],aans);
            for(j=0;j<30;j++) chengji[j]=0;
            mul(aans,b,chengji);
            if(!com(a,chengji))
            {
                for(k=0;k<30;k++) ans[k]=aans[k];
            }
            else
            {
                sub(0,0,aans,vvv[i],aans);
                break;
            }
        }
    }
    return 0;
}
/*
就像用笔算，列竖式
  100/3

    先试一千万，ans=ans+100000000   ans*3>100        ans恢复0      ans=ans-100000000
    接着百万，万，千，百
    直至十   ans+=10 ans*3<100
        试20 ans+=10 ans*3<100
        试30 ················
        试40 ans=ans+10             ans*3>100        ans恢复30      ans=ans-10
    接下来试个位 ans=ans+1 (31)     ans*3<100
        试32     ans=ans+1 (32)     ans*3<100
        试33     ans=ans+1 (33)     ans*3<100
        试34     ans=ans+1 (34)     ans*3>100        ans恢复33     ans=ans-1
    接下来试十分位ans=ans+0.1 (33.1) ans*3<100
        试33.2    ans=ans+0.1 (33.2)     ans*3<100
        试33.3    ans=ans+0.1 (33.3)     ans*3<100
        试33.4    ans=ans+0.1 (33.4)     ans*3>100   ans恢复33.3   ans=ans-0.1
    接下来百分位
    。
    。
    。
    。
    。

*/
