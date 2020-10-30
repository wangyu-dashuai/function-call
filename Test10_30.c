#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

//编写一个函数 reverse_string(char * string)（递归实现）--字符串逆序
char * reverse_string(char *str) {

	if (strlen(str) < 2) {
		return str;
	}
	char ch = *str;
	int len = strlen(str) - 1;
	*str = *(str + len); //把最后一个位置的数据赋值给起始位置
	*(str + len) = '\0'; //把当前的最后一个字符数据替换为\0

	reverse_string(str + 1);
	*(str + len) = ch;
	return str;
}
int main()
{
	char tmp[] = "hello future!";
	printf("%s\n", reverse_string(tmp));
	getchar();
	return 0;
}


/*
//递归和非递归分别实现strlen
//strlen功能是求字符串的长度--字符串是以'\0'截止
//"hello bit~"
int mystrlen(char *str){
//int len = 0;
//while (*str != '\0') {
//	len++;
//	str++;
//}
if (*str == '\0') {
return 0;
}
return 1 + mystrlen(str + 1);
}
int main()
{
printf("%d\n", mystrlen("hello bit~"));
getchar();
return 0;
}
*/

//递归和非递归分别实现求n的阶乘
//n的阶乘  n n * f(n-1)  n-1 n-1*f(n-2)
/*
int  Factorial(int n)
{

int num = 1;
for (int i = 1; i <= n; i++) {
num = num * i;
}
if (n == 1) {
return 1;
}
return n * Factorial(n - 1);
}

int main()
{
printf("%d\n", Factorial(4));
getchar();
return 0;
}
*/


/*
//递归方式实现打印一个整数的每一位  4583
void recursion(int num)
{
if (num < 10) {
printf("%d ", num);
return;
}
recursion(num / 10);
printf("%d ", num % 10);
return;
}
int main()
{
recursion(4583);
getchar();
return 0;
}
*/

/*
//实现一个函数，打印乘法口诀表，口诀表的行数和列数自己指定
int multiplication_table(int num)
{
for (int i = 1; i <= num; i++) {
for (int j = 1; j <= i; j++) {
printf("%d * %d = %d\t", i, j, i * j);
}
printf("\n");
}
return 0;
}
int main()
{
multiplication_table(100);
getchar();
return 0;
}
*/
/*
//实现一个函数来交换两个整数的内容
void myswap(int *a, int *b)
{
int tmp = *a;
*a = *b;
*b = tmp;
}
int main()
{
int a = 10, b = 20;
printf("%d-%d\n", a, b);
myswap(&a, &b);
printf("%d-%d\n", a, b);
getchar();
return 0;
}
*/
/*
int is_leap_year(int num)
{
if ((num % 4 == 0 && num % 100 != 0) || num % 400 == 0) {
return 0;
}
return -1;
}
int main()
{
for (int i = 1000; i <= 2000; i++) {
if (is_leap_year(i) == 0) {
printf("%d ", i);
}
}
getchar();
return 0;
}
*/
/*
int prime(int num)
{
for (int i = 2; i <= sqrt(num); i++) {
if (num % i == 0) {
return -1;
}
}
return 0;
}

int main()
{
for (int i = 100; i <= 200; i++) {
if (prime(i) == 0) {
printf("%d ", i);
}
}
getchar();
return 0;
}
*/

/*

//二分查找
#define NUM 10
#define MALE 1
#define FEMALE 0

int main()
{
int arry[NUM] = { 1, 3, 5, 7, 8, 10, 12, 15, 18, 19 };
printf("请输入要查找的数字：");
int num;
scanf("%d", &num);

int start = 0;//数组的检索起始下标与结束下标
int end = (sizeof(arry) / sizeof(arry[0])) - 1;
while (start <= end) {
int mid = (start + end) / 2;//取出检索区域的中间下标
if (num < arry[mid]) {
end = mid - 1;
}
if (num > arry[mid]) {
start = mid + 1;
}
if (num == arry[mid]) {
printf("数字%d在数组中的下标为：%d\n", num, mid);
system("pause");
return 1;
}
}
printf("找不到\n");
system("pause");
return 0;
}
*/
/*
//完成上课的猜数字游戏---
//先生成 一个随机数；   让我们去猜这个数字是多少；
//如果我们输入的数据大于这个随机数，则输出，高了； 小于则输出，低了
void game()
{
//生成随机数
srand(time(NULL));
int num = rand() % 100;

while (1) {
printf("请输入你要猜的数字吧~~ : ");
int input;
scanf("%d", &input);
if (input > num) {
printf("高了\n");
}
else if (input < num) {
printf("低了\n");
}
else {
printf("恭喜你~~答对了~！\n");
break;
}
}
return;
}
int main()
{
while (1) {
system("cls");
printf("********************欢迎进入猜数字游戏********************\n");
printf("********                                          ********\n");
printf("********       0. Exit             1. Play        ********\n");
printf("********                                          ********\n");
printf("**********************************************************\n");
printf("请输入你的选择编号: ");
int selected;
scanf("%d", &selected);
switch (selected){
case 0:
return 0;
case 1:
game();
break;
}
}
system("pause");
return 0;
}
*/

/*
//在屏幕上输出9*9乘法口诀表
// 1*1=1
// 2*1=2 2*2=4
int main()
{
for (int i = 1; i < 10; i++) {
for (int j = 1; j < 10; j++) {
printf("%d * %d = %d\t", i, j, i*j);
}
printf("\n");
}
system("pause");
return 0;
}
*/

/*
//求10个整数中最大值
//int arry[10];  int max = arry[0];  将max与剩下的9个数字相比较每次将较大的数放到max中即可

int main()
{
int arry[10], max;
printf("请输入十个数字，以空格间隔: ");
for (int i = 0; i < 10; i++) {
scanf("%d", &arry[i]);
}
max = arry[0];
for (int i = 1; i < 10; i++) {
if (arry[i] > max) {
max = arry[i];
}
}
printf("最大的数字是: %d\n", max);
system("pause");
return 0;
}
*/

/*
//计算1/1-1/2+1/3-1/4+1/5 …… + 1/99 - 1/100 的值，打印出结果
//分母是从1~100逐次递增，分子一直是1；
//分母为偶数则是减去； 分母为奇数则是加法
//这个题需要考虑整数相除，与浮点数运算不同

int main()
{
double sum = 0;
int flag = 1;
for (int i = 1; i <= 100; i++) {
sum = sum + flag * (1.0 / i);
flag = -flag;//符号位的控制
}
printf("%f\n", sum);
system("pause");
return 0;
}
*/




/*
//编写程序数一下 1到 100 的所有整数中出现多少个数字9
//9 19 29 39 49 59 69 79 89 90 91 92 93 94 95 96 97 98 99
//先取出十位数9的个数 num/10 == 9，再取出个位数9的个数 num%10 == 9
int main()
{
int count = 0;
for (int i = 1; i < 100; i++) {
if (i / 10 == 9) {
count++;
}
if (i % 10 == 9) {
count++;
}
}
printf("9的个数: %d\n", count);
system("pause");
return 0;
}
*/


/*
//写一个代码：打印100~200之间的素数
//素数:只能被1和自身整除的数字就是素数
//暴力穷举法：100~200之间每一个数，都去整除从2开始比自己小的数字，有任意一个被整除就不是素数
int main()
{
for (int i = 100; i <= 200; i++) {
int j;
for (j = 2; j <= sqrt(i); j++) {
if (i % j == 0) {
//被整除则不是素数
break;
}
}
if (i == j) {
//表示当前i数字，遍历了从0开始到i=1都不能被整除--素数
printf("%d ", i);
}
}
system("pause");
return 0;
}
*/
/*
//打印1000年到2000年之间的闰年
//闰年--1. 是4的倍数，且不是100的倍数；  2. 是400的倍数

#include <stdio.h>

int main()
{
int year;

for (year = 1000; year <= 2000; year++) {
if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
printf("%d ", year);
}
}
system("pause");
return 0;
}

*/

/*
//给定两个数，求这两个数的最大公约数
//最大公约数: 能被两个指定的数字整除的数（最大的那一个）就是公约数
//时间复杂度---计算一个算法运行效率
#include <stdio.h>

int main()
{
int num1, num2;
printf("请输入两个数字，以空格间隔： ");
scanf("%d %d", &num1, &num2);
int rem, count = 0;
while ((rem = num1 % num2) != 0) {
num1 = num2;
num2 = rem;
count++ ;
}
printf("他们的最大公约数是: %d-%d\n", num2, count);
system("pause");
return 0;
}
*/
/*
int main()
{
//暴力穷举法，从前往后逐个判断--效率最低
int num1, num2;
printf("请输入两个数字，以空格间隔： ");
scanf("%d %d", &num1, &num2);
int min = num1;
if (num1 > num2) {
min = num2;//获取到较小的数据
}
int count = 0;
for (int i = min; i >= 1; i--){
count++;
if (num1 % i == 0 && num2 % i == 0) {
printf("他们的最大公约数是: %d-%d\n", i, count);
break;
}
}
system("pause");
return 0;
}
*/