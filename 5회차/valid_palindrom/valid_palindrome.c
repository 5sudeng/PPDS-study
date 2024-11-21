#include <stdio.h>
#include <stdbool.h>

// 알파벳이나 숫자인지 확인하는 함수
bool isAlphaNumeric(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
}

// 대문자를 소문자로 변환하는 함수
char toLower(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c + ('a' - 'A'); // 대문자를 소문자로 변환
    }
    return c;
}

// 회문인지 확인하는 함수
bool isPalindrome(const char *s) {
    int left = 0;
    int right = 0;

    // 문자열 끝 위치 찾기
    while (s[right] != '\0') {
        right++;
    }
    right--; // 마지막 유효 문자 위치

    // 투 포인터 검사
    while (left < right) {
        // 왼쪽 포인터가 알파벳이나 숫자가 아닐 때 이동
        while (left < right && !isAlphaNumeric(s[left])) {
            left++;
        }
        // 오른쪽 포인터가 알파벳이나 숫자가 아닐 때 이동
        while (left < right && !isAlphaNumeric(s[right])) {
            right--;
        }

        // 소문자로 변환 후 비교
        if (toLower(s[left]) != toLower(s[right])) {
            return false;
        }

        left++;
        right--;
    }

    return true;
}

int main() {
    // 테스트 케이스
    const char *test1 = "A man, a plan, a canal: Panama";
    const char *test2 = "racecar";
    const char *test3 = "hello";
    const char *test4 = "Not a palindrome";

    printf("Test 1: %s\n", isPalindrome(test1) ? "true" : "false"); // true
    printf("Test 2: %s\n", isPalindrome(test2) ? "true" : "false"); // true
    printf("Test 3: %s\n", isPalindrome(test3) ? "true" : "false"); // false
    printf("Test 4: %s\n", isPalindrome(test4) ? "true" : "false"); // false

    return 0;
}
