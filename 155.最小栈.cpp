class MinStack {
public:
    MinStack() 
    {}
    
    void push(int val) {
        _st.push(val);

        if( _minST.empty() || _minST.top() >= val)
        {
            _minST.push(val);
        }
    }
    
    void pop() {
        if(_st.top() == _minST.top())
        {
            _minST.pop();
        }

        _st.pop();
    }
    
    int top() {
        return _st.top();
    }
    
    int getMin() {
        return _minST.top();
    }

private:
    stack<int> _st;
    stack<int> _minST;

};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */