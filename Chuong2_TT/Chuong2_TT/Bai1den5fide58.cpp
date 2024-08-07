//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdbool.h>
//
//// Hàm kiểm tra số nguyên tố
//bool isPrime(int n) {
//    if (n <= 1) return false;
//    for (int i = 2; i * i <= n; i++) {
//        if (n % i == 0) return false;
//    }
//    return true;
//}
//
//// Hàm đếm số phần tử là số nguyên tố trong mảng
//int countPrimes(int arr[], int n) {
//    int count = 0;
//    for (int i = 0; i < n; i++) {
//        if (isPrime(arr[i])) {
//            count++;
//        }
//    }
//    return count;
//}
//
//// Hàm kiểm tra từng chữ số của một số có phải là số lẻ không
//bool allDigitsOdd(int n) {
//    if (n == 0) return false;
//    n = n < 0 ? -n : n; // Chuyển số âm thành số dương
//    while (n > 0) {
//        int digit = n % 10;
//        if (digit % 2 == 0) return false;
//        n /= 10;
//    }
//    return true;
//}
//
//// Hàm xuất các phần tử mà từng chữ số của nó là số lẻ
//void printAllDigitsOdd(int arr[], int n) {
//    printf("Elements with all odd digits: ");
//    for (int i = 0; i < n; i++) {
//        if (allDigitsOdd(arr[i])) {
//            printf("%d ", arr[i]);
//        }
//    }
//    printf("\n");
//}
//
//// Hàm tìm vị trí số lớn nhất (cuối cùng) trong mảng
//int findLastMaxPosition(int arr[], int n) {
//    int maxPos = -1;
//    int maxVal = arr[0];
//    for (int i = 0; i < n; i++) {
//        if (arr[i] >= maxVal) {
//            maxVal = arr[i];
//            maxPos = i;
//        }
//    }
//    return maxPos;
//}
//
//// Hàm kiểm tra mảng có toàn là số chẵn không
//bool isAllEven(int arr[], int n) {
//    for (int i = 0; i < n; i++) {
//        if (arr[i] % 2 != 0) {
//            return false;
//        }
//    }
//    return true;
//}
//
//// Hàm kiểm tra mảng có phải là dãy số chẵn lẻ xen kẽ không
//bool isAlternatingEvenOdd(int arr[], int n) {
//    for (int i = 0; i < n - 1; i++) {
//        if ((arr[i] % 2 == 0 && arr[i + 1] % 2 == 0) || (arr[i] % 2 != 0 && arr[i + 1] % 2 != 0)) {
//            return false;
//        }
//    }
//    return true;
//}
//
//// Hàm in mảng số nguyên
//void printArray(int arr[], int n) {
//    for (int i = 0; i < n; i++) {
//        printf("%d ", arr[i]);
//    }
//    printf("\n");
//}
//
//int main() {
//    int arr[] = { 5, 13, 2, 14, 23, 6, 17, 18 };
//    int n = sizeof(arr) / sizeof(arr[0]);
//    int choice;
//
//    do {
//        printf("\nMenu:\n");
//        printf("1. Đếm số phần tử là số nguyên tố\n");
//        printf("2. Xuất các phần tử mà từng chữ số của nó là số lẻ\n");
//        printf("3. Tìm vị trí số lớn nhất (cuối cùng) trong mảng\n");
//        printf("4. Kiểm tra mảng có toàn là số chẵn không\n");
//        printf("5. Kiểm tra mảng có phải là dãy số chẵn lẻ xen kẽ không\n");
//        printf("6. Thoát\n");
//        printf("Nhập lựa chọn của bạn: ");
//        scanf("%d", &choice);
//
//        switch (choice) {
//        case 1: {
//            int primeCount = countPrimes(arr, n);
//            printf("Số phần tử là số nguyên tố: %d\n", primeCount);
//            break;
//        }
//        case 2: {
//            printAllDigitsOdd(arr, n);
//            break;
//        }
//        case 3: {
//            int lastMaxPos = findLastMaxPosition(arr, n);
//            printf("Vị trí số lớn nhất (cuối cùng) trong mảng: %d\n", lastMaxPos);
//            break;
//        }
//        case 4: {
//            bool allEven = isAllEven(arr, n);
//            printf("Mảng có toàn là số chẵn: %s\n", allEven ? "true" : "false");
//            break;
//        }
//        case 5: {
//            bool alternating = isAlternatingEvenOdd(arr, n);
//            printf("Mảng là dãy số chẵn lẻ xen kẽ: %s\n", alternating ? "true" : "false");
//            break;
//        }
//        case 6: {
//            printf("Thoát chương trình.\n");
//            break;
//        }
//        default: {
//            printf("Lựa chọn không hợp lệ. Vui lòng chọn lại.\n");
//        }
//        }
//    } while (choice != 6);
//
//    return 0;
//}
