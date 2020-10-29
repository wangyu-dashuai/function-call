#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//int is_leap(int year){   
//	if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0)){
//		printf("此年份是闰年\n");
//	}
//	else{
//		printf("此年份不是闰年\n");  
//	}
//}

//用函数交换两个整数的值
//void  Swap(int *x, int *y){ //用指针直接访问存储两个整数的内存空间，实现交换
//	int tmp = *x;
//	*x = *y;
//	*y = tmp;

//}


//void mul(int k){  //创建函数
//	int i = 0;
//	int j = 0;
//	for (i = 1; i <= k; i++){
//		for (j = 1; j <= i; j++){
//			printf("%2d = %d*%d  ", i*j, i, j);
//		}
//		printf("\n");
//	}
//}


//void print(int n){   //递归方式实现打印一个整数的每一位
//	if (n > 9){
//		print(n/10);
//	}
//	printf("%d ",n%10);
//
//}


//递归和非递归分别实现求n的阶乘（不考虑溢出的问题)
void factor(int n){
	if (n <= 1){
		return 1;
	}
	else{
		return n*factor(n - 1);
	}
}

int main(){
	//int year = 0;
	//printf("请输入年份:");
	//scanf("%d",&year);
	//is_leap(year);

	//int a = 10;
	//int b = 20;
	//
	//int *x = &a;
	//int *y = &b;
	//printf("x = %d, y = %d\n", *x, *y);
	//printf("--------------\n");
	//Swap(x, y);
	//printf("x = %d, y = %d\n", *x, *y);
	//printf("a = %d, b = %d\n", a, b);


	//int k;
	//printf("输入你想指定的行数\n");
	//printf("------------------\n");
	//scanf("%d", &k);
	//for (int i = 1; i <= k; i++)
	//{
	//	for (int j = 1; j <= i; j++)
	//	{
	//		printf("%2d=%d*%d  ", i*j, i, j);
	//	}
	//	printf("\n");
	//}


	//int n = 0;
	//printf("请为乘法口诀表输入一个数:");
	//scanf("%d", &n);
	//mul(n);

	//int num = 12345;
	//print(num);

	//int n=0;    //用非递归的方式实现对n的阶乘
	//printf("请输入一个数求阶乘:");
	//scanf("%d", &n);
	//int j = 1;
	//for (int i = 1; i <= n; i++){
	//	j *= i;

	//
	//}
	//printf("阶乘为%d\n", j);

	int n = 1;
	printf("请输入一个数:");
	scanf("%d",&n);
	printf("阶乘为：%d",factor(n));
	system("pause");
	return 0;
	}




//}