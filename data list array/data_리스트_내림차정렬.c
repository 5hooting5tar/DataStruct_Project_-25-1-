#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM 500

int main() {

    // ���� �б�
    FILE *file_read = fopen("data.dat", "r");

    int data_list[MAX_NUM];
    int count = 0;

    while (count < MAX_NUM && fscanf(file_read, "%d", &data_list[count]) == 1)
    {
        count++;
    }
    fclose(file_read);

    // �������� ����
    for (int list_num = 0; list_num < count - 1; list_num++)
    {
        for (int list_loop = 0; list_loop < count - 1 - list_num; list_loop++)
        {
            if (data_list[list_loop] < data_list[list_loop+1])
            {
                int save_data = data_list[list_loop];
                data_list[list_loop] = data_list[list_loop+1];
                data_list[list_loop+1] = save_data;
            }
        }
    }

    // �������� ���� ����(data.dat)
    FILE *file_write = fopen("data.dat", "w");

    for (int i = 0; i < count; i++)
    {
        fprintf(file_write, "%d\n", data_list[i]);
    }
    fclose(file_write);

    // �������� ���� ����Ʈ ���
    system("cls");
    printf("\n----------------------------------------\n");
    printf("�������� ���ĵ� ������\n");
    printf("----------------------------------------\n");
    for (int i = 0; i < count; i++)
    {
        printf("%d \n", data_list[i]);
    }
    printf("----------------------------------------\n");
    printf("data.dat ���Ͽ� ����Ʈ�� ����Ǿ����ϴ�.\n");
    printf("----------------------------------------\n");
    return 0;
}
