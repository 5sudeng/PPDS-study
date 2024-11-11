/*
Dynamic programming!
문제 설명은 readme 참고..
base case : n=1, n=2, n=3 (1,2,3을 더해서 만들어야 하는 상황..)
점화식 -> n의 경우의수 = n-1일 때 + n-2일 때 + n-3일 때..

4
arr[1] -> 3
arr[2] -> 2
arr[3] -> 1
*/
#include <iostream>
using namespace std;

int main(void) {
    int n, tmp;
    int arr[11];
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 4;
    
    for (int i=4; i<11;i++) {
        arr[i] = arr[i-1] + arr[i-2] + arr[i-3];
    }

    cin >> n;
    
    for (int i=0; i<n; i++) {
        cin >> tmp;
        cout << arr[tmp] << endl;
    }
    return 0;
}