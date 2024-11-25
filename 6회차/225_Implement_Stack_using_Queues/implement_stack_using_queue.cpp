#include <queue>
using namespace std;  

class MyStack {
private: 
    queue<int> q1, tmp;
public:
    MyStack() {
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        int back = q1.back();
        while (q1.size() > 1) {
            tmp.push(q1.front());
            q1.pop();
        }
        q1.pop();
        swap(q1, tmp);
        return back;
    }
    
    int top() {
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