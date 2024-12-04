#include <vector>
#include <unordered_map>
#include <stack>
#include <algorithm>
#include <iterator>

class Solution {
public:
    // 직접 구현한 std::find
    template <typename Iterator, typename T>
    Iterator custom_find(Iterator begin, Iterator end, const T& value) {
        for (Iterator it = begin; it != end; ++it) {
            if (*it == value) {
                return it; // 값이 일치하면 해당 반복자를 반환
            }
        }
        return end; // 값이 없으면 끝 반복자를 반환
    }

    // 직접 구현한 std::distance
    template <typename Iterator>
    typename std::iterator_traits<Iterator>::difference_type 
    custom_distance(Iterator begin, Iterator end) {
        typename std::iterator_traits<Iterator>::difference_type count = 0;
        for (Iterator it = begin; it != end; ++it) {
            ++count;
        }
        return count;
    }

    // O(M * N) 방식
    std::vector<int> naive_nextGreaterElement(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::vector<int> answer;
        for (int target : nums1) {
            // nums2에서 target 위치 찾기
            auto it = custom_find(nums2.begin(), nums2.end(), target); // custom_find 사용
            int idx = custom_distance(nums2.begin(), it);              // custom_distance 사용

            // 다음 큰 숫자 탐색
            int next_greater = -1;
            for (int i = idx + 1; i < nums2.size(); ++i) {
                if (nums2[i] > target) {
                    next_greater = nums2[i];
                    break;
                }
            }
            answer.push_back(next_greater);
        }
        return answer;
    }

    // O(M + N) 방식
    std::vector<int> nextGreaterElement(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::unordered_map<int, int> next_greater;
        std::stack<int> st;
        std::vector<int> answer;

        // nums2를 오른쪽에서 왼쪽으로 순회
        for (int i = nums2.size() - 1; i >= 0; --i) {
            while (!st.empty() && st.top() <= nums2[i]) {
                st.pop(); // 현재 숫자보다 작거나 같은 스택 값 제거
            }

            // 맵에 다음 큰 숫자 기록
            next_greater[nums2[i]] = st.empty() ? -1 : st.top();

            // 현재 숫자를 스택에 추가
            st.push(nums2[i]);
        }

        // nums1의 각 원소에 대해 답 생성
        for (int num : nums1) {
            answer.push_back(next_greater[num]);
        }
        return answer;
    }
};
