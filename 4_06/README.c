# 4_6
今晚的c作业
第一题直接硬上就好了
要注意的是,3/2的值为1,整整的1;
计算分数时要写成1.0/(i*i);
对于有个问题说两句
有关初始化的
因为c不支持在程序中定义变量,所有变量都是在第一行定义好并初始化
但是可能这个变量要用好多次
比如上次作业,要检测某个数i能否被2到n之间的数整除,定义了一个j
在检测n=999是不是质数时,j=2,2不是999的因数,继续,j=3;诶可以整除,999不是质数,开始检测998,但是,此时j的值为3,根本就没有检测2能否整除998;
推荐酱紫
int a=0,i=1000,j;
while(a<10)
{
	j=2;//这一点很重要
	balabala.....;//检测i是不是质数,也就是看看i%j是否等于0(j=2,3,4....i)
	a++;//如果i是质数,把统计已经找到的质数的数量的变量自增,输出i什么的balabala

}
至于第二题
今晚可能会学字符串
char c[100];听了过后用就可以了
可能会学一个新的头文件<string.h>继<stdio.h>和<math.h>之后
字符是以ascii表示的
比如 char d='a';
其实是把字符'a'的ascii值赋值给了变量d,此时d的值为97
(详见ascii表,百度一下就有)
接下来就跟之前写过的一个判断成绩等级差不多了
'a'也就是97分,判断属于那个范围,小写字母的范围是97~122
balabalabala


以上仅个人意见
仅供参考
