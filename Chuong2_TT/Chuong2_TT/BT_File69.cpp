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
//// Hàm nhập danh sách các phân số
//void inputFractions(Fraction arr[], int n) {
//    for (int i = 0; i < n; i++) {
//        printf("Nhập phân số thứ %d:\n", i + 1);
//        printf("Nhập tử số: ");
//        scanf("%d", &arr[i].numerator);
//        do {
//            printf("Nhập mẫu số (khác 0): ");
//            scanf("%d", &arr[i].denominator);
//            if (arr[i].denominator == 0) {
//                printf("Mẫu số không được bằng 0. Vui lòng nhập lại.\n");
//            }
//        } while (arr[i].denominator == 0);
//        simplifyFraction(&arr[i]);
//    }
//}
//
//// Hàm xuất danh sách các phân số
//void printFractions(Fraction arr[], int n) {
//    for (int i = 0; i < n; i++) {
//        printf("%d/%d ", arr[i].numerator, arr[i].denominator);
//    }
//    printf("\n");
//}
//
//// Hàm tính giá trị của phân số
//double fractionValue(Fraction f) {
//    return (double)f.numerator / f.denominator;
//}
//
//// Hàm tìm phân số có giá trị lớn nhất
//Fraction findMaxFraction(Fraction arr[], int n) {
//    Fraction max = arr[0];
//    for (int i = 1; i < n; i++) {
//        if (fractionValue(arr[i]) > fractionValue(max)) {
//            max = arr[i];
//        }
//    }
//    return max;
//}
//
//// Hàm tìm phân số có giá trị nhỏ nhất
//Fraction findMinFraction(Fraction arr[], int n) {
//    Fraction min = arr[0];
//    for (int i = 1; i < n; i++) {
//        if (fractionValue(arr[i]) < fractionValue(min)) {
//            min = arr[i];
//        }
//    }
//    return min;
//}
//
//// Hàm tính tổng của các phân số
//Fraction addFractions(Fraction arr[], int n) {
//    Fraction sum = { 0, 1 }; // Khởi tạo phân số 0/1
//    for (int i = 0; i < n; i++) {
//        sum.numerator = sum.numerator * arr[i].denominator + arr[i].numerator * sum.denominator;
//        sum.denominator = sum.denominator * arr[i].denominator;
//        simplifyFraction(&sum);
//    }
//    return sum;
//}
//
//// Hàm tính tích của các phân số
//Fraction multiplyFractions(Fraction arr[], int n) {
//    Fraction product = { 1, 1 }; // Khởi tạo phân số 1/1
//    for (int i = 0; i < n; i++) {
//        product.numerator = product.numerator * arr[i].numerator;
//        product.denominator = product.denominator * arr[i].denominator;
//        simplifyFraction(&product);
//    }
//    return product;
//}
//
//// Hàm xuất nghịch đảo giá trị các phân số
//void printInvertedFractions(Fraction arr[], int n) {
//    printf("Nghịch đảo các phân số:\n");
//    for (int i = 0; i < n; i++) {
//        if (arr[i].numerator == 0) {
//            printf("Phân số thứ %d không thể nghịch đảo (tử số bằng 0).\n", i + 1);
//        }
//        else {
//            Fraction inverted = { arr[i].denominator, arr[i].numerator };
//            simplifyFraction(&inverted);
//            printf("%d/%d ", inverted.numerator, inverted.denominator);
//        }
//    }
//    printf("\n");
//}
//
//// Hàm sắp xếp mảng phân số tăng dần
//void sortFractionsAscending(Fraction arr[], int n) {
//    for (int i = 0; i < n - 1; i++) {
//        for (int j = i + 1; j < n; j++) {
//            if (fractionValue(arr[i]) > fractionValue(arr[j])) {
//                Fraction temp = arr[i];
//                arr[i] = arr[j];
//                arr[j] = temp;
//            }
//        }
//    }
//}
//
//// Hàm sắp xếp mảng phân số giảm dần
//void sortFractionsDescending(Fraction arr[], int n) {
//    for (int i = 0; i < n - 1; i++) {
//        for (int j = i + 1; j < n; j++) {
//            if (fractionValue(arr[i]) < fractionValue(arr[j])) {
//                Fraction temp = arr[i];
//                arr[i] = arr[j];
//                arr[j] = temp;
//            }
//        }
//    }
//}
//
//// Hàm chính
//int main() {
//    int n;
//    Fraction arr[50];
//
//    printf("Nhập số lượng phân số (tối đa 50): ");
//    scanf("%d", &n);
//    if (n > 50) n = 50;
//
//    inputFractions(arr, n);
//
//    int choice;
//    do {
//        printf("\nMenu:\n");
//        printf("1. Xuất danh sách các phân số\n");
//        printf("2. Tìm phân số có giá trị lớn nhất\n");
//        printf("3. Tìm phân số có giá trị nhỏ nhất\n");
//        printf("4. Tính tổng của các phân số\n");
//        printf("5. Tính tích của các phân số\n");
//        printf("6. Xuất nghịch đảo các phân số\n");
//        printf("7. Sắp xếp phân số tăng dần\n");
//        printf("8. Sắp xếp phân số giảm dần\n");
//        printf("9. Thoát\n");
//        printf("Nhập lựa chọn của bạn: ");
//        scanf("%d", &choice);
//
//        switch (choice) {
//        case 1: {
//            printf("Danh sách các phân số: ");
//            printFractions(arr, n);
//            break;
//        }
//        case 2: {
//            Fraction max = findMaxFraction(arr, n);
//            printf("Phân số có giá trị lớn nhất: %d/%d\n", max.numerator, max.denominator);
//            break;
//        }
//        case 3: {
//            Fraction min = findMinFraction(arr, n);
//            printf("Phân số có giá trị nhỏ nhất: %d/%d\n", min.numerator, min.denominator);
//            break;
//        }
//        case 4: {
//            Fraction sum = addFractions(arr, n);
//            printf("Tổng của các phân số: %d/%d\n", sum.numerator, sum.denominator);
//            break;
//        }
//        case 5: {
//            Fraction product = multiplyFractions(arr, n);
//            printf("Tích của các phân số: %d/%d\n", product.numerator, product.denominator);
//            break;
//        }
//        case 6: {
//            printInvertedFractions(arr, n);
//            break;
//        }
//        case 7: {
//            sortFractionsAscending(arr, n);
//            printf("Danh sách phân số sau khi sắp xếp tăng dần: ");
//            printFractions(arr, n);
//            break;
//        }
//        case 8: {
//            sortFractionsDescending(arr, n);
//            printf("Danh sách phân số sau khi sắp xếp giảm dần: ");
//            printFractions(arr, n);
//            break;
//        }
//        case 9: {
//            printf("Thoát chương trình.\n");
//            break;
//        }
//        default: {
//            printf("Lựa chọn không hợp lệ. Vui lòng chọn lại.\n");
//        }
//        }
//    } while (choice != 9);
//
//    return 0;
//}
