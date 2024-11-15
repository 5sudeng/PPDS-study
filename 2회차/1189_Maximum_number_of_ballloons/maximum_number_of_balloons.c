#include <string.h>
#include <limits.h>

int maxNumberOfBalloons(char* text) {
    double cnt[5] = {0, 0, 0, 0, 0};
    double result = INT_MAX;
    char eng[5] = {'b', 'a', 'l', 'o', 'n'};
    double values[5] = {1, 1, 0.5, 0.5, 1};

    for (int i = 0; text[i] != '\0'; i++) {
        for (int j = 0; j < 5; j++) {
            if (text[i] == eng[j]) {
                cnt[j] += values[j];
                break;
            }
        }
    }

    for (int i = 0; i < 5; i++) {
        if (result > cnt[i]) {
            result = cnt[i];
        }
    }

    return (int)result;
}