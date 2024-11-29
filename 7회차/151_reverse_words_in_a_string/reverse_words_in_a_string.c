#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* reverseWords(char* s) {
    int n = strlen(s); // 입력 문자열의 길이
    char* result = (char*)malloc((n + 1) * sizeof(char)); // 결과 문자열을 저장할 메모리 할당
    int end = n - 1, pos = 0;

    // 공백 처리 및 단어 순서 뒤집기
    while (end >= 0) {
        // 공백 건너뛰기
        while (end >= 0 && isspace(s[end])) end--;
        if (end < 0) break; // 더 이상 단어가 없으면 종료

        // 단어의 끝 위치 찾기
        int start = end;
        while (start >= 0 && !isspace(s[start])) start--;

        // 단어를 결과 문자열에 복사
        for (int i = start + 1; i <= end; i++) {
            result[pos++] = s[i];
        }

        // 단어 사이에 공백 추가
        if (start > 0) result[pos++] = ' ';

        // 다음 단어로 이동
        end = start - 1;
    }

    // 마지막 공백 제거
    if (pos > 0 && result[pos - 1] == ' ') pos--;

    result[pos] = '\0'; // 문자열 끝 표시
    return result; 
}