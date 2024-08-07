//#include <stdio.h>
//#include <ctype.h>
//#include <string.h>
//
//void chuyenDoiChuCai(char* str) {
//    int trongTu = 0;
//    while (*str) {
//        if (isspace(*str)) {
//            trongTu = 0;
//        }
//        else if (!trongTu) {
//            *str = toupper(*str);
//            trongTu = 1;
//        }
//        else {
//            *str = tolower(*str);
//        }
//        str++;
//    }
//}
//
//int main() {
//    char str[100];
//    printf("Nhập vào một chuỗi: ");
//    fgets(str, 100, stdin);
//    str[strcspn(str, "\n")] = 0;  // Xóa ký tự xuống dòng
//    chuyenDoiChuCai(str);
//    printf("Chuỗi sau khi chuyển đổi: '%s'\n", str);
//    return 0;
//}
