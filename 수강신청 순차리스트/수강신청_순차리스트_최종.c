#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define _CRT_SECURE_NO_WARNINGS

#define FILENAME "enroll.txt"
#define N 40
typedef struct {
	int id;
	char name[10];
} student;

student enroll[N];
int length = -1;

int apply(student s) {
    if (length == N - 1) {
        return 0; // fail
    }
    enroll[++length] = s;
    return 1; // success
}

int drop(int id) {
    int i;
    for (i = 0; i <= length; i++) {
        if (enroll[i].id == id) break;
    }
    if (i > length) return 0; // fail
    for (int j = i; j < length; j++) {
        enroll[j] = enroll[j + 1];
    }
    length--;
    return 1; // success
}

void print() {
    system("cls");
    printf(" \n \n ** 수강신청 목록 **\n");
    printf("-------------------------------\n");
    printf("학번\t\t이름\n");
    printf("-------------------------------\n");

    if (length <= 0) {
        printf("수강신청 내역이 없습니다.\n");
    } else {
        for (int i = 0; i <= length; i++) {
            if (i <= length) {
                if (enroll[i].name[0] != '\0')
                {
                    printf("%d\t\t%s\n", enroll[i].id, enroll[i].name);

                }

            }
        }
    }
    printf("-------------------------------\n");
}

void save() {
	FILE* f1 = fopen(FILENAME, "w");
	for (int i = 0; i <= length; i++) {
		fprintf(f1, "%d %s\n", enroll[i].id, enroll[i].name);
	}
	fclose(f1);
}

void load() {
    length = -1;
    FILE* f1 = fopen(FILENAME, "r");
    char temp[10];
    while (fscanf(f1, "%d %s", &enroll[++length].id, temp) == 2) {
        enroll[length].name[0] = temp[0];
        enroll[length].name[1] = '\0';
    }
    fclose(f1);
}

void doRequest(char ch) {
	student s; int flag;
	switch (ch) {
	case '1': system("cls"); printf(" \n \n ** 수강신청 처리중 **\n");
		printf(" \n 학번 : "); scanf("%d", &s.id);
		printf(" \n 이름 : "); scanf("%s", s.name);
		flag = apply(s);
		if (flag == 0) printf(" \n \n 수강신청 마감됨. \n\n");
		else printf(" \n\n 수강신청 승인했음! \n\n");
		break;
	case '2': system("cls"); printf(" \n \n ** 수강철회 처리중 **\n");
		printf(" \n 학번 : "); scanf("%d", &s.id);
		flag = drop(s.id);
		if (flag == 0) printf(" \n \n 수강신청 정보없음! \n\n");
		else printf(" \n\n 신청철회 승인했음! \n\n");
		break;
	case '3': system("cls"); print();
		break;
	case 'q': system("cls"); save();
		printf("  \n\n  프로그램 종료 \n\n");
		break;
	default: system("cls"); printf("\n\n 잘못 입력했음. \n");
		printf("'1'~'3' 또는 'q'를 입력해야 함 \n\n");
	}
}

int main() {
	int id; char ch;
	load();
	do
	{
		system("cls");
		printf("\n------------------------------------\n");
		printf("  자료구조 수강신청 및 수강철회  \n");
		printf("------------------------------------\n");
		printf("1. 수강신청 ('1') \n");
		printf("2. 수강철회 ('2') \n");
		printf("3. 수강조회 ('3') \n");
		printf("4. 종　　료 ('q') \n");
		printf("------------------------------------\n");
		printf("원하시는 서비스를 선택하세요 : ");
		ch = getche();
		doRequest(ch);
		printf("\n\n  임의의 키를 눌러 주세요"); getche();
	} while (ch != 'q');

}
