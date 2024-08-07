//#include <stdio.h>
//#include <string.h>
//
//int demKhoangTrang(const char* str) {
//    int dem = 0;
//    while (*str) {
//        if (*str == ' ') {
//            dem++;
//        }
//        str++;
//    }
//    return dem;
//}
//
//int main() {
//    char str[100];
//    printf("Nhập vào một chuỗi: ");
//    fgets(str, 100, stdin);
//    str[strcspn(str, "\n")] = 0;  // Xóa ký tự xuống dòng
//    printf("Số khoảng trắng: %d\n", demKhoangTrang(str));
//    return 0;
//}
