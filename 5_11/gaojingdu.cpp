#include<stdio.h>
#include<string.h>
//#include<iostream>
//using namespace std;
void cinnn(int *,int *); //输入函数
void coutt(int *); //输出函数
void add(int *,int *,int *);
int main()
{
    int i,j,k;
    int left[35],right[35];
    int ans[35];
    for(i=0;i<35;i++) left[i]=right[i]=0;
    cinnn(left,right);
    coutt(left);
    printf("\n");
    coutt(right);
    printf("\n");
    return 0;
}
void cinnn(int left[],int right[])
{
    char a[35],b[35];
    char *tapoint,*tbpoint;
    int an,bn,apoint,bpoint;
    int i,j,k;
    scanf("%s%s",a,b);
 //   cout<<a<<endl<<b<<endl;
    an=strlen(a);
    bn=strlen(b);
    tapoint=strchr(a,'.');
    tbpoint=strchr(b,'.');
    if(tapoint) apoint=tapoint-a;
    else apoint=an;
    if(tbpoint) bpoint=tbpoint-b;
    else bpoint=bn;
    //cout<<an<<"   "<<bn<<endl;
    //cout<<apoint<<"   "<<bpoint<<endl;
    for(i=19-apoint+1;i<=19;i++) left[i]=a[i-20+apoint]-'0';
    for(i=20;i<20+an-apoint-1;i++) left[i]=a[i-20+1+apoint]-'0';
    for(i=19-bpoint+1;i<=19;i++) right[i]=b[i-20+bpoint]-'0';
    for(i=20;i<20+bn-bpoint-1;i++) right[i]=b[i-20+1+bpoint]-'0';
}
void coutt (int a[])
{
    int st,en;
    int i;
    for(i=0;i<30;i++) if(a[i]!=0) {st=i;break;}
    for(i=29;i>=0;i--) if(a[i]!=0) {en=i;break;}
    for(i=st;i<20&&i<=en;i++) printf("%d",a[i]);
    if(en>=20)
    {
        printf(".");
        for(i=20;i<30&&i<=en;i++) printf("%d",a[i]);
    }

}
void add(int a[],int b[],int ans[])
{
    ;
}
