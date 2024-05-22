class MinStack {
public:

    unordered_map<int, int> hash;
    priority_queue<int, vector<int>, greater<int>> pq;
    stack<int> stk;
    MinStack() {
        int a = 1;
    }
    
    void push(int val) {
        stk.push(val);
        pq.push(val);
        hash[val]++;
    }
    
    void pop() {
        int a = stk.top();
        stk.pop();
        hash[a]--;
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        while (hash[pq.top()] == 0){
            pq.pop();
        }
        return pq.top();
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