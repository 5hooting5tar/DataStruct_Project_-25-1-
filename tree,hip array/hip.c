#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) { int t = *a; *a = *b; *b = t; }

void heapify(int arr[], int n, int i) {
    int largest = i, l = 2*i+1, r = 2*i+2;
    if (l < n && arr[l] > arr[largest]) largest = l;
    if (r < n && arr[r] > arr[largest]) largest = r;
    if (largest != i) { swap(&arr[i], &arr[largest]); heapify(arr, n, largest); }
}

void buildHeap(int arr[], int n) { 
    for (int i = n/2-1; i >= 0; i--) heapify(arr, n, i); 
}

void heapSort(int arr[], int n) {
    buildHeap(arr, n);
    for (int i = n-1; i > 0; i--) { 
        swap(&arr[0], &arr[i]); 
        heapify(arr, i, 0); 
    }
}

void reverse(int arr[], int n) { 
    for (int i=0; i < n/2; i++) swap(&arr[i], &arr[n-1-i]); 
}

void printArr(int arr[], int n, FILE *fp) { 
    for (int i=0; i <n; i++) fprintf(fp, "%d ", arr[i]); 
    fprintf(fp, "\n"); 
}

int main() {
    FILE *in = fopen("hip.in", "r"), 
        *out = fopen("result.out", "w");
    int *arr = NULL, cap = 10, size = 0, num;

    if (!in) { perror("hip.in 오픈 실패"); return 1; }
    arr = (int*)malloc(cap * sizeof(int));
    while (fscanf(in, "%d", &num) == 1) {
        if (size >= cap) arr = (int*)realloc(arr, (cap *=2) * sizeof(int));
        arr[size++] = num;
    }
    fclose(in);

    // 초기 배열 출력
    fprintf(out, "[ 초기 배열 상태 ]\n"); 
    printArr(arr, size, out);
    printf("\n[ 초기 배열 상태 ]\n"); 
    printArr(arr, size, stdout);

    // 힙 구성 후 출력
    buildHeap(arr, size);
    fprintf(out, "\n[ 힙 구성 후 상태 ]\n"); 
    printArr(arr, size, out);
    printf("\n[ 힙 구성 후 상태 ]\n"); 
    printArr(arr, size, stdout);

    // 힙 정렬, 결과 출력
    heapSort(arr, size);
    reverse(arr, size);
    fprintf(out, "\n[ 내림차순 정렬 결과 ]\n"); 
    printArr(arr, size, out);
    printf("\n[ 내림차순 정렬 결과 ]\n"); 
    printArr(arr, size, stdout);

    free(arr); 
    fclose(out);
    return 0;
}