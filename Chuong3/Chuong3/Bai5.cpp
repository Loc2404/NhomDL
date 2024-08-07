#include <stdio.h>
#include <string.h>

void timKiemTen(const char* hoTen, const char* ten) {
    if (strstr(hoTen, ten) != NULL) {
        printf("Tên '%s' đã được nhập đúng.\n", ten);
    }
    else {
        printf("Tên '%s' đã nhập sai.\n", ten);
    }
}

int main() {
    char hoTen[100];
    char ten[50];
    printf("Nhập vào họ tên đầy đủ: ");
    fgets(hoTen, 100, stdin);
    hoTen[strcspn(hoTen, "\n")] = 0;  // Xóa ký tự xuống dòng
    printf("Nhập vào tên cần tìm: ");
    fgets(ten, 50, stdin);
    ten[strcspn(ten, "\n")] = 0;  // Xóa ký tự xuống dòng
    timKiemTen(hoTen, ten);
    return 0;
}
