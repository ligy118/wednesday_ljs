//�˷��������������ֳ���20λ��С�����ֳ���10λ���������ǲ��Ե�
//������Ϊ�õ��˳˷�����Ϊ����һЩ���㣬���ȸ��ͣ��������㣬ֱ���޶�������ķ�Χ
//��������ʦ������Ҫ���� ���÷ֿ�д������������������ʲô�Ķ�ѳ��������������
#include<stdio.h>
#include<string.h>
int cinnn(int *); //���뺯��������-1������� ����0����ɹ�
void coutt(int *); //�������
int com(int *,int *); // �ȽϺ��� return 0 left��,1 right ��  ��Χ��������
void add(int ,int ,int *,int *,int *);// +
void sub(int ,int ,int *,int *,int *);// -
void mul(int *,int *,int *);// *
int div(int *,int *,int *);// /    ������Ϊ0 ����-1�������������� ����0��
//�йط��ţ�0Ϊ����1Ϊ��
//����ע�������
int q=1;
int main()
{
    int aaaaa;
    int status;
    int i,j,k;
    int left[31],right[31];
    int addans[31],subans[31],mulans[31],divans[31];
    int divstatus; //divstatus ������״̬������Ϊ0�������
	printf("��������������С�������������벻Ҫ�����������ݵ�Ϸ~\n\n");
    while(1)
    {
        for(i=0;i<31;i++) left[i]=right[i]=addans[i]=subans[i]=mulans[i]=divans[i]=0;
        printf("������������/С�� ��/��10^-4��С��/���� ��/��10^9��ʵ�����Կո���߻��и�������������q�뿪\n");
        status=cinnn(left);
        if(status==-1) {printf("bye~\n");return 0;}
        cinnn(right);
        add(left[30],right[30],left,right,addans);
        printf("�ӷ�����Ľ��: ");
        coutt(addans);
        printf("\n");
        sub(left[30],right[30],left,right,subans);
        printf("��������Ľ��: ");
        coutt(subans);
        printf("\n");
        mul(left,right,mulans);
        printf("�˷�����Ľ��: ");
        coutt(mulans);
        printf("\n");
        divstatus=div(left,right,divans);
        if(divstatus) printf("����������Ϊ0!\n");
        else
        {
            printf("��������Ľ��: ");
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
void add(int af,int bf,int a[],int b[],int ans[]) //a��b�ķ��Ŵ�ʱ��af,bf������a[30],b[30]�ڴ˺�������Ч
{
    int jinwei=0;
    int i,j,k;
    if(af&&bf) ans[30]=1;//���������Ǹ�������һ��Ϊ����
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
void sub(int af,int bf,int a[],int b[],int ans[])//a��b�ķ��Ŵ�ʱ��af,bf������a[30],b[30]�ڴ˺�������Ч
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
        ;// ʲô�¶�û�з�����ԭ������
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
    //0��������Ϊ0
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
        if(i==30) return -1;    //0������Ϊ����
    for(i=0;i<30;i++) if(a[i]!=0) break;
        if(i==30)
        {
            for(i=0;i<30;i++) ans[i]=0;
            return 0;
        }
    //0�����κη����������㣬���������ɹ�������0
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
�����ñ��㣬����ʽ
  100/3

    ����һǧ��ans=ans+100000000   ans*3>100        ans�ָ�0      ans=ans-100000000
    ���Ű�����ǧ����
    ֱ��ʮ   ans+=10 ans*3<100
        ��20 ans+=10 ans*3<100
        ��30 ��������������������������������
        ��40 ans=ans+10             ans*3>100        ans�ָ�30      ans=ans-10
    �������Ը�λ ans=ans+1 (31)     ans*3<100
        ��32     ans=ans+1 (32)     ans*3<100
        ��33     ans=ans+1 (33)     ans*3<100
        ��34     ans=ans+1 (34)     ans*3>100        ans�ָ�33     ans=ans-1
    ��������ʮ��λans=ans+0.1 (33.1) ans*3<100
        ��33.2    ans=ans+0.1 (33.2)     ans*3<100
        ��33.3    ans=ans+0.1 (33.3)     ans*3<100
        ��33.4    ans=ans+0.1 (33.4)     ans*3>100   ans�ָ�33.3   ans=ans-0.1
    �������ٷ�λ
    ��
    ��
    ��
    ��
    ��

*/
