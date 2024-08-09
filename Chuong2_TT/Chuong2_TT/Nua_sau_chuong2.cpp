#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_STUDENTS 100
#define MAX_STUDENTS 100
#define MAX_SUBJECTS 5


typedef struct {
    int id;
    char mssv[10];
    char name[50];
    float assignment_score;
    float exam_score;
    float total_score;
    float gpa;
} Students;

void input_students(Students students[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Sinh vien %d:\n", i + 1);
        students[i].id = i + 1;
        printf("Ma so sinh vien: ");
        scanf("%s", students[i].mssv);
        printf("Ho va ten: ");
        scanf(" %[^\n]s", students[i].name);
        printf("Diem tieu luan: ");
        scanf("%f", &students[i].assignment_score);
        printf("Diem thi ket thuc mon: ");
        scanf("%f", &students[i].exam_score);
        students[i].total_score = 0.3 * students[i].assignment_score + 0.7 * students[i].exam_score;
        printf("\n");
    }
}

void output_students(Students students[], int n) {
    printf("Danh sach sinh vien:\n");
    printf("%-5s %-10s %-30s %-15s %-15s %-15s %-15s\n", "STT", "MSSV", "Ho va ten", "Diem tieu luan", "Diem thi", "Diem tong ket", "Diem 4.0");
    for (int i = 0; i < n; i++) {
        printf("%-5d %-10s %-30s %-15.2f %-15.2f %-15.2f %-15.2f\n",
            students[i].id, students[i].mssv, students[i].name,
            students[i].assignment_score, students[i].exam_score,
            students[i].total_score, students[i].gpa);
    }
}

void sort_students_by_total_score(Students students[], int n, int ascending) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if ((ascending && students[j].total_score > students[j + 1].total_score) ||
                (!ascending && students[j].total_score < students[j + 1].total_score)) {
                Students temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

void calculate_gpa(Students students[], int n) {
    for (int i = 0; i < n; i++) {
        if (students[i].total_score >= 90) {
            students[i].gpa = 4.0;
        }
        else if (students[i].total_score >= 85) {
            students[i].gpa = 3.5;
        }
        else if (students[i].total_score >= 80) {
            students[i].gpa = 3.0;
        }
        else if (students[i].total_score >= 75) {
            students[i].gpa = 2.5;
        }
        else if (students[i].total_score >= 70) {
            students[i].gpa = 2.0;
        }
        else if (students[i].total_score >= 60) {
            students[i].gpa = 1.0;
        }
        else {
            students[i].gpa = 0.0;
        }
    }
}

void get_pass_fail_count(Students students[], int n, int* pass, int* fail) {
    *pass = 0;
    *fail = 0;
    for (int i = 0; i < n; i++) {
        if (students[i].total_score >= 5.0) {
            (*pass)++;
        }
        else {
            (*fail)++;
        }
    }
}

float calculate_average_score(Students students[], int n) {
    float total_score = 0;
    for (int i = 0; i < n; i++) {
        total_score += students[i].total_score;
    }
    return total_score / n;
}

typedef struct Subject {
    int code;
    char name[50];
    int credits;
    float score;
} Subject;

typedef struct Student {
    int id;
    char name[50];
    Subject subjects[MAX_SUBJECTS];
    float gpa;
} Student;

int numStudents = 0;
Student students[MAX_STUDENTS];

void addStudent() {
    if (numStudents >= MAX_STUDENTS) {
        printf("Danh sach da day, khong the them sinh vien moi.\n");
        return;
    }

    Student newStudent;
    printf("Nhap ma so sinh vien: ");
    scanf("%d", &newStudent.id);
    scanf("%*c");
    printf("Nhap ho ten sinh vien: ");
    scanf(" %[^\n]s", newStudent.name);

    float totalScore = 0;
    for (int i = 0; i < MAX_SUBJECTS; i++) {
        printf("Nhap thong tin mon hoc %d:\n", i + 1);
        printf("Ma mon: ");
        scanf("%d", &newStudent.subjects[i].code);
        printf("Ten mon: ");
        scanf(" %[^\n]s", newStudent.subjects[i].name);
        printf("So tin chi: ");
        scanf("%d", &newStudent.subjects[i].credits);
        printf("Diem: ");
        scanf("%f", &newStudent.subjects[i].score);
        totalScore += newStudent.subjects[i].score;
    }

    newStudent.gpa = totalScore / MAX_SUBJECTS;
    students[numStudents++] = newStudent;
    printf("Da them sinh vien moi.\n");
}

void removeStudent() {
    int id;
    printf("Nhap ma so sinh vien can xoa: ");
    scanf("%d", &id);

    int index = -1;
    for (int i = 0; i < numStudents; i++) {
        if (students[i].id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Khong tim thay sinh vien voi ma so %d.\n", id);
        return;
    }

    for (int i = index; i < numStudents - 1; i++) {
        students[i] = students[i + 1];
    }
    numStudents--;
    printf("Da xoa sinh vien voi ma so %d.\n", id);
}

void findStudent() {
    int id;
    printf("Nhap ma so sinh vien can tim: ");
    scanf("%d", &id);

    for (int i = 0; i < numStudents; i++) {
        if (students[i].id == id) {
            printf("Thong tin sinh vien:\n");
            printf("Ma so: %d\n", students[i].id);
            printf("Ho ten: %s\n", students[i].name);
            printf("Diem trung binh: %.2f\n", students[i].gpa);
            return;
        }
    }

    printf("Khong tim thay sinh vien voi ma so %d.\n", id);
}

void findHighestGPA() {
    if (numStudents == 0) {
        printf("Danh sach sinh vien trong.\n");
        return;
    }

    int index = 0;
    float highestGPA = students[0].gpa;
    for (int i = 1; i < numStudents; i++) {
        if (students[i].gpa > highestGPA) {
            highestGPA = students[i].gpa;
            index = i;
        }
    }

    printf("Sinh vien co diem trung binh cao nhat:\n");
    printf("Ma so: %d\n", students[index].id);
    printf("Ho ten: %s\n", students[index].name);
    printf("Diem trung binh: %.2f\n", students[index].gpa);
}

void sortStudents(int ascending) {
    if (numStudents == 0) {
        printf("Danh sach sinh vien trong.\n");
        return;
    }

    for (int i = 0; i < numStudents - 1; i++) {
        for (int j = 0; j < numStudents - i - 1; j++) {
            if ((ascending && students[j].gpa > students[j + 1].gpa) ||
                (!ascending && students[j].gpa < students[j + 1].gpa)) {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }

    printf("Da sap xep danh sach sinh vien %s theo diem trung binh.\n",
        ascending ? "tang dan" : "giam dan");
}

void classifyStudents() {
    if (numStudents == 0) {
        printf("Danh sach sinh vien trong.\n");
        return;
    }

    int excellent = 0, good = 0, average = 0, poor = 0;
    for (int i = 0; i < numStudents; i++) {
        if (students[i].gpa >= 3.5) {
            excellent++;
        }
        else if (students[i].gpa >= 3.0) {
            good++;
        }
        else if (students[i].gpa >= 2.0) {
            average++;
        }
        else {
            poor++;
        }
    }

    printf("Xep loai hoc tap cua sinh vien:\n");
    printf("Xuat sac: %d\n", excellent);
    printf("Gioi: %d\n", good);
    printf("Trung binh: %d\n", average);
    printf("Yeu: %d\n", poor);
}

void printStudents() {
    if (numStudents == 0) {
        printf("Danh sach sinh vien trong.\n");
        return;
    }

    printf("Danh sach sinh vien:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("Ma so: %d\n", students[i].id);
        printf("Ho ten: %s\n", students[i].name);
        printf("Diem trung binh: %.2f\n", students[i].gpa);
        printf("Mon hoc:\n");
        for (int j = 0; j < MAX_SUBJECTS; j++) {
            printf("- Ma mon: %d, Ten mon: %s, So tin chi: %d, Diem: %.2f\n",
                students[i].subjects[j].code, students[i].subjects[j].name,
                students[i].subjects[j].credits, students[i].subjects[j].score);
        }
        printf("\n");
    }
}

// Kiem tra so nguyen to
int isPrime(int n) {
    if (n < 2) return 0;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

// Bai 1: Tinh tong cac phan tu co chu so dau la so le
int sumOddLeadingDigits(int a[][MAX_COLS], int m, int n) {
    int sum = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (abs(a[i][j]) % 10 % 2 != 0) {
                sum += a[i][j];
            }
        }
    }
    return sum;
}

// Bai 2: Liet ke cac so hoan thien trong ma tran
void printPerfectNumbers(int a[][MAX_COLS], int m, int n) {
    printf("Cac so hoan thien trong ma tran: ");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int sum = 0;
            for (int k = 1; k < a[i][j]; k++) {
                if (a[i][j] % k == 0) {
                    sum += k;
                }
            }
            if (sum == a[i][j]) {
                printf("%d ", a[i][j]);
            }
        }
    }
    printf("\n");
}

// Bai 3: Tinh tong cac phan tu lon hon tri tuyet doi cua phan tu lien sau no
int sumGreaterThanNext(int a[][MAX_COLS], int m, int n) {
    int sum = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (abs(a[i][j]) > abs(a[i][j + 1])) {
                sum += a[i][j];
            }
        }
    }
    return sum;
}

// Bai 4: Tinh tong cac phan tu tren dong k
int sumRowK(int a[][MAX_COLS], int m, int n, int k) {
    int sum = 0;
    for (int j = 0; j < n; j++) {
        sum += a[k][j];
    }
    return sum;
}

// Bai 5: Tinh tong cac phan tu tren bien cua ma tran
int sumBorder(int a[][MAX_COLS], int m, int n) {
    int sum = 0;
    for (int i = 0; i < m; i++) {
        sum += a[i][0];
        sum += a[i][n - 1];
    }
    for (int j = 1; j < n - 1; j++) {
        sum += a[0][j];
        sum += a[m - 1][j];
    }
    return sum;
}

// Bai 6: Dem tan suat xuat hien cua mot gia tri x trong ma tran
int countOccurrence(int a[][MAX_COLS], int m, int n, int x) {
    int count = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == x) {
                count++;
            }
        }
    }
    return count;
}

// Bai 7: Dem so luong cac phan tu la so chan, so le, so am, so duong, so nguyen to
void countTypes(int a[][MAX_COLS], int m, int n) {
    int evenCount = 0, oddCount = 0, negativeCount = 0, positiveCount = 0, primeCount = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] % 2 == 0) {
                evenCount++;
            }
            else {
                oddCount++;
            }
            if (a[i][j] < 0) {
                negativeCount++;
            }
            else {
                positiveCount++;
            }
            if (isPrime(a[i][j])) {
                primeCount++;
            }
        }
    }
    printf("So luong cac phan tu:\n");
    printf("So chan: %d\n", evenCount);
    printf("So le: %d\n", oddCount);
    printf("So am: %d\n", negativeCount);
    printf("So duong: %d\n", positiveCount);
    printf("So nguyen to: %d\n", primeCount);
}

// Ham tinh tong cac phan tu trong cot j
int sumCol(int a[][100], int m, int n, int j) {
    int sum = 0;
    for (int i = 0; i < m; i++) {
        sum += a[i][j];
    }
    return sum;
}

// Ham dem so luong so hoan thien trong hang i
int countPerfectNum(int a[][100], int m, int n, int i) {
    int count = 0;
    for (int j = 0; j < n; j++) {
        int sum = 0;
        for (int k = 1; k < a[i][j]; k++) {
            if (a[i][j] % k == 0) {
                sum += k;
            }
        }
        if (sum == a[i][j]) {
            count++;
        }
    }
    return count;
}

void sapxep_hang(int a[][100], int n, int m) {
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < m - 1; j++) {
                for (int k = 0; k < m - j - 1; k++) {
                    if (a[i][k] > a[i][k + 1]) {
                        int temp = a[i][k];
                        a[i][k] = a[i][k + 1];
                        a[i][k + 1] = temp;
                    }
                }
            }
        }
        else {
            for (int j = 0; j < m - 1; j++) {
                for (int k = 0; k < m - j - 1; k++) {
                    if (a[i][k] < a[i][k + 1]) {
                        int temp = a[i][k];
                        a[i][k] = a[i][k + 1];
                        a[i][k + 1] = temp;
                    }
                }
            }
        }
    }
}

void sapxep_cot(int a[][100], int n, int m) {
    for (int j = 0; j < m; j++) {
        if (j % 2 == 0) {
            for (int i = 0; i < n - 1; i++) {
                for (int k = 0; k < n - i - 1; k++) {
                    if (a[k][j] > a[k + 1][j]) {
                        int temp = a[k][j];
                        a[k][j] = a[k + 1][j];
                        a[k + 1][j] = temp;
                    }
                }
            }
        }
        else {
            for (int i = 0; i < n - 1; i++) {
                for (int k = 0; k < n - i - 1; k++) {
                    if (a[k][j] < a[k + 1][j]) {
                        int temp = a[k][j];
                        a[k][j] = a[k + 1][j];
                        a[k + 1][j] = temp;
                    }
                }
            }
        }
    }
}

void sapxep_ziczac(int a[][100], int n, int m) {
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < m - 1; j++) {
                for (int k = 0; k < m - j - 1; k++) {
                    if (a[i][k] > a[i][k + 1]) {
                        int temp = a[i][k];
                        a[i][k] = a[i][k + 1];
                        a[i][k + 1] = temp;
                    }
                }
            }
        }
        else {
            for (int j = m - 1; j > 0; j--) {
                for (int k = j; k > 0; k--) {
                    if (a[i][k] < a[i][k - 1]) {
                        int temp = a[i][k];
                        a[i][k] = a[i][k - 1];
                        a[i][k - 1] = temp;
                    }
                }
            }
        }
    }
}

// Ham tinh tong cac phan tu nam tren duong cheo chinh
int tongDuongCheoChinh(int matrix[][100], int n) {
    int tong = 0;
    for (int i = 0; i < n; i++) {
        tong += matrix[i][i];
    }
    return tong;
}

// Ham tinh tong cac phan tu nam tren duong cheo phu
int tongDuongCheoPhu(int matrix[][100], int n) {
    int tong = 0;
    for (int i = 0; i < n; i++) {
        tong += matrix[i][n - i - 1];
    }
    return tong;
}

// Ham tinh tong cac phan tu nam phia tren duong cheo chinh
int tongPhiaTrenDuongCheoChinh(int matrix[][100], int n) {
    int tong = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            tong += matrix[i][j];
        }
    }
    return tong;
}

// Ham tinh tong cac phan tu nam phia tren duong cheo phu
int tongPhiaTrenDuongCheoPhu(int matrix[][100], int n) {
    int tong = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            tong += matrix[i][j];
        }
    }
    return tong;
}


int main() {
    int choice, choice1;

    do {
        printf("=== MENU ===\n");
        printf("1. Bai 2 slide 70 chuong 2\n");
        printf("2. Bai 3 slide 71 chuong 2\n");
        printf("3. Bai tap slide 78 chuong 2\n");
        printf("4. Bai tap slide 82 chuong 2\n");
        printf("5. Bai tap slide 86 chuong 2\n");
        printf("6. Bai tap slide 89 chuong 2\n");
        printf("0. Thoat\n");
        printf("Chon chuc nang (0-6): ");
        scanf("%d", &choice1);

        switch (choice1) {
        case 1:
        {
            int n, pass, fail;
            Students students[MAX_STUDENTS];

            printf("Nhap so luong sinh vien: ");
            scanf("%d", &n);

            input_students(students, n);
            calculate_gpa(students, n);
            output_students(students, n);

            printf("Sinh vien co diem tong ket cao nhat: ");
            sort_students_by_total_score(students, n, 0);
            printf("%s (%.2f)\n", students[0].name, students[0].total_score);

            printf("Sinh vien co diem tong ket thap nhat: ");
            sort_students_by_total_score(students, n, 1);
            printf("%s (%.2f)\n", students[n - 1].name, students[n - 1].total_score);

            get_pass_fail_count(students, n, &pass, &fail);
            printf("So sinh vien dat: %d, So sinh vien khong dat: %d\n", pass, fail);

            printf("Diem trung binh cua tat ca cac sinh vien: %.2f\n", calculate_average_score(students, n));

            // Lưu dữ liệu vào file
            FILE* fp = fopen("students.txt", "w");
            if (fp == NULL) {
                printf("Khong the mo file.\n");
                return 1;
            }
            fprintf(fp, "Danh sach sinh vien:\n");
            fprintf(fp, "%-5s %-10s %-30s %-15s %-15s %-15s %-15s\n", "STT", "MSSV", "Ho va ten", "Diem tieu luan", "Diem thi", "Diem tong ket", "Diem 4.0");
            for (int i = 0; i < n; i++) {
                fprintf(fp, "%-5d %-10s %-30s %-15.2f %-15.2f %-15.2f %-15.2f\n",
                    students[i].id, students[i].mssv, students[i].name,
                    students[i].assignment_score, students[i].exam_score,
                    students[i].total_score, students[i].gpa);
            }
            fclose(fp);

            printf("Du lieu da duoc luu vao file 'students.txt'.\n");

            system("pause");
            system("cls");
            break;
        }
        case 2:
        {
            system("cls");
            do {
                printf("=== MENU ===\n");
                printf("1. Them sinh vien\n");
                printf("2. Xoa sinh vien\n");
                printf("3. Tim sinh vien\n");
                printf("4. Tim sinh vien co diem trung binh cao nhat\n");
                printf("5. Sap xep danh sach sinh vien\n");
                printf("6. Xep loai hoc tap cua sinh vien\n");
                printf("7. In danh sach sinh vien\n");
                printf("0. Quay lai\n");
                printf("Chon lua(0-7): ");
                scanf("%d", &choice);

                switch (choice) {
                case 1:
                {
                    addStudent();
                    system("pause");
                    system("cls");
                    break;
                }
                case 2:
                {
                    removeStudent();
                    system("pause");
                    system("cls");
                    break;
                }
                case 3:
                {
                    findStudent();
                    system("pause");
                    system("cls");
                    break;
                }
                case 4:
                {
                    findHighestGPA();
                    system("pause");
                    system("cls");
                    break;
                }
                case 5:
                {
                    int ascending;
                    printf("Sap xep tang dan (1) hay giam dan (0)? ");
                    scanf("%d", &ascending);
                    sortStudents(ascending);
                    system("pause");
                    system("cls");
                    break;
                }
                case 6:
                {
                    classifyStudents();
                    system("pause");
                    system("cls");
                    break;
                }
                case 7:
                {
                    printStudents();
                    system("pause");
                    system("cls");
                    break;
                }
                case 0:
                    printf("Quay lai.\n");
                    break;
                default:
                    printf("Lua chon khong hop le. Vui long thu lai.\n");
                    break;
                }
            } while (choice != 0);
            system("pause");
            system("cls");
            break;
        }
        case 3:
        {
            int a[MAX_ROWS][MAX_COLS];
            int m, n;
            printf("Nhap so hang (m) va so cot (n) cua ma tran: ");
            scanf("%d %d", &m, &n);

            printf("Nhap cac phan tu cua ma tran:\n");
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    scanf("%d", &a[i][j]);
                }
            }

            printf("Bai 1: Tong cac phan tu co chu so dau la so le: %d\n", sumOddLeadingDigits(a, m, n));
            printPerfectNumbers(a, m, n);
            printf("Bai 3: Tong cac phan tu lon hon tri tuyet doi cua phan tu lien sau no: %d\n", sumGreaterThanNext(a, m, n));
            printf("Bai 4: Tong cac phan tu tren dong k: %d\n", sumRowK(a, m, n, 2));
            printf("Bai 5: Tong cac phan tu tren bien cua ma tran: %d\n", sumBorder(a, m, n));
            printf("Bai 6: Tan suat xuat hien cua gia tri 5 trong ma tran: %d\n", countOccurrence(a, m, n, 5));
            countTypes(a, m, n);

            system("pause");
            system("cls");
            break;
        }
        case 4:
        {

            int a[100][100];
            int m, n;
            printf("Nhap so hang m: ");
            scanf("%d", &m);
            printf("Nhap so cot n: ");
            scanf("%d", &n);

            // Nhap ma tran a
            printf("Nhap cac phan tu cua ma tran:\n");
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    printf("Nhap a[%d][%d]: ", i, j);
                    scanf("%d", &a[i][j]);
                }
            }

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    printf("%d ", a[i][j]);
                }
                printf("\n");
            }

            // Bai 1: Liet ke cac cot co tong nho nhat
            printf("Cac cot co tong nho nhat:\n");
            int minSum = sumCol(a, m, n, 0);
            printf("%d ", 0);
            for (int j = 1; j < n; j++) {
                int curSum = sumCol(a, m, n, j);
                if (curSum < minSum) {
                    minSum = curSum;
                    printf("%d ", j);
                }
                else if (curSum == minSum) {
                    printf("%d ", j);
                }
            }
            printf("\n");

            // Bai 2: Liet ke cac hang co nhieu so hoan thien nhat
            int maxPerfect = countPerfectNum(a, m, n, 0);
            printf("Cac hang co nhieu so hoan thien nhat:\n");
            printf("%d ", 0);
            for (int i = 1; i < m; i++) {
                int curPerfect = countPerfectNum(a, m, n, i);
                if (curPerfect > maxPerfect) {
                    maxPerfect = curPerfect;
                    printf("%d ", i);
                }
                else if (curPerfect == maxPerfect) {
                    printf("%d ", i);
                }
            }
            printf("\n");

            // Bai 3: Liet ke chi so cac hang toan so chan
            printf("Chi so cac hang toan so chan:\n");
            for (int i = 0; i < m; i++) {
                bool allEven = true;
                for (int j = 0; j < n; j++) {
                    if (a[i][j] % 2 != 0) {
                        allEven = false;
                        break;
                    }
                }
                if (allEven) {
                    printf("%d ", i);
                }
            }
            printf("\n");

            // Bai 4: Tim gia tri xuat hien nhieu nhat
            int maxCount = 0;
            int maxVal = a[0][0];
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    int count = 0;
                    for (int k = 0; k < m; k++) {
                        for (int l = 0; l < n; l++) {
                            if (a[k][l] == a[i][j]) {
                                count++;
                            }
                        }
                    }
                    if (count > maxCount || (count == maxCount && a[i][j] < maxVal)) {
                        maxCount = count;
                        maxVal = a[i][j];
                    }
                }
            }
            printf("Gia tri xuat hien nhieu nhat: %d\n", maxVal);

            // Bai 5: Tim so nguyen to nho nhat
            int minPrime = -1;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (isPrime(a[i][j])) {
                        if (minPrime == -1 || a[i][j] < minPrime) {
                            minPrime = a[i][j];
                        }
                    }
                }
            }
            if (minPrime == -1) {
                printf("Khong co so nguyen to trong ma tran\n");
            }
            else {
                printf("So nguyen to nho nhat: %d\n", minPrime);
            }

            // Bai 6: Tim phan tu lon (nho) nhat trong hang k
            int k;
            printf("Nhap chi so hang k: ");
            scanf("%d", &k);
            int maxVal6 = a[k][0], minVal6 = a[k][0];
            for (int j = 1; j < n; j++) {
                if (a[k][j] > maxVal6) {
                    maxVal6 = a[k][j];
                }
                if (a[k][j] < minVal6) {
                    minVal6 = a[k][j];
                }
            }
            printf("Phan tu lon nhat trong hang %d: %d\n", k, maxVal6);
            printf("Phan tu nho nhat trong hang %d: %d\n", k, minVal6);

            // Bai 7: Tim phan tu lon (nho) nhat trong cot k
            int k2;
            printf("Nhap chi so cot k: ");
            scanf("%d", &k2);
            int maxVal7 = a[0][k2], minVal7 = a[0][k2];
            for (int i = 1; i < m; i++) {
                if (a[i][k2] > maxVal7) {
                    maxVal7 = a[i][k2];
                }
                if (a[i][k2] < minVal7) {
                    minVal7 = a[i][k2];
                }
            }
            printf("Phan tu lon nhat trong cot %d: %d\n", k2, maxVal7);
            printf("Phan tu nho nhat trong cot %d: %d\n", k2, minVal7);
            system("pause");
            system("cls");
            break;
        }
        case 5:
        {
            int n, m;
            printf("Nhap so hang n va so cot m cua ma tran: ");
            scanf("%d %d", &n, &m);

            int a[100][100];

            printf("Nhap cac phan tu cua ma tran:\n");
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    scanf("%d", &a[i][j]);
                }
            }

            printf("\nBai 1: Sap xep tang dan cac phan tu o cac hang chan, giam dan cac phan tu o cac hang le:\n");
            sapxep_hang(a, n, m);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    printf("%d ", a[i][j]);
                }
                printf("\n");
            }

            printf("\nBai 2: Sap xep tang dan cac phan tu o cac cot chan, giam dan cac phan tu o cac cot le:\n");
            sapxep_cot(a, n, m);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    printf("%d ", a[i][j]);
                }
                printf("\n");
            }

            printf("\nBai 3: Sap xep ma tran theo zig-zag:\n");
            sapxep_ziczac(a, n, m);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    printf("%d ", a[i][j]);
                }
                printf("\n");
            }

            system("pause");
            system("cls");
            break;
        }
        case 6:
        {
            int n;
            printf("Nhap kich thuoc ma tran vuong n: ");
            scanf("%d", &n);

            int matrix[100][100];
            printf("Nhap cac phan tu cua ma tran:\n");
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    printf("Phan tu [%d][%d]: ", i, j);
                    scanf("%d", &matrix[i][j]);
                }
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    printf("%d ", matrix[i][j]);
                }
                printf("\n");
            }
            printf("Tong cac phan tu tren duong cheo chinh: %d\n", tongDuongCheoChinh(matrix, n));
            printf("Tong cac phan tu tren duong cheo phu: %d\n", tongDuongCheoPhu(matrix, n));
            printf("Tong cac phan tu phia tren duong cheo chinh: %d\n", tongPhiaTrenDuongCheoChinh(matrix, n));
            printf("Tong cac phan tu phia tren duong cheo phu: %d\n", tongPhiaTrenDuongCheoPhu(matrix, n));

            system("pause");
            system("cls");
            break;
        }
        case 0:
            printf("Thoat chuong trinh.\n");
            break;
        default:
            printf("Lua chon khong hop le. Vui long chon lai.\n");
            break;
        }
    } while (choice1 != 0);

    system("pause");
    return 0;
}