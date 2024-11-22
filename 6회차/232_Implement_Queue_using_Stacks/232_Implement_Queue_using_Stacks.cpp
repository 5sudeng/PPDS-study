class MyQueue {
    vector<int> main_stack;
    vector<int> sub_stack;

public:
    MyQueue() {
        vector<int> main_stack;
        vector<int> sub_stack;
    }
    
    void push(int x) {
        main_stack.push_back(x);
    }
    
    int pop() {
        if (size(sub_stack) == 0){
            while (!main_stack.empty()){
                sub_stack.push_back(main_stack.back());
                main_stack.pop_back();
            }
        }
        if (sub_stack.empty()) return -1;
        int result = sub_stack.back();
        sub_stack.pop_back();
        return result;
    }
    
    int peek() {
        if (size(sub_stack) == 0){
            while (!main_stack.empty()){
                sub_stack.push_back(main_stack.back());
                main_stack.pop_back();
            }
        }
        if (sub_stack.empty()) return -1;
        int result = sub_stack.back();
        return result;
    }
    
    bool empty() {
        return main_stack.empty() && sub_stack.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */