#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <random>
#include <conio.h>
#include <algorithm>
#include <unordered_map>

// hàm Fibonacci
int fibonacci(int n) {
	if (n <= 2)
		return 1;
	return fibonacci(n - 1) + fibonacci(n - 2);
}

// Bài 12
int largestFibonacciRecursive(int n) {
	int i = 0;
	while (fibonacci(i) < n) {
		i++;
	}
	return fibonacci(i - 1);
}

// bài 13
void calculateSequences(int n, int* xn, int* yn) {
	int xPrev = 1, yPrev = 0, xCurrent, yCurrent;
	for (int i = 1; i <= n; i++) {
		xCurrent = xPrev + yPrev;
		yCurrent = 3 * xPrev + 2 * yPrev;
		xPrev = xCurrent;
		yPrev = yCurrent;
	}
	*xn = xPrev;
	*yn = yPrev;
}

// Bài 14
int calculateAn(int n) {
	if (n == 1)
		return 1;
	int sum = 0;
	for (int i = 1; i < n; i++) {
		sum += calculateAn(i);
	}
	return n * sum;
}

// Bài 15 sử dụng đệ quy
int calculateYnRecursive(int n) {
	if (n == 1) return 1;
	if (n == 2) return 2;
	if (n == 3) return 3;
	return calculateYnRecursive(n - 1) + 2 * calculateYnRecursive(n - 2) + 3 * calculateYnRecursive(n - 3);
}

// Bài 15 khử đệ quy
int calculateYnIterative(int n) {
	if (n == 1) return 1;
	if (n == 2) return 2;
	if (n == 3) return 3;

	int y1 = 1, y2 = 2, y3 = 3, yn;
	for (int i = 4; i <= n; i++) {
		yn = y3 + 2 * y2 + 3 * y1;
		y1 = y2;
		y2 = y3;
		y3 = yn;
	}
	return yn;
}

// Bài 16 đệ quy
int calculateXnRecursive(int n) {
	if (n == 1 || n == 2) return 1;
	return calculateXnRecursive(n - 1) + (n - 1) * calculateXnRecursive(n - 2);
}

// Bài 16 khử đệ quy
int calculateXnIterative(int n) {
	if (n == 1 || n == 2) return 1;

	int x1 = 1, x2 = 1, xn;
	for (int i = 3; i <= n; i++) {
		xn = x2 + (i - 1) * x1;
		x1 = x2;
		x2 = xn;
	}
	return xn;
}

int main() {
	int choice;


	do {
		printf("=== MENU ===\n");
		printf("1. Bai 12 slide 30.\n");
		printf("2. Bai 13 slide 30.\n");
		printf("3. Bai 14 slide 30.\n");
		printf("4. Bai 15 slide 30.\n");
		printf("5. Bai 16 slide 30.\n");
		printf("0. Thoat chuong trinh.\n");
		printf("Nhap lua chon(0-4): ");
		scanf(" %d", &choice);
		scanf("%*c");
		switch (choice) {
		case 1:
		{
			int n;
			printf("Nhap so nguyen duong n: ");
			scanf("%d", &n);
			printf("So Fibonacci lon nhat nho hon %d la: %d\n", n, largestFibonacciRecursive(n));
			system("pause");
			system("cls");
			break;
		}
		case 2:
		{
			int n;
			printf("Nhap so hang thu n: ");
			scanf("%d", &n);
			int xn, yn;
			calculateSequences(n, &xn, &yn);
			printf("x_%d = %d, y_%d = %d\n", n, xn, n, yn);
			system("pause");
			system("cls");
			break;
		}

		case 3:
		{
			int n;
			printf("Nhap so nguyen duong n: ");
			scanf("%d", &n);
			printf("A_%d = %d\n", n, calculateAn(n));
			system("pause");
			system("cls");
			break;
		}

		case 4:
		{
			int n;
			printf("Nhap so nguyen duong n: ");
			scanf("%d", &n);
			printf("Y_%d = %d (De quy)\n", n, calculateYnRecursive(n));
			printf("Y_%d = %d (Khu de quy)\n", n, calculateYnIterative(n));
			system("pause");
			system("cls");
			break;
		}
		case 5:
		{
			int n;
			printf("Nhap so nguyen duong n: ");
			scanf("%d", &n);
			printf("X_%d = %d (De quy)\n", n, calculateXnRecursive(n));
			printf("X_%d = %d (Khu de quy)\n", n, calculateXnIterative(n));
			system("pause");
			system("cls");
			break;
		}
		case 0:
			printf("Thoat chuong trinh.\n");
			break;
		default:
			printf("Lua chon khong hop le. Vui long chon lai.");
			break;
		}
	} while (choice != 0);

	return 0;
}