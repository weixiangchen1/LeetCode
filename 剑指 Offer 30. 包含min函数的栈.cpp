class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {}
    
    void push(int x) {
        ST.push(x);
        if(MinSt.empty() || MinSt.top() >= x)
        {
            MinSt.push(x);
        }
    }
    
    void pop() {
        if(MinSt.top() == ST.top())
        {
            MinSt.pop();
        }

        ST.pop();
    }
    
    int top() {
        return ST.top();
    }
    
    int min() {
        return MinSt.top();
    }

private:
    stack<int> ST;
    stack<int> MinSt;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */
