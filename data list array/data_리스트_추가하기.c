#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM 500

int main() {
    FILE *file = fopen("data.dat", "w");

    int data_list[MAX_NUM];
    int count = 0;

    system("cls");
    printf("\n-------------------------------------------------------\n");
    printf("������ ������ ������ �Է��ϼ��� (�ּ� 20��, �ִ� %d��)\n", MAX_NUM);
    printf("-------------------------------------------------------\n");
    printf("���� �Է� : "); scanf("%d", &count);

    if (count > MAX_NUM) {
        count = MAX_NUM;
    } if (20 < MAX_NUM) {
        count = 20;
    }

    for (int i = 0; i < count; i++) {
    system("cls");
    printf("\n-------------------------------\n");
    printf("%d���� ������ �Է��ϼ���: \n", count);
    printf("%d / %d �Ϸ�\n", i+1, count);
    printf("-------------------------------\n");
    printf("���� �Է� : "); scanf("%d", &data_list[i]);
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%d\n", data_list[i]);
    }

    system("cls");
    printf("\n----------------------------------------\n");
    printf("\data.dat ���Ͽ� ����Ʈ�� ����Ǿ����ϴ�.\n");
    printf("----------------------------------------\n");

    fclose(file);
    return 0;
}
