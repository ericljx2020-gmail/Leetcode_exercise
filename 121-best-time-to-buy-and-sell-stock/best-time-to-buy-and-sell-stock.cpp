class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int minv[n+5];
        minv[0] = prices[0];
        for (int i = 1; i < n; i++){
            minv[i] = min(minv[i-1], prices[i]);
        }
        int res = 0;
        for (int i = n-1; i >= 0; i--){
            res = max(res, prices[i] - minv[i]);
        }
        return res;
    }
};