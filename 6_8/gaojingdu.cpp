//连续两次都出意外，好气啊
/*
玛德智障
在半学期的时候布置了一个几乎没几个人能完成的任务
交作业互评各种套路走完
又承认了作业太难
课堂上带着写了输入输入加法，你们自己回去写减法啊，每周写一个，然后交，互评
这次交添加了对负数的支持，下次咋整？支持复数
手动【滑稽】
*/
#include<stdio.h>
#include<string.h>
int cinnn(int *); //输入函数，返回-1程序结束 返回0输入成功
void coutt(int *); //输出函数
int com(int *,int *); // 比较函数 return 0 left大,1 right 大  范围两个正数
void add(int ,int ,int *,int *,int *);// +
void sub(int ,int ,int *,int *,int *);// -
void mul(int *,int *,int *);// *
void div(int *,int *,int *);// /
//有关符号，0为正，1为负
int q=1;
int main()
{
    int status;
    int i,j,k;
    int left[100],right[100];
    int addans[100],subans[100],mulans[100],divans[100];
    while(1)
    {
        for(i=0;i<100;i++) left[i]=right[i]=addans[i]=subans[i]=mulans[i]=divans[i]=0;
        printf("输入两个实数，以空格或者换行隔开，或者输入q离开\n");
        status=cinnn(left);
        if(status==-1) {printf("bye~\n");return 0;}
        cinnn(right);
        add(left[35],right[35],left,right,addans);
        printf("加法运算的结果: ");
        coutt(addans);
        printf("\n");
        sub(left[35],right[35],left,right,subans);
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
        printf("\n");
    }

    return 0;
}
int cinnn(int in[])
{
    char a[100];
    char *point;
    int n,intn;
    int i,j,k;
    scanf("%s",a);
    if(a[0]=='q'||a[0]=='Q') return -1;
    if(a[0]=='-')
    {
        in[35]=1;
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
void add(int af,int bf,int a[],int b[],int ans[]) //a，b的符号此时由af,bf决定，a[35],b[35]在此函数中无效
{
    if(af&&bf) ans[35]=1;//两个数都是负数，和一定为负数
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
    int jinwei=0;
    int i,j,k;
    for(i=29;i>=0;i--)
    {
        ans[i]=a[i]+b[i]+jinwei;
        jinwei=ans[i]/10;
        ans[i]-=jinwei*10;
    }
}
void sub(int af,int bf,int a[],int b[],int ans[])//a，b的符号此时由af,bf决定，a[35],b[35]在此函数中无效
{
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
    int jinwei=0;
    int i,j,k;
    if(com(a,b))
    {
        ans[35]=1;
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
    if(a[35]!=b[35]) ans[35]=1;
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
    for(i=0;i<30;i++) add(0,0,aans[i],ans,ans);
}
void div(int a[],int b[],int ans[])
{
    if(a[35]!=b[35]) ans[35]=1;
    int i,j,k;
    int vvv[28][35]={0};
    int chengji[35]={0};
    int aans[35]={0};
    for(i=1;i<28;i++) vvv[i][i]=1;

    for(i=1;i<28;i++)
    {
        for(;;)
        {
            add(0,0,aans,vvv[i],aans);
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
                sub(0,0,aans,vvv[i],aans);
                break;
            }
        }
    }
}
