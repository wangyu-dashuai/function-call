#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

//��дһ������ reverse_string(char * string)���ݹ�ʵ�֣�--�ַ�������
char * reverse_string(char *str) {

	if (strlen(str) < 2) {
		return str;
	}
	char ch = *str;
	int len = strlen(str) - 1;
	*str = *(str + len); //�����һ��λ�õ����ݸ�ֵ����ʼλ��
	*(str + len) = '\0'; //�ѵ�ǰ�����һ���ַ������滻Ϊ\0

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
//�ݹ�ͷǵݹ�ֱ�ʵ��strlen
//strlen���������ַ����ĳ���--�ַ�������'\0'��ֹ
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

//�ݹ�ͷǵݹ�ֱ�ʵ����n�Ľ׳�
//n�Ľ׳�  n n * f(n-1)  n-1 n-1*f(n-2)
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
//�ݹ鷽ʽʵ�ִ�ӡһ��������ÿһλ  4583
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
//ʵ��һ����������ӡ�˷��ھ����ھ���������������Լ�ָ��
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
//ʵ��һ��������������������������
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

//���ֲ���
#define NUM 10
#define MALE 1
#define FEMALE 0

int main()
{
int arry[NUM] = { 1, 3, 5, 7, 8, 10, 12, 15, 18, 19 };
printf("������Ҫ���ҵ����֣�");
int num;
scanf("%d", &num);

int start = 0;//����ļ�����ʼ�±�������±�
int end = (sizeof(arry) / sizeof(arry[0])) - 1;
while (start <= end) {
int mid = (start + end) / 2;//ȡ������������м��±�
if (num < arry[mid]) {
end = mid - 1;
}
if (num > arry[mid]) {
start = mid + 1;
}
if (num == arry[mid]) {
printf("����%d�������е��±�Ϊ��%d\n", num, mid);
system("pause");
return 1;
}
}
printf("�Ҳ���\n");
system("pause");
return 0;
}
*/
/*
//����ϿεĲ�������Ϸ---
//������ һ���������   ������ȥ����������Ƕ��٣�
//���������������ݴ�����������������������ˣ� С�������������
void game()
{
//���������
srand(time(NULL));
int num = rand() % 100;

while (1) {
printf("��������Ҫ�µ����ְ�~~ : ");
int input;
scanf("%d", &input);
if (input > num) {
printf("����\n");
}
else if (input < num) {
printf("����\n");
}
else {
printf("��ϲ��~~�����~��\n");
break;
}
}
return;
}
int main()
{
while (1) {
system("cls");
printf("********************��ӭ�����������Ϸ********************\n");
printf("********                                          ********\n");
printf("********       0. Exit             1. Play        ********\n");
printf("********                                          ********\n");
printf("**********************************************************\n");
printf("���������ѡ����: ");
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
//����Ļ�����9*9�˷��ھ���
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
//��10�����������ֵ
//int arry[10];  int max = arry[0];  ��max��ʣ�µ�9��������Ƚ�ÿ�ν��ϴ�����ŵ�max�м���

int main()
{
int arry[10], max;
printf("������ʮ�����֣��Կո���: ");
for (int i = 0; i < 10; i++) {
scanf("%d", &arry[i]);
}
max = arry[0];
for (int i = 1; i < 10; i++) {
if (arry[i] > max) {
max = arry[i];
}
}
printf("����������: %d\n", max);
system("pause");
return 0;
}
*/

/*
//����1/1-1/2+1/3-1/4+1/5 ���� + 1/99 - 1/100 ��ֵ����ӡ�����
//��ĸ�Ǵ�1~100��ε���������һֱ��1��
//��ĸΪż�����Ǽ�ȥ�� ��ĸΪ�������Ǽӷ�
//�������Ҫ��������������븡�������㲻ͬ

int main()
{
double sum = 0;
int flag = 1;
for (int i = 1; i <= 100; i++) {
sum = sum + flag * (1.0 / i);
flag = -flag;//����λ�Ŀ���
}
printf("%f\n", sum);
system("pause");
return 0;
}
*/




/*
//��д������һ�� 1�� 100 �����������г��ֶ��ٸ�����9
//9 19 29 39 49 59 69 79 89 90 91 92 93 94 95 96 97 98 99
//��ȡ��ʮλ��9�ĸ��� num/10 == 9����ȡ����λ��9�ĸ��� num%10 == 9
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
printf("9�ĸ���: %d\n", count);
system("pause");
return 0;
}
*/


/*
//дһ�����룺��ӡ100~200֮�������
//����:ֻ�ܱ�1���������������־�������
//������ٷ���100~200֮��ÿһ��������ȥ������2��ʼ���Լ�С�����֣�������һ���������Ͳ�������
int main()
{
for (int i = 100; i <= 200; i++) {
int j;
for (j = 2; j <= sqrt(i); j++) {
if (i % j == 0) {
//��������������
break;
}
}
if (i == j) {
//��ʾ��ǰi���֣������˴�0��ʼ��i=1�����ܱ�����--����
printf("%d ", i);
}
}
system("pause");
return 0;
}
*/
/*
//��ӡ1000�굽2000��֮�������
//����--1. ��4�ı������Ҳ���100�ı�����  2. ��400�ı���

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
//���������������������������Լ��
//���Լ��: �ܱ�����ָ������������������������һ�������ǹ�Լ��
//ʱ�临�Ӷ�---����һ���㷨����Ч��
#include <stdio.h>

int main()
{
int num1, num2;
printf("�������������֣��Կո����� ");
scanf("%d %d", &num1, &num2);
int rem, count = 0;
while ((rem = num1 % num2) != 0) {
num1 = num2;
num2 = rem;
count++ ;
}
printf("���ǵ����Լ����: %d-%d\n", num2, count);
system("pause");
return 0;
}
*/
/*
int main()
{
//������ٷ�����ǰ��������ж�--Ч�����
int num1, num2;
printf("�������������֣��Կո����� ");
scanf("%d %d", &num1, &num2);
int min = num1;
if (num1 > num2) {
min = num2;//��ȡ����С������
}
int count = 0;
for (int i = min; i >= 1; i--){
count++;
if (num1 % i == 0 && num2 % i == 0) {
printf("���ǵ����Լ����: %d-%d\n", i, count);
break;
}
}
system("pause");
return 0;
}
*/