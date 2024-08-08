#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

// Bài 3: Viết hàm tính ước chung lớn nhất của 2 số nguyên a, b.
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

// Bài 4: Viết hàm tính giá trị phần tử thứ n của cấp số cộng có hạng đầu là a, công sai là r.
int arithmetic_progression(int a, int r, int n) {
    return a + (n - 1) * r;
}

// Bài 5: Viết hàm tính giá trị phần tử thứ n của cấp số nhân có hạng đầu là a, công bội là q.
int geometric_progression(int a, int q, int n) {
    return a * pow(q, n - 1);
}

// Bài 6: Viết hàm tính biểu thức U(n) sau đây, với n là số nguyên dương nhập từ bàn phím:
// U(n) = {U(n-5) + U(n-4) + U(n-3) + U(n-2) + U(n-1)} với n < 6
//        {U(n-1) + r} với n >= 6
int U(int n) {
    if (n <= 0) {
        return 0; // Base case for negative and zero values
    }
    else if (n < 6) {
        return U(n - 5) + U(n - 4) + U(n - 3) + U(n - 2) + U(n - 1);
    }
    else {
        return U(n - 1) + 1;
    }
}

int main() {
    int a, b, n, r, q, choice;

    printf("Chon phep toan can thuc hien:\n");
    printf("1. Tinh uoc chung lon nhat cua 2 so nguyen a, b\n");
    printf("2. Tinh gia tri phan tu thu n cua cap so cong\n");
    printf("3. Tinh gia tri phan tu thu n cua cap so nhan\n");
    printf("4. Tinh gia tri U(n)\n");
    printf("Nhap lua chon cua ban: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
        printf("Nhap a, b: ");
        scanf("%d %d", &a, &b);
        printf("Uoc chung lon nhat cua %d va %d la: %d\n", a, b, gcd(a, b));
        break;
    case 2:
        printf("Nhap a, r, n: ");
        scanf("%d %d %d", &a, &r, &n);
        printf("Phan tu thu %d cua cap so cong la: %d\n", n, arithmetic_progression(a, r, n));
        break;
    case 3:
        printf("Nhap a, q, n: ");
        scanf("%d %d %d", &a, &q, &n);
        printf("Phan tu thu %d cua cap so nhan la: %d\n", n, geometric_progression(a, q, n));
        break;
    case 4:
        printf("Nhap n: ");
        scanf("%d", &n);
        printf("Gia tri U(%d) la: %d\n", n, U(n));
        break;
    default:
        printf("Lua chon khong hop le.\n");
        break;
    }

    return 0;
}
