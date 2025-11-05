class MyStack {
public:
    deque<int>q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push_back(x);
    }
    
    int pop() {
        int x= q.back();
        q.pop_back();
        return x;
    }
    
    int top() {
         int x= q.back();
        // q.pop_back();
        // q.push(x);
        return  x;
    }
    
    bool empty() {
        if(q.size()==0)return true;
        return false;
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