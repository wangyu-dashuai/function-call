#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROW 9
#define MAX_COL 9
#define DEFAULT_MINE_COUNT 10

int menu() {
	printf("======================\n");
	printf(" 1. ��ʼ��Ϸ\n");
	printf(" 0. ������Ϸ\n");
	printf("======================\n");
	printf(" ����������ѡ��: ");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}

void init(char showMap[MAX_ROW][MAX_COL],
	char mineMap[MAX_ROW][MAX_COL]) {
	// 1. ��ʼ�� showMap, ȫ����Ϊ * ����
	for (int row = 0; row < MAX_ROW; row++) {
		for (int col = 0; col < MAX_COL; col++) {
			showMap[row][col] = '*';
		}
	}
	// 2. ��ʼ�� mineMap, ��ȫ��Ϊ '0', Ȼ��������� N �� '1' 
	for (int row = 0; row < MAX_ROW; row++) {
		for (int col = 0; col < MAX_COL; col++) {
			mineMap[row][col] = '0';
		}
	}
	int n = DEFAULT_MINE_COUNT;
	while (n > 0) {
		// �����׵����λ��. 
		int row = rand() % MAX_ROW;
		int col = rand() % MAX_COL;
		if (mineMap[row][col] == '1') {
			// �����ǰλ���Ѿ�������, ��ֱ�ӽ����´�ѭ��, ����
			// �������λ��. 
			continue;
		}
		mineMap[row][col] = '1';
		n--;
	}
}

// ������������ӡ��ͼ. 
// �󲿷�����´�ӡ�Ķ��� showMap. 
// ������ GameOver ��ʱ��, ����Ҫ��ӡ mineMap

void printMap(char theMap[MAX_ROW][MAX_COL]) {
	/*for (int row = 0; row < MAX_ROW; row++) {
	for (int col = 0; col < MAX_COL; col++) {
	printf("%c ", theMap[row][col]);
	}
	printf("\n");
	}*/
	// �ȴ�ӡ����һ��, ��һ�о��ǰ������е��к�
	// Ȼ���ڴ�ӡ�����ÿһ�е�ʱ���ٴ�ӡ�к�
	printf("  |");
	for (int col = 0; col < MAX_COL; col++) {
		printf("%d ", col);
	}
	printf("\n");
	printf("--+------------------\n");
	for (int row = 0; row < MAX_ROW; row++) {
		printf(" %d|", row);
		for (int col = 0; col < MAX_COL; col++) {
			printf("%c ", theMap[row][col]);
		}
		printf("\n");
	}
}

// ���ݵ�ǰ row, col ��λ��, �������ǰλ����Χ�м�����
// ���Ҹ�����ʾ�� showMap ��. 
void updateShowMap(char showMap[MAX_ROW][MAX_COL],
	char mineMap[MAX_ROW][MAX_COL], int row, int col) {
	int count = 0;
	for (int r = row - 1; r <= row + 1; r++) {
		for (int c = col - 1; c <= col + 1; c++) {
			if (r < 0 || r >= MAX_ROW
				|| c < 0 || c >= MAX_COL) {
				// r, c �±�Խ��, ��ֱ������
				continue;
			}
			if (mineMap[r][c] == '1') {
				count++;
			}
		}
	}
	// ��ʱ count ������Ѿ������ row, col ��Χ �˸����� ���׵ĸ���
	// ��������д�� showMap �м���. 
	// ��Ҫ������ count ת�ɶ�Ӧ���ַ�
	// ���� count Ϊ 2, ����Ҫת�� '2' (ASCII 50)
	showMap[row][col] = count + '0';
}

void game() {
	// 1. ������ͼ����ʼ��. (������ͼ)
	char showMap[MAX_ROW][MAX_COL] = { 0 };
	char mineMap[MAX_ROW][MAX_COL] = { 0 };
	init(showMap, mineMap);
	int openedBlockCount = 0;
	while (1) {
		// 2. ��ӡ��ͼ

		// TODO �˴���ʱ�ſ���ӡ mineMap ���߼�, �������. 
		// ��������ʽ������ʱ��, ����Ҫ�������ӡ��ȥ��. 
		printMap(mineMap);
		printf("=================================\n");

		printMap(showMap);
		// 3. �����ȡ��������Ҫ����λ�õ�����, ��У��
		int row = 0;
		int col = 0;
		printf("������Ҫ����������(row col): ");
		scanf("%d %d", &row, &col);
		if (row < 0 || row >= MAX_ROW || col < 0 || col >= MAX_COL) {
			printf("���������������!\n");
			continue;
		}
		if (showMap[row][col] != '*') {
			printf("��ǰλ���Ѿ�������!\n");
			continue;
		}
		// 4. �ж���λ�õ������Ƿ��ǵ���. ����ǵ���, ֱ�� GameOver
		if (mineMap[row][col] == '1') {
			printf("GameOver!\n");
			// ��Ϸ������ʱ������ٴ�ӡһ����׵ĵ�ͼ, �������������
			printMap(mineMap);
			break;
		}
		// 5. ������ǵ���, ͳ�Ƶ�ǰλ����Χ�׵ĸ���, ����ʾ����ͼ��. 
		updateShowMap(showMap, mineMap, row, col);
		// 6. �ж���Ϸ�Ƿ�ʤ��
		//    �����߼�Ӧ�����жϵ�ǰ�ǲ��ǰ����в����׵�λ�ö�������
		//    �˴����Լ�¼�����ĸ��ӵĸ���
		openedBlockCount++;
		if (openedBlockCount == MAX_ROW * MAX_COL - DEFAULT_MINE_COUNT) {
			printf("��Ϸʤ��!\n");
			printMap(mineMap);
			break;
		}
	}
}

int main() {
	srand((unsigned int)time(0));
	while (1) {
		int choice = menu();
		if (choice == 1) {
			game();
		}
		else if (choice == 0) {
			printf("goodbye!\n");
			break;
		}
		else {
			printf("������������!\n");
		}
	}
	system("pause");
	return 0;
}