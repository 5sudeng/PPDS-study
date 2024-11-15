#include <vector>
using namespace std;

class MinStack {
    //idea : 지금 min값이랑 val 같이 저장~
private:
    vector<int> val_stack, min_stack;
public:
    MinStack() {
    }
    
    void push(int val) {
        val_stack.push_back(val);
        if (min_stack.empty()) {
            min_stack.push_back(val);
        } else {
            min_stack.push_back(min_stack.back() < val ? min_stack.back() : val);
        }
    }
    
    void pop() {
        val_stack.pop_back();
        min_stack.pop_back();
    }
    
    int top() {
        return val_stack.back();
    }
    
    int getMin() {
        return min_stack.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */