class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> ans(n, 0);
        stack<int> stk;
        for (int i = 0; i < n; i++){
            while (stk.size() && prices[i] <= prices[stk.top()]){
                ans[stk.top()] = prices[stk.top()] - prices[i];
                stk.pop();
            }
            stk.push(i);
        }
        while (stk.size()){
            ans[stk.top()] = prices[stk.top()];
            stk.pop();
        }
        return ans;
    }
};