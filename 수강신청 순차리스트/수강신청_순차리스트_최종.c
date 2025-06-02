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
    printf(" \n \n ** ������û ��� **\n");
    printf("-------------------------------\n");
    printf("�й�\t\t�̸�\n");
    printf("-------------------------------\n");

    if (length <= 0) {
        printf("������û ������ �����ϴ�.\n");
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
	case '1': system("cls"); printf(" \n \n ** ������û ó���� **\n");
		printf(" \n �й� : "); scanf("%d", &s.id);
		printf(" \n �̸� : "); scanf("%s", s.name);
		flag = apply(s);
		if (flag == 0) printf(" \n \n ������û ������. \n\n");
		else printf(" \n\n ������û ��������! \n\n");
		break;
	case '2': system("cls"); printf(" \n \n ** ����öȸ ó���� **\n");
		printf(" \n �й� : "); scanf("%d", &s.id);
		flag = drop(s.id);
		if (flag == 0) printf(" \n \n ������û ��������! \n\n");
		else printf(" \n\n ��ûöȸ ��������! \n\n");
		break;
	case '3': system("cls"); print();
		break;
	case 'q': system("cls"); save();
		printf("  \n\n  ���α׷� ���� \n\n");
		break;
	default: system("cls"); printf("\n\n �߸� �Է�����. \n");
		printf("'1'~'3' �Ǵ� 'q'�� �Է��ؾ� �� \n\n");
	}
}

int main() {
	int id; char ch;
	load();
	do
	{
		system("cls");
		printf("\n------------------------------------\n");
		printf("  �ڷᱸ�� ������û �� ����öȸ  \n");
		printf("------------------------------------\n");
		printf("1. ������û ('1') \n");
		printf("2. ����öȸ ('2') \n");
		printf("3. ������ȸ ('3') \n");
		printf("4. �������� ('q') \n");
		printf("------------------------------------\n");
		printf("���Ͻô� ���񽺸� �����ϼ��� : ");
		ch = getche();
		doRequest(ch);
		printf("\n\n  ������ Ű�� ���� �ּ���"); getche();
	} while (ch != 'q');

}
