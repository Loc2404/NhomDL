//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//
//// Định nghĩa cấu trúc phân số
//typedef struct {
//    int numerator;   // Tử số
//    int denominator; // Mẫu số
//} Fraction;
//
//// Hàm tìm ước số chung lớn nhất (UCLN) của hai số nguyên
//int gcd(int a, int b) {
//    while (b != 0) {
//        int temp = b;
//        b = a % b;
//        a = temp;
//    }
//    return a;
//}
//
//// Hàm nhập phân số
//void inputFraction(Fraction* f) {
//    printf("Nhập tử số: ");
//    scanf("%d", &f->numerator);
//    do {
//        printf("Nhập mẫu số (khác 0): ");
//        scanf("%d", &f->denominator);
//        if (f->denominator == 0) {
//            printf("Mẫu số không được bằng 0. Vui lòng nhập lại.\n");
//        }
//    } while (f->denominator == 0);
//}
//
//// Hàm xuất phân số
//void printFraction(Fraction f) {
//    printf("%d/%d\n", f.numerator, f.denominator);
//}
//
//// Hàm tối giản phân số
//void simplifyFraction(Fraction* f) {
//    int divisor = gcd(f->numerator, f->denominator);
//    f->numerator /= divisor;
//    f->denominator /= divisor;
//    // Đảm bảo mẫu số dương
//    if (f->denominator < 0) {
//        f->denominator *= -1;
//        f->numerator *= -1;
//    }
//}
//
//// Hàm tính tổng của hai phân số
//Fraction addFractions(Fraction f1, Fraction f2) {
//    Fraction result;
//    result.numerator = f1.numerator * f2.denominator + f2.numerator * f1.denominator;
//    result.denominator = f1.denominator * f2.denominator;
//    simplifyFraction(&result);
//    return result;
//}
//
//// Hàm tính hiệu của hai phân số
//Fraction subtractFractions(Fraction f1, Fraction f2) {
//    Fraction result;
//    result.numerator = f1.numerator * f2.denominator - f2.numerator * f1.denominator;
//    result.denominator = f1.denominator * f2.denominator;
//    simplifyFraction(&result);
//    return result;
//}
//
//// Hàm tính tích của hai phân số
//Fraction multiplyFractions(Fraction f1, Fraction f2) {
//    Fraction result;
//    result.numerator = f1.numerator * f2.numerator;
//    result.denominator = f1.denominator * f2.denominator;
//    simplifyFraction(&result);
//    return result;
//}
//
//// Hàm tính thương của hai phân số
//Fraction divideFractions(Fraction f1, Fraction f2) {
//    Fraction result;
//    result.numerator = f1.numerator * f2.denominator;
//    result.denominator = f1.denominator * f2.numerator;
//    simplifyFraction(&result);
//    return result;
//}
//
//int main() {
//    Fraction f1, f2;
//
//    // Nhập hai phân số
//    printf("Nhập phân số thứ nhất:\n");
//    inputFraction(&f1);
//    printf("Nhập phân số thứ hai:\n");
//    inputFraction(&f2);
//
//    // Tính và xuất các phép toán
//    Fraction sum = addFractions(f1, f2);
//    Fraction difference = subtractFractions(f1, f2);
//    Fraction product = multiplyFractions(f1, f2);
//    Fraction quotient = divideFractions(f1, f2);
//
//    printf("\nTổng: ");
//    printFraction(sum);
//    printf("Hiệu: ");
//    printFraction(difference);
//    printf("Tích: ");
//    printFraction(product);
//    printf("Thương: ");
//    printFraction(quotient);
//
//    return 0;
//}
