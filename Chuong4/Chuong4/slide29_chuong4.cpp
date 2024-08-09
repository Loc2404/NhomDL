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

// Câu A bài 7
int calculateSequence1(int n) {
    if (n == 0) return 1;
    if (n == 1) return 0;
    if (n == 2) return -1;

    int a0 = 1, a1 = 0, a2 = -1, an;
    for (int i = 3; i <= n; i++) {
        an = 2 * a2 - 3 * a1 - a0;
        a0 = a1;
        a1 = a2;
        a2 = an;
    }
    return an;
}

// Câu B bài 7
int calculateSequence2(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;
    if (n == 3) return 3;

    int a1 = 1, a2 = 2, a3 = 3, an;
    for (int i = 4; i <= n; i++) {
        an = 2 * a3 + a2 - 3 * a1;
        a1 = a2;
        a2 = a3;
        a3 = an;
    }
    return an;
}

// Bài 8 
int f(int n) {
	if (n == 1) return 1;
	if (n % 2 == 0)
		return 2 * f(n / 2);
	else
		return 2 * f(n / 2) + 3 * f(n / 2 + 1);
}

// bài 10 tìm kiếm nhị phân bằng đệ quy
int binarySearch(int a[], int left, int right, int x) {
	if (right >= left) {
		int mid = left + (right - left) / 2;

		// Check if x is at mid
		if (a[mid] == x)
			return mid;

		// If x is smaller, search the left subarray
		if (a[mid] > x)
			return binarySearch(a, left, mid - 1, x);

		// Otherwise, search the right subarray
		return binarySearch(a, mid + 1, right, x);
	}

	// Element is not present in array
	return -1;
}

// Bài 11 hàm Fibonacci
int fibonacci(int n) {
	if (n <= 2)
		return 1;
	return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
	int choice;


	do {
		printf("=== MENU ===\n");
		printf("1. Bai 7 slide 29.\n");
		printf("2. Bai 8 slide 29.\n");
		printf("3. Bai 10 slide 29.\n");
		printf("4. Bai 11 slide 29.\n");
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

			printf("So hang thu %d cua day so thu nhat: %d\n", n, calculateSequence1(n));
			printf("So hang thu %d cua day so thu hai: %d\n", n, calculateSequence2(n));
			system("pause");
			system("cls");
			break;
		}
		case 2:
		{
			int n = 5;

			// Tính f(5)
			printf("f(5) = %d\n", f(n));

			// Tính f(n)
			printf("Nhap so nguyen duong n: ");
			scanf("%d", &n);
			printf("f(%d) = %d\n", n, f(n));
			system("pause");
			system("cls");
			break;
		}

		case 3:
		{
			int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
			int n = sizeof(a) / sizeof(a[0]);
			int x;
			printf("Nhap so can tim(1-10): ");
			scanf("%d", &x);
			int result = binarySearch(a, 0, n - 1, x);
			if (result != -1)
				printf("Phan tu %d duoc tim thay tai chi so %d.\n", x, result);
			else
				printf("Phan tu %d khong co trong mang.\n", x);
			system("pause");
			system("cls");
			break;
		}

		case 4:
		{
			int n;
			printf("Nhap so nguyen duong n: ");
			scanf("%d", &n);
			printf("Day so Fibonacci co %d so la: ", n);
			for (int i = 1; i <= n; i++) {
				printf("%d ", fibonacci(i));
			}
			printf("\n");
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