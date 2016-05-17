#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
void cinnn(int *,int *);
void add(int *,int *,int *);
int main()
{
    int i,j,k;
    int left[35],right[35];
    int ans[35];
    for(i=0;i<35;i++) left[i]=right[i]=0;
    cinnn(left,right);
    for(i=0;i<30;i++) cout<<left[i];
    cout<<endl;
    for(i=0;i<30;i++) cout<<right[i];
    cout<<endl;
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
    for(i=20-apoint+1;i<=20;i++) left[i]=a[i-21+apoint]-'0';
    for(i=21;i<21+an-apoint-1;i++) left[i]=a[i-21+1+apoint]-'0';
    for(i=20-bpoint+1;i<=20;i++) right[i]=b[i-21+bpoint]-'0';
    for(i=21;i<21+bn-bpoint-1;i++) right[i]=b[i-21+1+bpoint]-'0';
}
void add(int a[],int b[],int ans[])
{

;
}
