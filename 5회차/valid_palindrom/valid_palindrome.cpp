#include <iostream>
#include <string>

class Solution {
public:
    bool isPalindrome(const std::string& s) {
        // 투 포인터 초기화
        int left = 0;
        int right = s.size() - 1;

        while (left < right) {
            // 왼쪽 포인터가 알파벳이나 숫자가 아닐 때 이동
            while (left < right && !isAlphaNumeric(s[left])) {
                ++left;
            }
            // 오른쪽 포인터가 알파벳이나 숫자가 아닐 때 이동
            while (left < right && !isAlphaNumeric(s[right])) {
                --right;
            }

            // 소문자로 비교
            if (toLower(s[left]) != toLower(s[right])) {
                return false;
            }

            ++left;
            --right;
        }

        return true;
    }

private:
    // 알파벳 또는 숫자인지 확인
    bool isAlphaNumeric(char c) {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
    }

    // 소문자로 변환
    char toLower(char c) {
        if (c >= 'A' && c <= 'Z') {
            return c + ('a' - 'A'); // 대문자를 소문자로
        }
        return c;
    }
};

int main() {
    Solution solution;

    // 테스트 케이스
    std::cout << std::boolalpha; // true/false 출력
    std::cout << solution.isPalindrome("A man, a plan, a canal: Panama") << std::endl; // true
    std::cout << solution.isPalindrome("racecar") << std::endl;                        // true
    std::cout << solution.isPalindrome("hello") << std::endl;                          // false
    std::cout << solution.isPalindrome("Not a palindrome") << std::endl;              // false

    return 0;
}
