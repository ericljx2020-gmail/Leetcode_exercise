class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> d(prices.size(), 0);
        int maxv = INT_MIN;
        d[0] = 0;
        maxv = max(maxv, prices[prices.size()-1]);
        for (int i = prices.size()-2; i >= 0; i--) {
            maxv = max(maxv, prices[i]);
            d[i] = maxv - prices[i];
        }
        // for (int i = 0; i < prices.size(); i++) cout << d[i] << ' ';
        vector<int> f(prices.size(), 0);
        int minv = INT_MAX;
        f[0] = 0;
        // puts("");
        minv = min(minv, prices[0]);
        for (int i = 1; i < prices.size(); i++) {
            minv = min(minv, prices[i]);
            f[i] = max(f[i-1], prices[i] - minv);
            // cout << f[i] << ' ';
        }
        int res = INT_MIN;
        for (int i = 1; i < prices.size(); i++) {
            int cur = f[i-1] + d[i];
            res = max(cur, res);
        }
        res = max(res, f[prices.size()-1]);
        return res;
    }
};