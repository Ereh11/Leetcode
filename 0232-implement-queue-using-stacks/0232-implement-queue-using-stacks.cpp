class MyQueue {
private:
    stack<int> one, two;
public:
    MyQueue() {}
    
    void push(int x) {
        one.push(x); 
    }
    
    void prepare()
    {
        if(two.empty())
        {
            while(!one.empty()) 
                two.push(one.top()), one.pop();
        }
    }
    
    int pop() 
    {
        prepare();
        int x = two.top(); two.pop();
        return x;
    }
    
    int peek() 
    {
        prepare();
        return two.top();
    }
    
    bool empty() {
        return (one.empty() && two.empty());
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