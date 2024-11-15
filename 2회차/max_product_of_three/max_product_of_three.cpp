#include <iostream>
#include <vector>
#include <algorithm>  
using namespace std;

int solution(vector<int>& A) {
    sort(A.begin(), A.end());

    int max_product_1 = A[A.size() - 1] * A[A.size() - 2] * A[A.size() - 3];
    int max_product_2 = A[0] * A[1] * A[A.size() - 1];

    if (A[0] >= 0) {
        return max_product_1;
    } else if (A[1] < 0) {
        return max(max_product_1, max_product_2);
    } else {
        return max_product_1;
    }
}
