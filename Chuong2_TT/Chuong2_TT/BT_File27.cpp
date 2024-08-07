#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

// Hàm sắp xếp tăng dần cho số nguyên
void sort_asc_int(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Hàm sắp xếp giảm dần cho số nguyên
void sort_desc_int(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Hàm sắp xếp tăng dần cho số thực
void sort_asc_float(float arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                float temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Hàm sắp xếp giảm dần cho số thực
void sort_desc_float(float arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                float temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Hàm sắp xếp tăng dần cho ký tự
void sort_asc_char(char arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                char temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Hàm sắp xếp giảm dần cho ký tự
void sort_desc_char(char arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                char temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Hàm sắp xếp tăng dần cho chuỗi ký tự
void sort_asc_string(char arr[][100], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(arr[j], arr[j + 1]) > 0) {
                char temp[100];
                strcpy(temp, arr[j]);
                strcpy(arr[j], arr[j + 1]);
                strcpy(arr[j + 1], temp);
            }
        }
    }
}

// Hàm sắp xếp giảm dần cho chuỗi ký tự
void sort_desc_string(char arr[][100], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(arr[j], arr[j + 1]) < 0) {
                char temp[100];
                strcpy(temp, arr[j]);
                strcpy(arr[j], arr[j + 1]);
                strcpy(arr[j + 1], temp);
            }
        }
    }
}
int main() {
    int int_arr[] = { 5, 2, 9, 1, 7 };
    float float_arr[] = { 3.4, 1.2, 7.8, 2.5, 6.1 };
    char char_arr[] = { 'b', 'a', 'd', 'c', 'e' };
    char string_arr[][100] = { "apple", "banana", "cherry", "date", "elderberry" };

    int int_size = sizeof(int_arr) / sizeof(int_arr[0]);
    int float_size = sizeof(float_arr) / sizeof(float_arr[0]);
    int char_size = sizeof(char_arr) / sizeof(char_arr[0]);
    int string_size = sizeof(string_arr) / sizeof(string_arr[0]);

    printf("Mang so nguyen truoc khi sap xep:\n");
    for (int i = 0; i < int_size; i++) {
        printf("%d ", int_arr[i]);
    }
    printf("\n");

    sort_asc_int(int_arr, int_size);
    printf("Mang so nguyen sau khi sap xep tang dan:\n");
    for (int i = 0; i < int_size; i++) {
        printf("%d ", int_arr[i]);
    }
    printf("\n");

    sort_desc_int(int_arr, int_size);
    printf("Mang so nguyen sau khi sap xep giam dan:\n");
    for (int i = 0; i < int_size; i++) {
        printf("%d ", int_arr[i]);
    }
    printf("\n");

    // Thực hiện tương tự cho các kiểu dữ liệu khác
    // ...

    return 0;
}