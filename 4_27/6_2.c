#include<stdio.h>
int chr(char *,char);
int main()
{
    char a[1000],b;
    int ans;
    while(~scanf("%s %c",a,&b))
    {
        ans=chr(a,b);
        if(ans<0) printf("no found\n");
        else printf("%d\n",ans+1);
    }
    return 0;
}
int chr(char *a,char b)
{
    int i,j;
    for(i=0;a[i]!='\0';i++)
    {
        if(a[i]==b)
        {
            return i;
            break;
        }
    }
    if(a[i]=='\0') return -1;
}
