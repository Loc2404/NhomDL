#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

#define MAX_SIZE 100

// Hàm nhập/xuất mảng a
void inputArray(int a[], int n) {
    printf("Nhập %d phần tử của mảng: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
}

void printArray(int a[], int n) {
    printf("Các phần tử của mảng: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

// Tìm max/min của a
int findMax(int a[], int n) {
    int max = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    return max;
}

int findMin(int a[], int n) {
    int min = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] < min) {
            min = a[i];
        }
    }
    return min;
}

// Đếm số phần tử chẵn/lẻ trong a
int countEven(int a[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            count++;
        }
    }
    return count;
}

int countOdd(int a[], int n) {
    return n - countEven(a, n);
}

// Tìm kiếm phần tử x trong a
int linearSearch(int a[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (a[i] == x) {
            return i;
        }
    }
    return -1;
}

int binarySearch(int a[], int n, int x) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (a[mid] == x) {
            return mid;
        }
        else if (a[mid] < x) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1;
}

// Đếm số lần xuất hiện của x trong a
int countElement(int a[], int n, int x) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == x) {
            count++;
        }
    }
    return count;
}

// Đếm số phần tử lớn hơn x
int countGreater(int a[], int n, int x) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > x) {
            count++;
        }
    }
    return count;
}

// Tính tổng các phần tử của a
int sumArray(int a[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    return sum;
}

// Xuất các số nguyên tố trong a
void printPrimes(int a[], int n) {
    printf("Các số nguyên tố trong mảng: ");
    for (int i = 0; i < n; i++) {
        if (a[i] < 2) {
            continue;
        }
        int isPrime = 1;
        for (int j = 2; j <= sqrt(a[i]); j++) {
            if (a[i] % j == 0) {
                isPrime = 0;
                break;
            }
        }
        if (isPrime) {
            printf("%d ", a[i]);
        }
    }
    printf("\n");
}

// Xuất các số hoàn thiện trong a
void printPerfect(int a[], int n) {
    printf("Các số hoàn thiện trong mảng: ");
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 1; j < a[i]; j++) {
            if (a[i] % j == 0) {
                sum += j;
            }
        }
        if (sum == a[i]) {
            printf("%d ", a[i]);
        }
    }
    printf("\n");
}

// Xuất các phần tử ở vị trí chẵn/lẻ trong a
void printEvenIndexes(int a[], int n) {
    printf("Các phần tử ở vị trí chẵn: ");
    for (int i = 0; i < n; i += 2) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void printOddIndexes(int a[], int n) {
    printf("Các phần tử ở vị trí lẻ: ");
    for (int i = 1; i < n; i += 2) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

// Xuất giá trị max/min kèm theo vị trí
void printMaxMinIndex(int a[], int n) {
    int max = findMax(a, n);
    int min = findMin(a, n);
    printf("Giá trị max: %d (vị trí %d)\n", max, linearSearch(a, n, max));
    printf("Giá trị min: %d (vị trí %d)\n", min, linearSearch(a, n, min));
}

// Ghép 2 dãy b và c thành dãy a tăng dần
void mergeArrays(int b[], int m, int c[], int n, int a[], int* p) {
    int i = 0, j = 0, k = 0;
    while (i < m && j < n) {
        if (b[i] < c[j]) {
            a[k++] = b[i++];
        }
        else {
            a[k++] = c[j++];
        }
    }
    while (i < m) {
        a[k++] = b[i++];
    }
    while (j < n) {
        a[k++] = c[j++];
    }
    *p = k;
}

// Hàm sắp xếp mảng bằng thuật toán sắp xếp nổi bọt (bubble sort)
void bubbleSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int main() {
    int a[MAX_SIZE];
    int n, x, choice, index;
    int b[MAX_SIZE], m, c[MAX_SIZE], p;

    do {
        printf("\nChọn một chức năng:\n");
        printf("1. Nhập mảng\n");
        printf("2. Xuất mảng\n");
        printf("3. Tìm max/min của mảng\n");
        printf("4. Đếm số phần tử chẵn/lẻ trong mảng\n");
        printf("5. Tìm kiếm phần tử trong mảng\n");
        printf("6. Đếm số lần xuất hiện của phần tử trong mảng\n");
        printf("7. Đếm số phần tử lớn hơn x\n");
        printf("8. Tính tổng các phần tử của mảng\n");
        printf("9. Xuất các số nguyên tố trong mảng\n");
        printf("10. Xuất các số hoàn thiện trong mảng\n");
        printf("11. Xuất các phần tử ở vị trí chẵn/lẻ\n");
        printf("12. Xuất giá trị max/min kèm theo vị trí\n");
        printf("13. Ghép 2 dãy thành dãy tăng dần\n");
        printf("0. Thoát\n");
        printf("Lựa chọn của bạn: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Nhập số lượng phần tử của mảng a: ");
            scanf("%d", &n);
            inputArray(a, n);
            break;
        case 2:
            printArray(a, n);
            break;
        case 3:
            printf("Giá trị max: %d\n", findMax(a, n));
            printf("Giá trị min: %d\n", findMin(a, n));
            break;
        case 4:
            printf("Số phần tử chẵn: %d\n", countEven(a, n));
            printf("Số phần tử lẻ: %d\n", countOdd(a, n));
            break;
        case 5:
            printf("Nhập phần tử x cần tìm: ");
            scanf("%d", &x);
            index = linearSearch(a, n, x);
            if (index == -1) {
                printf("Không tìm thấy %d trong mảng (tìm kiếm tuyến tính).\n", x);
            }
            else {
                printf("Phần tử %d được tìm thấy ở vị trí %d (tìm kiếm tuyến tính).\n", x, index);
            }

            bubbleSort(a, n);  // Sort array before binary search
            index = binarySearch(a, n, x);
            if (index == -1) {
                printf("Không tìm thấy %d trong mảng (tìm kiếm nhị phân).\n", x);
            }
            else {
                printf("Phần tử %d được tìm thấy ở vị trí %d (tìm kiếm nhị phân).\n", x, index);
            }
            break;
        case 6:
            printf("Nhập phần tử x: ");
            scanf("%d", &x);
            printf("Số lần xuất hiện của %d trong mảng: %d\n", x, countElement(a, n, x));
            break;
        case 7:
            printf("Nhập giá trị x: ");
            scanf("%d", &x);
            printf("Số phần tử lớn hơn %d: %d\n", x, countGreater(a, n, x));
            break;
        case 8:
            printf("Tổng các phần tử của mảng: %d\n", sumArray(a, n));
            break;
        case 9:
            printPrimes(a, n);
            break;
        case 10:
            printPerfect(a, n);
            break;
        case 11:
            printEvenIndexes(a, n);
            printOddIndexes(a, n);
            break;
        case 12:
            printMaxMinIndex(a, n);
            break;
        case 13:
            printf("Nhập số lượng phần tử của dãy b: ");
            scanf("%d", &m);
            printf("Nhập %d phần tử của dãy b: ", m);
            for (int i = 0; i < m; i++) {
                scanf("%d", &b[i]);
            }
            printf("Nhập số lượng phần tử của dãy c: ");
            scanf("%d", &n);
            printf("Nhập %d phần tử của dãy c: ", n);
            for (int i = 0; i < n; i++) {
                scanf("%d", &c[i]);
            }
            mergeArrays(b, m, c, n, a, &p);
            printf("Dãy a sau khi ghép: ");
            for (int i = 0; i < p; i++) {
                printf("%d ", a[i]);
            }
            printf("\n");
            break;
        case 0:
            printf("Thoát chương trình.\n");
            break;
        default:
            printf("Lựa chọn không hợp lệ. Vui lòng chọn lại.\n");
        }
    } while (choice != 0);

    return 0;
}
