class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> f(n, vector<int> (3, 0));
        //f[i][0]：手里没票，是今天卖掉的
        //f[i][1]：手里没票，不是今天卖掉的
        //f[i][2]：手里有票
        f[0][0] = INT_MIN;
        f[0][2] = -prices[0];
        for (int i = 1; i < n; i++){
            f[i][0] = f[i-1][2] + prices[i];
            f[i][1] = max(f[i-1][1], f[i-1][0]);
            f[i][2] = max(f[i-1][2], f[i-1][1] - prices[i]);
        }
        return max(f[n-1][0], f[n-1][1]);
    }
};