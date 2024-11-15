#include <iostream>
#include <stack>
#include <unordered_map>
#include <string>

int solution(const std::string &S) {
    std::unordered_map<char, char> matching_brackets = {{')', '('}, {']', '['}, {'}', '{'}};
    std::stack<char> stack;

    for (char current_char : S) {
        if (current_char == '(' || current_char == '[' || current_char == '{') {
            stack.push(current_char); 
        } else if (current_char == ')' || current_char == ']' || current_char == '}') {
            if (stack.empty() || stack.top() != matching_brackets[current_char]) {
                return 0; 
            }
            stack.pop(); 
        }
    }

    return stack.empty() ? 1 : 0; 
}