#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// frequencySort 함수 정의
char* frequencySort(char* s) {
    int hash[128] = {0}; // ASCII 문자 빈도 계산 배열
    int len = strlen(s);

    // 빈도 계산
    for (int i = 0; i < len; i++) {
        hash[(int)s[i]]++; // 각 문자의 ASCII 값을 인덱스로 사용
    }

    // 문자와 빈도를 저장하는 배열 생성
    char characters[128]; // 설정하기 나름.
    int frequencies[128];
    int count = 0; // 유효한 문자 개수

    for (int i = 0; i < 128; i++) {
        if (hash[i] > 0) {
            characters[count] = (char)i; // 문자 저장
            frequencies[count] = hash[i]; // 빈도 저장
            count++;
        }
    }

    // 빈도를 기준으로 내림차순 정렬 (버블 정렬 사용)
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (frequencies[j] < frequencies[j + 1] || 
                (frequencies[j] == frequencies[j + 1] && characters[j] > characters[j + 1])) {
                // 빈도가 더 작거나, 빈도가 같고 문자가 더 큰 경우 교환
                int tempFreq = frequencies[j];
                char tempChar = characters[j];

                frequencies[j] = frequencies[j + 1];
                characters[j] = characters[j + 1];

                frequencies[j + 1] = tempFreq;
                characters[j + 1] = tempChar;
            }
        }
    }

    // 결과 문자열 생성
    char* result = (char*)malloc(len + 1); // 결과 문자열 메모리 할당
    int index = 0;

    for (int i = 0; i < count; i++) {
        for (int j = 0; j < frequencies[i]; j++) {
            result[index++] = characters[i]; // 빈도만큼 문자 추가
        }
    }
    result[index] = '\0'; // 문자열 종료

    return result;
}

int main() {
    char s[] = "Aabb";

    char* sortedString = frequencySort(s);
    printf("%s\n", sortedString);

    free(sortedString); // 동적 메모리 해제
    return 0;
}
