#include <stdio.h>

int main(void) {
    int n, tmp;
    int arr[11];
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 4;
    
    for (int i=4; i<11;i++) {
        arr[i] = arr[i-1] + arr[i-2] + arr[i-3];
    }

    scanf("%d", &n);
    
    for (int i=0; i<n; i++) {
        scanf("%d", &tmp);
        printf("%d\n", arr[tmp]);
    }
    return 0;
}