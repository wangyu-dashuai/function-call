#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//int is_leap(int year){   
//	if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0)){
//		printf("�����������\n");
//	}
//	else{
//		printf("����ݲ�������\n");  
//	}
//}

//�ú�����������������ֵ
//void  Swap(int *x, int *y){ //��ָ��ֱ�ӷ��ʴ洢�����������ڴ�ռ䣬ʵ�ֽ���
//	int tmp = *x;
//	*x = *y;
//	*y = tmp;

//}


//void mul(int k){  //��������
//	int i = 0;
//	int j = 0;
//	for (i = 1; i <= k; i++){
//		for (j = 1; j <= i; j++){
//			printf("%2d = %d*%d  ", i*j, i, j);
//		}
//		printf("\n");
//	}
//}


//void print(int n){   //�ݹ鷽ʽʵ�ִ�ӡһ��������ÿһλ
//	if (n > 9){
//		print(n/10);
//	}
//	printf("%d ",n%10);
//
//}


//�ݹ�ͷǵݹ�ֱ�ʵ����n�Ľ׳ˣ����������������)
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
	//printf("���������:");
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
	//printf("��������ָ��������\n");
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
	//printf("��Ϊ�˷��ھ�������һ����:");
	//scanf("%d", &n);
	//mul(n);

	//int num = 12345;
	//print(num);

	//int n=0;    //�÷ǵݹ�ķ�ʽʵ�ֶ�n�Ľ׳�
	//printf("������һ������׳�:");
	//scanf("%d", &n);
	//int j = 1;
	//for (int i = 1; i <= n; i++){
	//	j *= i;

	//
	//}
	//printf("�׳�Ϊ%d\n", j);

	int n = 1;
	printf("������һ����:");
	scanf("%d",&n);
	printf("�׳�Ϊ��%d",factor(n));
	system("pause");
	return 0;
	}




//}