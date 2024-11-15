/*
You are given integers K, M and a non-empty array A consisting of N integers. Every element of the array is not greater than M.

You should divide this array into K blocks of consecutive elements. The size of the block is any integer between 0 and N. Every element of the array should belong to some block.

The sum of the block from X to Y equals A[X] + A[X + 1] + ... + A[Y]. The sum of empty block equals 0.

The large sum is the maximal sum of any block.

For example, you are given integers K = 3, M = 5 and array A such that:

  A[0] = 2
  A[1] = 1
  A[2] = 5
  A[3] = 1
  A[4] = 2
  A[5] = 2
  A[6] = 2
The array can be divided, for example, into the following blocks:

[2, 1, 5, 1, 2, 2, 2], [], [] with a large sum of 15;
[2], [1, 5, 1, 2], [2, 2] with a large sum of 9;
[2, 1, 5], [], [1, 2, 2, 2] with a large sum of 8;
[2, 1], [5, 1], [2, 2, 2] with a large sum of 6.
The goal is to minimize the large sum. In the above example, 6 is the minimal large sum.

Write a function:

int solution(int K, int M, vector<int> &A);

that, given integers K, M and a non-empty array A consisting of N integers, returns the minimal large sum.

For example, given K = 3, M = 5 and array A such that:

  A[0] = 2
  A[1] = 1
  A[2] = 5
  A[3] = 1
  A[4] = 2
  A[5] = 2
  A[6] = 2
the function should return 6, as explained above.

Write an efficient algorithm for the following assumptions:

N and K are integers within the range [1..100,000];
M is an integer within the range [0..10,000];
each element of array A is an integer within the range [0..M].
*/

#include <vector>
#include <iostream>
#include <climits>

using namespace std;

// max element of vector
int max(const vector<int> vec) {
    int sol = INT_MIN;
    for (size_t i=0; i<vec.size(); ++i) {
        if (vec[i] > sol) { sol = vec[i]; }
    }
    return sol;
}

// sum all elements in vector
int sum(const vector<int> vec) {
    int sol = 0;
    for (size_t i=0; i<vec.size(); ++i) {
        sol += vec[i];
    }
    return sol;
}

int solution(int K, int M, vector<int> &A) {
    // large sum으로 가능한 최솟값과 최댓값
    int low = max(A);
    int high = sum(A);

    while (low != high) {

        // 중간값을 large sum으로 가정하여 A를 K개의 블록으로 나눌 수 있을지 확인
        int mid = (low+high)/2;
        int cnt = 1; // 현재까지 나눈 블록의 개수
        int tmp = 0; // 현재 블록의 sum

        for (auto x : A) {
            if (tmp + x > mid) { // 현재 요소를 더했을 때, 가정한 large sum을 초과하면
                cnt += 1; tmp = x; // 현재 요소부터 새로운 블록을 시작
            }
            else {
                tmp += x;
            }
        }

        if (cnt > K) { low = mid+1; } // mid 값이 너무 작다는 뜻 -> 탐색 범위를 올림
        else if (cnt <= K) { high = mid; } // (걍 else임..) mid보다 더 작은 값이 가능하다는 뜻 -> 탐색 범위를 내림
    }

    return low; // = high
}