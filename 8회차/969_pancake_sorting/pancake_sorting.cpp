#include <vector>
using namespace std;

class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> result;
        int n = arr.size();
        
        /*
        // 현재 범위를 줄여가며 반복
        for (int currentSize = n; currentSize > 1; --currentSize) {
            // 현재 범위에서 가장 큰 값의 인덱스 찾기
            int maxIndex = max_element(arr.begin(), arr.begin() + currentSize) - arr.begin();
            
            // 가장 큰 값이 이미 제자리에 있으면 건너뜀
            if (maxIndex == currentSize - 1) continue;

            // 1. 가장 큰 값을 맨 앞으로 뒤집음
            if (maxIndex != 0) {
                result.push_back(maxIndex + 1);
                reverse(arr.begin(), arr.begin() + maxIndex + 1);
            }

            // 2. 가장 큰 값을 현재 범위의 끝으로 이동
            result.push_back(currentSize);
            reverse(arr.begin(), arr.begin() + currentSize);
        }
        */
        // 현재 범위를 줄여가며 반복
        for (int currentSize = n; currentSize > 1; --currentSize) {
            // 1. 현재 범위에서 가장 큰 값의 인덱스 찾기
            int maxIndex = 0;
            for (int i = 1; i < currentSize; ++i) {
                if (arr[i] > arr[maxIndex]) {
                    maxIndex = i;
                }
            }

            // 2. 가장 큰 값이 이미 제자리에 있으면 건너뜀
            if (maxIndex == currentSize - 1) continue;

            // 3. 가장 큰 값을 맨 앞으로 뒤집음
            if (maxIndex != 0) {
                result.push_back(maxIndex + 1);
                reverse(arr, 0, maxIndex);
            }

            // 4. 가장 큰 값을 현재 범위의 끝으로 이동
            result.push_back(currentSize);
            reverse(arr, 0, currentSize - 1);
        }

        return result;
    }

private:
    // Sub-array [0...end] 뒤집기
    void reverse(vector<int>& arr, int start, int end) {
        while (start < end) {
            swap(arr[start], arr[end]);
            start++;
            end--;
        }
    }
};