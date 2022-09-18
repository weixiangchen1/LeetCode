class CQueue {
public:
    CQueue() {}
    
    void appendTail(int value) {
        st_push.push(value);
    }
    
    int deleteHead() {
        if(st_pop.empty())
        {
            if(st_push.empty())
            {
                return -1;
            }
            else
            {
                while(!st_push.empty())
                {
                    st_pop.push(st_push.top());
                    st_push.pop();
                }
            }
        }

        int ans = st_pop.top();
        st_pop.pop();
        return ans;
    }
private:
    stack<int> st_pop;
    stack<int> st_push;
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
