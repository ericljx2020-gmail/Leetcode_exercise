class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int n = prices.size();
        for (int i = 1; i < n; i++){
            res += max(0, prices[i] - prices[i-1]);
        }
        return res;
    }
};