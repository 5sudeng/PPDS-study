#include <stdio.h>
#include <string.h>

char* intToRoman(int num) {
    // 로마 숫자와 정수의 매핑
    struct {
        int value;
        char *symbol;
    } hash_table[] = {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
        {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
        {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
    };

    // 정렬하는 알고리즘을 따로 짜야하므로, 그냥 미리 순서대로 정의한다.

    static char ans[1000]; // 결과를 저장할 문자열
    memset(ans, 0, sizeof(ans)); // 초기화

    for (int i = 0; i < sizeof(hash_table) / sizeof(hash_table[0]); i++) {
        while (num >= hash_table[i].value) {
            strcat(ans, hash_table[i].symbol); // 로마 문자 추가
            num -= hash_table[i].value;       // 값 감소
        }
    }

    return ans;
}
