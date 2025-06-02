#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM 500

int main() {
    FILE *file = fopen("data.dat", "w");

    int data_list[MAX_NUM];
    int count = 0;

    system("cls");
    printf("\n-------------------------------------------------------\n");
    printf("저장할 정수의 개수를 입력하세요 (최소 20개, 최대 %d개)\n", MAX_NUM);
    printf("-------------------------------------------------------\n");
    printf("정수 입력 : "); scanf("%d", &count);

    if (count > MAX_NUM) {
        count = MAX_NUM;
    } if (20 < MAX_NUM) {
        count = 20;
    }

    for (int i = 0; i < count; i++) {
    system("cls");
    printf("\n-------------------------------\n");
    printf("%d개의 정수를 입력하세요: \n", count);
    printf("%d / %d 완료\n", i+1, count);
    printf("-------------------------------\n");
    printf("정수 입력 : "); scanf("%d", &data_list[i]);
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%d\n", data_list[i]);
    }

    system("cls");
    printf("\n----------------------------------------\n");
    printf("\data.dat 파일에 리스트가 저장되었습니다.\n");
    printf("----------------------------------------\n");

    fclose(file);
    return 0;
}
