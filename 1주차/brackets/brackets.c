#include <stdio.h>
#include <string.h>

int solution(const char *S) {
    char stack[1000];
    int top = -1;
    
    char matching_brackets[128] = {0};
    matching_brackets[')'] = '(';
    matching_brackets[']'] = '[';
    matching_brackets['}'] = '{';
    
    for (int i = 0; S[i] != '\0'; i++) {
        char current_char = S[i];
        
        if (current_char == '(' || current_char == '[' || current_char == '{') {
            stack[++top] = current_char; 
        } else if (current_char == ')' || current_char == ']' || current_char == '}') {
            if (top == -1 || stack[top] != matching_brackets[current_char]) {
                return 0;
            }
            top--; 
        }
    }
    
    return top == -1 ? 1 : 0; 
}