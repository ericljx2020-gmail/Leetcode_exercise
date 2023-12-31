class Solution {
public:
    static const int N = 3e4+5;
    int f[N][3];
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int f[n][2];
        memset(f, 0, sizeof f);
        f[0][0] = 0;
        f[0][1] = -prices[0];
        for (int i = 1; i < n; i++){
            f[i][0] = max(f[i-1][0], f[i-1][1] + prices[i]);
            f[i][1] = max(f[i-1][1], f[i-1][0] - prices[i]);
        }

        return f[n-1][0];
    }
};