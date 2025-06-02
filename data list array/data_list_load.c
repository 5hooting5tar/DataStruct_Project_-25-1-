#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM 500

int main() {
    FILE *file = fopen("data.dat", "r");

    int data_list[MAX_NUM];

    int count = 0;
    while (count < MAX_NUM && fscanf(file, "%d", &data_list[count]) == 1) {
        count++;
    }

    printf("읽어온 정수들: \n");
    for (int i = 0; i < count; i++) {
        printf("%d ", data_list[i]);
    }
    printf("\n");

    fclose(file);
    return 0;
}
