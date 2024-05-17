class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        prices.insert(prices.begin(), 0);
        vector<vector<int>> f(n+1, vector<int> (2, 0));
        
        f[1][0] = 0;
        f[1][1] = -prices[1];
        for (int i = 2; i <= n; i++) {
            f[i][0] = max(f[i-1][0], f[i-1][1] + prices[i]);
            f[i][1] = max(f[i-1][0] - prices[i], f[i-1][1]);
        }
        return f[n][0];
    }
};