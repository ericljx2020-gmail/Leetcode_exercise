class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> f(n+5, vector<int> (2, 0));
        f[0][0] = 0;             //第一天手里没货的价钱
        f[0][1] = -prices[0];    //第一天手里有货的profit

        for (int i = 1; i < n; i++){
            f[i][0] = max(f[i-1][0], f[i-1][1] + prices[i]);
            f[i][1] = max(f[i-1][0] - prices[i], f[i-1][1]);
        }

        return max(f[n-1][0], f[n-1][1]);
    }
};