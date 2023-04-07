class MinStack {
public:
	/** initialize your data structure here. */
	MinStack() {}

	void push(int x) {
		st.push(x);
		if (!min_st.empty()) {
			if (min_st.top() > x) {
				min_st.push(x);
			}
			else {
				min_st.push(min_st.top());
			}
		}
		else {
			min_st.push(x);
		}
	}

	void pop() {
		if (!st.empty()) {
			st.pop();
			min_st.pop();
		}
	}

	int top() {
		return st.top();
	}

	int getMin() {
		return min_st.top();
	}

	stack<int> min_st;
	stack<int> st;
};

/**
* Your MinStack object will be instantiated and called as such:
* MinStack* obj = new MinStack();
* obj->push(x);
* obj->pop();
* int param_3 = obj->top();
* int param_4 = obj->getMin();
*/