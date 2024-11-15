#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex+1, 1); // rowIndex + 1개만큼 1로 채워둠

        for (int i = 2 ; i < rowIndex+1 ; i++){ // rowIndex 0, 1은 basecase니까 2부터 시작
            for (int j = i-1 ; j > 0 ; j--){ // j가 i-1부터 감소하면서 이전 값을 더해서 update 
                row[j] += row[j-1]; // ex) 1 3 3 1 -> 1 3 3 4 -> 1 3 6 4 -> 1 4 6 4 
            }
        }

        return row;
    }
};

int main() {
    int rowIndex;
    cout << "Enter the row index: ";
    cin >> rowIndex;

    Solution solution;
    vector<int> result = solution.getRow(rowIndex);

    cout << "The " << rowIndex << "-th row of Pascal's triangle is: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
