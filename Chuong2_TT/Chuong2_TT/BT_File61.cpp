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
//// Hàm kiểm tra mảng có chứa toàn bộ số nguyên tố hay không
//bool isAllPrimes(int arr[], int n) {
//    for (int i = 0; i < n; i++) {
//        if (!isPrime(arr[i])) {
//            return false;
//        }
//    }
//    return true;
//}
//
//// Hàm kiểm tra mảng có đối xứng hay không
//bool isSymmetric(int arr[], int n) {
//    for (int i = 0; i < n / 2; i++) {
//        if (arr[i] != arr[n - i - 1]) {
//            return false;
//        }
//    }
//    return true;
//}
//
//// Hàm kiểm tra mảng có tăng dần hay không
//bool isAscending(int arr[], int n) {
//    for (int i = 0; i < n - 1; i++) {
//        if (arr[i] > arr[i + 1]) {
//            return false;
//        }
//    }
//    return true;
//}
//
//// Hàm kiểm tra mảng có giảm dần hay không
//bool isDescending(int arr[], int n) {
//    for (int i = 0; i < n - 1; i++) {
//        if (arr[i] < arr[i + 1]) {
//            return false;
//        }
//    }
//    return true;
//}
//
//// Hàm kiểm tra mảng có không tăng không giảm hay không
//bool isNotIncreasingNotDecreasing(int arr[], int n) {
//    bool hasIncrease = false;
//    bool hasDecrease = false;
//
//    for (int i = 0; i < n - 1; i++) {
//        if (arr[i] < arr[i + 1]) {
//            hasIncrease = true;
//        }
//        if (arr[i] > arr[i + 1]) {
//            hasDecrease = true;
//        }
//    }
//    return hasIncrease && hasDecrease;
//}
//
//int main() {
//    int arr[] = { 7, 11, 5, 5, 11, 7 };
//    int n = sizeof(arr) / sizeof(arr[0]);
//    int choice;
//
//    do {
//        printf("\nMenu:\n");
//        printf("1. Kiểm tra mảng có chứa toàn bộ số nguyên tố hay không\n");
//        printf("2. Kiểm tra mảng có đối xứng hay không\n");
//        printf("3. Kiểm tra mảng có tăng dần/giảm dần/không tăng không giảm\n");
//        printf("4. Thoát\n");
//        printf("Nhập lựa chọn của bạn: ");
//        scanf("%d", &choice);
//
//        switch (choice) {
//        case 1: {
//            bool allPrimes = isAllPrimes(arr, n);
//            printf("Mảng có chứa toàn bộ số nguyên tố: %s\n", allPrimes ? "true" : "false");
//            break;
//        }
//        case 2: {
//            bool symmetric = isSymmetric(arr, n);
//            printf("Mảng có đối xứng: %s\n", symmetric ? "true" : "false");
//            break;
//        }
//        case 3: {
//            bool ascending = isAscending(arr, n);
//            bool descending = isDescending(arr, n);
//            bool notIncreasingNotDecreasing = isNotIncreasingNotDecreasing(arr, n);
//
//            if (ascending) {
//                printf("Mảng tăng dần.\n");
//            }
//            else if (descending) {
//                printf("Mảng giảm dần.\n");
//            }
//            else if (notIncreasingNotDecreasing) {
//                printf("Mảng không tăng không giảm.\n");
//            }
//            else {
//                printf("Mảng không thuộc các trường hợp trên.\n");
//            }
//            break;
//        }
//        case 4: {
//            printf("Thoát chương trình.\n");
//            break;
//        }
//        default: {
//            printf("Lựa chọn không hợp lệ. Vui lòng chọn lại.\n");
//        }
//        }
//    } while (choice != 4);
//
//    return 0;
//}
