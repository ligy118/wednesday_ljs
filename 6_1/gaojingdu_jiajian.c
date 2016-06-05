//都写了完整的了还要再拆开好蛋疼啊
#include<stdio.h>
#include<string.h>
void cinnn(int *,int *); //输入函数
void coutt(int *); //输出函数
int com(int *,int *); // 比较函数 return 0 left大,1 right 大
void add(int *,int *,int *);// +
void sub(int *,int *,int *);// -
int main()
{
    int i,j,k;
    int left[100]={0},right[100]={0};
    int addans[100]={0},subans[100]={0},mulans[100]={0},divans[100]={0};
    printf("输入两个数，以空格或回车隔开\n");
    cinnn(left,right);
    add(left,right,addans);
    printf("加法运算的结果: ");
    coutt(addans);
    printf("\n");
    sub(left,right,subans);
    printf("减法运算的结果: ");
    coutt(subans);
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
    an=strlen(a);
    bn=strlen(b);
    tapoint=strchr(a,'.');
    tbpoint=strchr(b,'.');
    if(tapoint) apoint=tapoint-a;
    else apoint=an;
    if(tbpoint) bpoint=tbpoint-b;
    else bpoint=bn;
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
