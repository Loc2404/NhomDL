//#define _CRT_SECURE_NO_WARNINGS
//
//#include <stdio.h>
//#include <math.h>
//
//// Function declarations
//int sum_natural_numbers_recursive(int n);
//int sum_natural_numbers_iterative(int n);
//
//double sum_sqrt2_recursive(int n);
//double sum_sqrt2_iterative(int n);
//
//double sum_reciprocal_incremental_recursive(int n);
//double sum_reciprocal_incremental_iterative(int n);
//
//double sum_reciprocal_odd_recursive(int n);
//double sum_reciprocal_odd_iterative(int n);
//
//double sum_linear_incremental_recursive(int n);
//double sum_linear_incremental_iterative(int n);
//
//// Function definitions
//int sum_natural_numbers_recursive(int n) {
//    if (n == 0) {
//        return 0;
//    }
//    return n + sum_natural_numbers_recursive(n - 1);
//}
//
//int sum_natural_numbers_iterative(int n) {
//    return n * (n + 1) / 2;
//}
//
//double sum_sqrt2_recursive(int n) {
//    if (n == 0) {
//        return 0;
//    }
//    return sqrt(2) + sum_sqrt2_recursive(n - 1);
//}
//
//double sum_sqrt2_iterative(int n) {
//    return n * sqrt(2);
//}
//
//double sum_reciprocal_incremental_recursive(int n) {
//    if (n == 0) {
//        return 0;
//    }
//    return 1.0 * n / (n + 1) + sum_reciprocal_incremental_recursive(n - 1);
//}
//
//double sum_reciprocal_incremental_iterative(int n) {
//    double sum = 0;
//    for (int i = 1; i <= n; i++) {
//        sum += 1.0 * i / (i + 1);
//    }
//    return sum;
//}
//
//double sum_reciprocal_odd_recursive(int n) {
//    if (n == 0) {
//        return 0;
//    }
//    return 1.0 / (2 * n + 1) + sum_reciprocal_odd_recursive(n - 1);
//}
//
//double sum_reciprocal_odd_iterative(int n) {
//    double sum = 0;
//    for (int i = 0; i <= n; i++) {
//        sum += 1.0 / (2 * i + 1);
//    }
//    return sum;
//}
//
//double sum_linear_incremental_recursive(int n) {
//    if (n == 0) {
//        return 0;
//    }
//    return n * (n + 1) + sum_linear_incremental_recursive(n - 1);
//}
//
//double sum_linear_incremental_iterative(int n) {
//    return n * (n + 1) * (n + 2) / 6;
//}
//
//int main() {
//    int n, choice;
//    printf("Nhap n: ");
//    scanf("%d", &n);
//
//    printf("Chon phep toan can thuc hien:\n");
//    printf("1. S(n) = 1 + 2 + 3 + ... + n\n");
//    printf("2. S(n) = √2 + √2 + ... + √2 (co n dau cong)\n");
//    printf("3. S(n) = 1/2 + 2/3 + ... + n/(n+1)\n");
//    printf("4. S(n) = 1 + 1/3 + 1/5 + ... + 1/(2n+1)\n");
//    printf("5. S(n) = 1.2 + 2.3 + 3.4 + 4.5 + ... + n.(n+1)\n");
//    scanf("%d", &choice);
//
//    switch (choice) {
//    case 1:
//        printf("S(n) = 1 + 2 + 3 + ... + n:\n");
//        printf("Recursive: %d\n", sum_natural_numbers_recursive(n));
//        printf("Iterative: %d\n", sum_natural_numbers_iterative(n));
//        break;
//    case 2:
//        printf("S(n) = √2 + √2 + ... + √2 (co n dau cong):\n");
//        printf("Recursive: %.2f\n", sum_sqrt2_recursive(n));
//        printf("Iterative: %.2f\n", sum_sqrt2_iterative(n));
//        break;
//    case 3:
//        printf("S(n) = 1/2 + 2/3 + ... + n/(n+1):\n");
//        printf("Recursive: %.2f\n", sum_reciprocal_incremental_recursive(n));
//        printf("Iterative: %.2f\n", sum_reciprocal_incremental_iterative(n));
//        break;
//    case 4:
//        printf("S(n) = 1 + 1/3 + 1/5 + ... + 1/(2n+1):\n");
//        printf("Recursive: %.2f\n", sum_reciprocal_odd_recursive(n));
//        printf("Iterative: %.2f\n", sum_reciprocal_odd_iterative(n));
//        break;
//    case 5:
//        printf("S(n) = 1.2 + 2.3 + 3.4 + 4.5 + ... + n.(n+1):\n");
//        printf("Recursive: %.2f\n", sum_linear_incremental_recursive(n));
//        printf("Iterative: %.2f\n", sum_linear_incremental_iterative(n));
//        break;
//    default:
//        printf("Lua chon khong hop le.\n");
//        break;
//    }
//
//    return 0;
//}
