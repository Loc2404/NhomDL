#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <random>
#include <conio.h>
#include <algorithm>
#include <unordered_map>

void split_name(char* full_name, char* last_name, char* first_name) {
	// Tìm vị trí của khoảng trắng cuối cùng trong chuỗi
	int i, len = strlen(full_name);
	for (i = len - 1; i >= 0; i--) {
		if (full_name[i] == ' ') {
			break;
		}
	}

	// Sao chép họ lót vào chuỗi last_name
	strncpy(last_name, full_name, i);
	last_name[i] = '\0';

	// Sao chép tên vào chuỗi first_name
	strcpy(first_name, full_name + i + 1);
}

int main() {
	int choice;


	do {
		printf( "=== MENU ===\n");
		printf("1. Viet ham cat chuoi ho ten.\n");
		printf("2. Chen 1 tu vao chuoi.\n");
		printf("3. Xoa 1 tu trong chuoi.\n");
		printf("4. So lan xuat hien cac tu trong chuoi.\n");
		printf("5. Tu xuat hien nhieu nhat trong chuoi.\n");
		printf("0. Thoat chuong trinh.\n");
		printf("Nhap lua chon(0-5): ");
		scanf(" %d", &choice);
		scanf("%*c");
		switch (choice) {
		case 1:
		{
			char fullName[100];
			char lastName[50], firstName[50];
			printf("Nhập chuỗi: ");
			fgets(fullName, sizeof(fullName), stdin);
			fullName[strcspn(fullName, "\n")] = '\0';
			split_name(fullName, lastName, firstName);
			printf("Ho lot: %s\nTen: %s\n", lastName, firstName);
			system("pause");
			system("cls");
			break;
		}
		case 2:
		{
			char str[100], word[50];
			int pos;

			printf("Nhap chuoi: ");
			fgets(str, sizeof(str), stdin);
			str[strcspn(str, "\n")] = '\0'; // Xóa ký tự xuống dòng

			printf("Nhap tu can chen: ");
			scanf("%s", word);

			printf("Nhap vi tri chen (0-based): ");
			scanf("%d", &pos);

			// Chèn từ vào vị trí yêu cầu
			memmove(str + pos + strlen(word), str + pos, strlen(str) - pos + 1);
			strncpy(str + pos, word, strlen(word));

			printf("Chuoi sau khi chen: %s\n", str);
			system("pause");
			system("cls");
			break;
		}
			
		case 3:
		{
			char str[100];
			char word[50];

			printf("Nhap chuoi: ");
			fgets(str, sizeof(str), stdin);
			str[strcspn(str, "\n")] = '\0'; // Xóa ký tự newline

			printf("Nhap tu can xoa: ");
			fgets(word, sizeof(word), stdin);
			word[strcspn(word, "\n")] = '\0'; // Xóa ký tự newline

			char* p = strstr(str, word);
			if (p != NULL) {
				memmove(p, p + strlen(word), strlen(p + strlen(word)) + 1);
				printf("Chuoi sau khi xoa: %s\n", str);
			}
			else {
				printf("Khong tim thay tu '%s' trong chuoi.\n", word);
			}

			system("pause");
			system("cls");
			break;
		}
			
		case 4:
		{
			char str[100];
			int charCount[256] = { 0 };

			printf("Nhap chuoi: ");
			fgets(str, sizeof(str), stdin);
			str[strcspn(str, "\n")] = '\0'; // Xóa ký tự xuống dòng

			for (int i = 0; i < strlen(str); i++) {
				charCount[(int)str[i]]++;
			}

			printf("So lan xuat hien cua cac ky tu:\n");
			for (int i = 0; i < 256; i++) {
				if (charCount[i] > 0) {
					printf("%c: %d\n", (char)i, charCount[i]);
				}
			}
			system("pause");
			system("cls");
			break;
		}
			
		case 5:
		{
			char str[100];
			int charCount[256] = { 0 };
			int maxCount = 0;
			char maxChar;

			printf("Nhap chuoi: ");
			fgets(str, sizeof(str), stdin);
			str[strcspn(str, "\n")] = '\0'; // Xóa ký tự xuống dòng

			for (int i = 0; i < strlen(str); i++) {
				charCount[(int)str[i]]++;
			}

			for (int i = 0; i < 256; i++) {
				if (charCount[i] > maxCount) {
					maxCount = charCount[i];
					maxChar = (char)i;
				}
			}

			printf("Ky tu xuat hien nhieu nhat la '%c' voi %d lan xuat hien.\n", maxChar, maxCount);
			system("pause");
			system("cls");
			break;
		}
		case 0:
			printf("Thoat chuong trinh.\n");
			break;
		default:
			printf("Lua chon khong hop le. Vui long chon lai.");
			break;
		}
	} while (choice != 0);

	return 0;
}