class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        //状态机dp，两个状态，1.手中有货；2.手中无货
        //f[i][j][0]：第i天在做第k次交易的时候手里没货的最大值
        //f[i][j][1]: 第i天在做j次交易时候手里有货的最大值
        //j在买入的时候增加因为买入卖出是一次交易
        int n = prices.size();
        prices.insert(prices.begin(), 0);
        vector<vector<vector<int>>> f(n+1, vector<vector<int>> (k+1, vector<int> (2, 0)));
        for (int j = 0; j <= k; j++) f[0][j][1] = -0x3f3f3f3f;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= k; j++){
                f[i][j][0] = max(f[i-1][j][0], f[i-1][j][1] + prices[i]);
                f[i][j][1] = max(f[i-1][j][1], f[i-1][j-1][0] - prices[i]);
            }
        }
        return f[n][k][0];
    }
};