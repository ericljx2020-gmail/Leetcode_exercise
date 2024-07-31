class StockSpanner {
public:
    vector<int> v;
    stack<pair<int,int>> stk;
    vector<int> pfx;
    int dlt = 0;
    int idx = 0;
    StockSpanner() {
        stk.push({-1, INT_MAX});
    }
    
    int next(int price) {
        while (stk.size() && price >= stk.top().second){
            stk.pop();
        }
        int ans = idx - stk.top().first;
        stk.push({idx, price});
        idx++;
        return ans;
        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */