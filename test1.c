#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//int main(){
	//unsigned char a = 200;
	//unsigned char b = 100;//1 0010 1100  =300 int  4+8+32=44 1被截断
	//unsigned char c = 0;//   1111 1111   =255   char
	//c = a + b;
	//printf("%d %d\n", a + b, c);

	//unsigned int a = 0x1234; 
	//unsigned char b = *(unsigned char *)&a;
	//在32位大端模式处理器上变量b等于
    //printf("%p\n", b);

	//char a[1000] = { 0 };
	//for (int i = 0; i<1000; i++)
	//{
	//	a[i] = -1 - i;  //-1相当于255 255-255 = 0；
	//}
	////求字符串的实际长度，它可以用来获取动态实际字符数组的长度，是从开始到遇到第一个"\0"
	//printf("%d\n", strlen(a));  //255

//打印杨辉三角
	//1> 定义数组，确定数组的tg[i][0]和tge[i][i]为1
	//2> 确实中间项为tge[i][j] = tge[i - 1][j - 1] + tge[i - 1][j]
	//3> 分别打印确定的值，为了使输出结果为上图，在每行前面加上对应的空格，再根据输出数字的的个数定义输出
	//4> 每打印一行换行输出
//#define N 11
//	int i = 0;
//	int j = 0;
//	int tge[N][N];
//	//先打印每一行的第一个和最后一个；
//	for (i = 0; i < N; i++)
//	{
//		tge[i][0] = 1;
//		tge[i][i] = 1;
//	}
//	//打印中间部分
//	for (i = 2; i < N; i++)
//	{
//		for (int j = 1; j < i; j++)
//		{
//			tge[i][j] = tge[i - 1][j - 1] + tge[i - 1][j];
//		}
//	}
//	for (i = 0; i < N; i++)
//	{
//		for (j = 0; j < 2 * (N - i); j++)
//		{
//			printf(" ");
//		}
//		for (j = 0; j <= i; j++)
//		{
//			printf("%4d", tge[i][j]);
//		}
//		printf("\n");
//	}
//}

	//日本某地发生了一件谋杀案，警察通过排查确定杀人凶手必为4个嫌疑犯的一个。以下为4个嫌疑犯的供词。
	//A说：不是我。
	//B说：是C。
	//C说：是D。
	//D说：C在胡说
	//已知3个人说了真话，1个人说的是假话。
	//char killer;
	//for (killer = 'A'; killer <= 'D'; killer++)//巧妙地利用ASCII 从A-D进行循环和比较
	//{
	//	//下面分别对应每个人都供词  
	//	//      不是A                 是C               是D              不是D
	//	if (((killer != 'A') + (killer == 'C') + (killer == 'D') + (killer != 'D')) == 3)  //这里等于3表示 有三个人说了真话
	//	{
	//		printf("%c是凶手\n", killer);
	//		break;
	//	}
	//}

	//喝汽水, 1瓶汽水1元，2个空瓶可以换一瓶汽水，给20元，可以得到多少汽水。
	//20块买汽水第一次有20瓶汽水(20个空瓶)，第二次得到10瓶新汽水(10个空瓶)，第三次得到5瓶新汽水(5个空瓶)
	//第四次得到2瓶新汽水(此时剩一个空瓶)，第五次得到1+1瓶新汽水() 00000->1 1 0->1 0->0 0->1
    //由此思路得到最后一共得到了20 + 10 + 5 + 2 + 1 + 1 = 39瓶汽水

	//程序的思路:先将总数置为sum(当前一共有的瓶子数)因为最开始给的钱数为money，所以购买了money/price瓶汽水，由于是
	//两个空瓶换一瓶新汽水，所以每次换得新汽水都为sum/2，再定义两个变量，一个为ret(上一次的换的新汽水),
	//一个为temp(上一次兑换过程中是否有单独剩余的空瓶)。ret(当前一共有的空瓶数)=ret(上次新换的瓶子)+temp%2(上次换掉剩余的旧空瓶)
	//while循环的条件是这次新换的瓶子不为零时，总数等于每次新换的汽水之和。

int Drink_sum(int money, int prise){
	int sum = 0;
	int temp = 0;
	int ret = 0;
	sum = money / prise; //开始的钱可购买的汽水数
	ret = sum;  //开始时的空瓶数等于购买的汽水数
	while (ret / 2 != 0){
		temp = ret; //开始的空瓶数temp = 20 10
		ret = ret / 2; //新换的新瓶子 10  5
		sum += ret; //当前一共的瓶子数 sum = 20 + 10 + 5 
		ret = ret + temp % 2; //当前的空瓶数ret = 10 + 0，5 + 0 
	}
	return sum;
}
int main(){
	int money = 0;
	int price = 0;
	printf("请输入钱数与单价:\n");
	scanf("%d %d",&money,&price);
	int bottle = Drink_sum(money,price);
	printf("%d元可以喝%d瓶汽水\n",money,bottle);
	system("pause");
	return 0;
}
	