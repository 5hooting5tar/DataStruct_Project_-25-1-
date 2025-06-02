#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define N 10

struct btNode {
    int data;                // 키 값: 정수형
    struct btNode *left;     // 왼쪽 자식
    struct btNode *right;    // 오른쪽 자식
};
struct btNode *bt = NULL;    // 트리의 루트 포인터

// 탐색 함수 (7.6)
struct btNode *searchBST(struct btNode *bt, int key) {
    if (bt == NULL) return NULL;
    if (key == bt->data) return bt;
    if (key < bt->data) return searchBST(bt->left, key);
    return searchBST(bt->right, key); // 정상 처리
}

// 추가 함수 (7.7)
int insertBST(struct btNode **t, int x) {
    struct btNode *temp;
    if (*t == NULL) {
        temp = (struct btNode *)malloc(sizeof(struct btNode));
        temp->data = x;
        temp->left = temp->right = NULL;
        *t = temp;
        return 1;
    }
    if (x == (*t)->data) return 0; // 이미 존재
    if (x < (*t)->data) return insertBST(&((*t)->left), x);
    return insertBST(&((*t)->right), x); // 정상 처리
}

// 삭제 함수
int deleteBST(struct btNode **t, int key) {
    struct btNode *current = *t, *parent = NULL;

    // 삭제할 노드 탐색
    while (current != NULL && current->data != key) {
        parent = current;
        current = (key < current->data) ? current->left : current->right;
    }
    if (current == NULL) return 0; // 노드 없음

    // 단말 노드
    if (current->left == NULL && current->right == NULL) {
        if (parent == NULL) *t = NULL;
        else if (parent->left == current) parent->left = NULL;
        else parent->right = NULL;
        free(current);
    }
    // 한 개 자식
    else if (current->left == NULL || current->right == NULL) {
        struct btNode *child = (current->left != NULL) ? current->left : current->right;
        if (parent == NULL) *t = child;
        else if (parent->left == current) parent->left = child;
        else parent->right = child;
        free(current);
    }
    // 두 개 자식
    else {
        struct btNode *successorParent = current, *successor = current->right;
        while (successor->left != NULL) {
            successorParent = successor;
            successor = successor->left;
        }
        current->data = successor->data;
        if (successorParent == current) successorParent->right = successor->right;
        else successorParent->left = successor->right;
        free(successor);
    }
    return 1; // 정상 처리
}

// 트리 저장 함수 (out_bst.txt)
void saveBST(struct btNode *node, FILE *fp) {
    if (node == NULL) return;
    fprintf(fp, "%d ", node->data);
    saveBST(node->left, fp);
    saveBST(node->right, fp);
}

// 트리 로드 함수 (in_bst.txt)
void loadBST(struct btNode **root) {
    FILE *fp = fopen("innout_bst.txt", "r");
    if (fp == NULL) return;

    int key;
    while (fscanf(fp, "%d", &key) == 1) {
        insertBST(root, key);
    }
    fclose(fp);
}

// 메뉴 처리 함수
void processingRequest(char ch) {
    int key;
    struct btNode *result;
    switch (ch) {
        case 's': // 탐색
            printf("\n탐색할 키 입력: ");
            scanf("%d", &key);
            result = searchBST(bt, key);
            if (result != NULL)
                printf("키 %d를 찾았습니다.\n", key);
            else
                printf("키 %d가 트리에 없습니다.\n", key);
            break;
        case 'i': // 추가
            printf("\n추가할 키 입력: ");
            scanf("%d", &key);
            if (insertBST(&bt, key))
                printf("키 %d 추가 완료.\n", key);
            else
                printf("키 %d는 이미 존재합니다.\n", key);
            break;
        case 'd': // 삭제
            printf("\n삭제할 키 입력: ");
            scanf("%d", &key);
            if (deleteBST(&bt, key))
                printf("키 %d 삭제 완료.\n", key);
            else
                printf("키 %d를 찾을 수 없습니다.\n", key);
            break;
        case 'q':
            printf("\n프로그램을 종료합니다.\n");
            break;
        default:
            printf("\n잘못된 메뉴 선택입니다.\n");
            break;
    }
}

// 메인 코드
int main(void) {
    // int i, key;
    char ch;
    loadBST(&bt);

    do {
        system("cls");
        printf("\n----------------------\n");
        printf("이진탐색트리 탐색/추가/삭제\n");
        printf("----------------------\n");
        printf("- 키 탐색('s')\n");
        printf("- 키 추가('i')\n");
        printf("- 키 삭제('d')\n");
        printf("- 종료('q')\n");
        printf("----------------------\n");
        ch = getche();
        processingRequest(ch); // 사용자 선택 처리
        printf("\n\n 임의의 키를 눌러 주세요"); getche();
    } while (ch != 'q');

    FILE *fp = fopen("innout_bst.txt", "w");
    if (fp != NULL) {
        saveBST(bt, fp);
        fclose(fp);
    }
    return 0;
}
