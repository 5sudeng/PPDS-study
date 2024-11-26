#include <queue>
using namespace std;  

class MyStack {
private: 
    queue<int> q1, tmp; //queue 두개로 구현 - q1이 메인..
public:
    MyStack() {
    }
    
    void push(int x) { //push는 그냥 push..
        q1.push(x);
    }
    
    int pop() { //pop이 관건 - q1이 하나 남을 때까지 (stack 기준 top만 남을 때까지) pop하면서 임시 큐에 넣어준다.
        int back = q1.back();
        while (q1.size() > 1) {
            tmp.push(q1.front());
            q1.pop();
        }
        q1.pop(); //q1을 마저 비우고... (초기상태가됨)
        swap(q1, tmp); //두개 바꿔주면..
        return back;
    }
    
    int top() { //top은 queue의 back으로..
        return q1.back();
    }
    
    bool empty() { 
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */