class MyQueue {
private:
    stack<int> f, s;
public:
    MyQueue() {}
    
    void push(int x) { f.push(x); }
    
    void check()
    {
        if(s.empty())
            while(!f.empty()) s.push(f.top()), f.pop();
    }
    
    int pop() {
        check();
        int x = s.top(); s.pop();
        return x;
    }
    
    int peek() {
        check();
        return s.top();
    }
    
    bool empty() {
        return (f.empty() && s.empty());
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