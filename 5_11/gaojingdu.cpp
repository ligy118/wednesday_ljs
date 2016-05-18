//不给数据规模，差评！
//就当模拟做了
//乘法有效范围极其有限
//除法，因为用到了乘法，所以有效范围也有限
#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
void cinnn(int *,int *); //输入函数
void coutt(int *); //输出函数
int com(int *,int *); // 比较函数 return 0 left大,1 right 大
void add(int *,int *,int *);// +
void sub(int *,int *,int *);// -
void mul(int *,int *,int *);// *
void div(int *,int *,int *);// /
int main()
{
    int i,j,k;
    int left[100]={0},right[100]={0};
    int addans[100]={0},subans[100]={0},mulans[100]={0},divans[100]={0};
    cinnn(left,right);
    /*coutt(left);
    printf("\n");
    coutt(right);
    printf("\n");*/
    add(left,right,addans);
    printf("加法运算的结果: ");
    coutt(addans);
    printf("\n");
    sub(left,right,subans);
    printf("减法运算的结果: ");
    coutt(subans);
    printf("\n");
    mul(left,right,mulans);
    printf("乘法运算的结果: ");
    coutt(mulans);
    printf("\n");
    div(left,right,divans);
    printf("除法运算的结果: ");
    coutt(divans);
    printf("\n");
    return 0;
}
void cinnn(int left[],int right[])
{
    char a[100],b[100];
    char *tapoint,*tbpoint;
    int an,bn,apoint,bpoint;
    int i,j,k;
    scanf("%s%s",a,b);
//  cout<<a<<endl<<b<<endl;
    an=strlen(a);
    bn=strlen(b);
    tapoint=strchr(a,'.');
    tbpoint=strchr(b,'.');
    if(tapoint) apoint=tapoint-a;
    else apoint=an;
    if(tbpoint) bpoint=tbpoint-b;
    else bpoint=bn;
//  cout<<an<<"   "<<bn<<endl;
//  cout<<apoint<<"   "<<bpoint<<endl;
    for(i=19-apoint+1;i<=19;i++) left[i]=a[i-20+apoint]-'0';
    for(i=20;i<20+an-apoint-1;i++) left[i]=a[i-20+1+apoint]-'0';
    for(i=19-bpoint+1;i<=19;i++) right[i]=b[i-20+bpoint]-'0';
    for(i=20;i<20+bn-bpoint-1;i++) right[i]=b[i-20+1+bpoint]-'0';
}
void coutt (int a[])
{
    int st=29,en=0;
    int i;
    if(a[35]) printf("-");
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
void add(int a[],int b[],int ans[])
{
    int jinwei=0;
    int i,j,k;
    for(i=29;i>=0;i--)
    {
        ans[i]=a[i]+b[i]+jinwei;
        jinwei=ans[i]/10;
        ans[i]-=jinwei*10;
    }
}
void sub(int a[],int b[],int ans[])
{
    int jinwei=0;
    int i,j,k;
    if(com(a,b))
    {
        ans[35]=1;
        sub(b,a,ans);
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
    for(i=0;i<30;i++)
            for(j=0;j<200;j++) aans[i][j]=0;
    for(i=29;i>=0;i--)
    {
        jinwei=0;
        for(j=29;j>=0;j--)
        {
            aans[i][100+j+i-19]=a[j]*b[i]+jinwei;
            jinwei=aans[i][100+j+i-19]/10;
            aans[i][100+j+i-19]-=jinwei*10;
        }
    }
    for(i=0;i<30;i++)
            for(j=0;j<30;j++) aans[i][j]=aans[i][j+100];
    for(i=0;i<30;i++) add(aans[i],ans,ans);
}
void div(int a[],int b[],int ans[])
{
    int i,j,k;
    int vvv[28][35]={0};
    int chengji[35]={0};
    int aans[35]={0};
    for(i=1;i<28;i++) vvv[i][i]=1;

    for(i=1;i<28;i++)
    {
        for(;;)
        {
            add(aans,vvv[i],aans);
            for(j=0;j<30;j++) chengji[j]=0;
            mul(aans,b,chengji);
//        cout<<i<<"  aans: ";coutt(aans);cout<<endl;
//            cout<<"chengji: ";coutt(chengji);cout<<endl;

            if(!com(a,chengji))
            {
                for(k=0;k<30;k++) ans[k]=aans[k];

            }
            else
            {
                sub(aans,vvv[i],aans);
                break;
            }
        }
    }
}
