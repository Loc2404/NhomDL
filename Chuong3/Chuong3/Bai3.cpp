//#include <stdio.h>
//#include <string.h>
//#include <ctype.h>
//
//void xoaKhoangTrangThua(char* str) {
//    int i, x;
//    for (i = x = 0; str[i]; ++i)
//        if (!isspace(str[i]) || (i > 0 && !isspace(str[i - 1])))
//            str[x++] = str[i];
//    str[x] = '\0';
//
//    // Xóa khoảng trắng cuối chuỗi nếu có
//    if (x > 0 && isspace(str[x - 1]))
//        str[x - 1] = '\0';
//}
//
//int main() {
//    char str[100];
//    printf("Nhập vào một chuỗi: ");
//    fgets(str, 100, stdin);
//    str[strcspn(str, "\n")] = 0;  // Xóa ký tự xuống dòng
//    xoaKhoangTrangThua(str);
//    printf("Chuỗi sau khi xóa khoảng trắng thừa: '%s'\n", str);
//    return 0;
//}
