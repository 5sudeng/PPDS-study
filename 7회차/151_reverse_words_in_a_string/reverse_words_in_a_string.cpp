#include <string>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string result = "", tmp = "";
        for (int i = s.size() - 1; i >= 0; --i) { //뒤에서 부터 순회
            if (s[i] == ' ') { //공백일 때 처리
                if (!tmp.empty()) { //tmp가 empty가 아닐 때 -> 즉, 단어가 tmp에 있을 때 => result에 추가해줘야 함
                    if (!result.empty()) result += " "; //result에 처음 넣는 단어가 아니라면 공백 넣어줌
                    result += tmp; 
                    tmp = ""; //reset
                }
            } else {
                tmp = s[i] + tmp; //공백이 아니면 아직 한 단어 순회중
            }
        }

        if (!tmp.empty()) { //마지막 단어가 공백이 아닌 경우 tmp에 남아있는 마지막 단어가 result에 추가되지 않음
            if (!result.empty()) result += " ";
            result += tmp;
        }

        return result;
    }
};
