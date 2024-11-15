#include <stdio.h>

// 배열을 정렬하는 함수
void quickSort(int arr[], int low, int high);

// 배열을 분할하고 피벗의 위치를 반환하는 함수
int partition(int arr[], int low, int high);

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 퀵 정렬 함수
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // partition 함수 호출하여 피벗 위치 얻음
        int pivot_index = partition(arr, low, high);
        
        // 피벗을 기준으로 좌우 부분 배열을 재귀적으로 정렬
        quickSort(arr, low, pivot_index - 1);
        quickSort(arr, pivot_index + 1, high);
    }
}

// 분할 함수
int partition(int arr[], int low, int high) {
    int pivot = arr[low]; // 부분 리스트의 첫 번째 요소를 피벗으로 설정
    int left = low + 1;
    int right = high;

    while (1) {
        // left가 right보다 작고, arr[left]가 pivot보다 작거나 같은 동안 left 증가
        while (left <= right && arr[left] <= pivot) {
            left++;
        }

        // right가 left보다 크고, arr[right]가 pivot보다 큰 동안 right 감소
        while (left <= right && arr[right] > pivot) {
            right--;
        }

        // 교환될 요소를 찾았다면 두 요소를 교환
        if (left <= right) {
            swap(&arr[left], &arr[right]);
        } else {
            break;
        }
    }

    // 피벗을 제자리로 이동
    swap(&arr[low], &arr[right]);

    // 피벗의 최종 위치 반환
    return right;
}

// 메인 함수
int main() {
    int t;
    scanf("%d", &t); // 테스트 케이스 수 입력 받기

    for (int i = 0; i < t; i++) {
        int n;
        scanf("%d", &n); // 배열 크기 입력 받기

        int arr[n];
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[j]); // 배열 요소 입력 받기
        }

        quickSort(arr, 0, n - 1); // 퀵 정렬 수행

        for (int j = 0; j < n; j++) {
            printf("%d ", arr[j]); // 정렬된 배열 출력
        }
        printf("\n");
    }

    return 0;
}
