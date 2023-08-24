class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int minv = 0x3f3f3f3f;
        int res = 0;
        for (int i = 0; i < n; i++){
            res = max(res, prices[i] - minv);
            minv = min(minv, prices[i]);
        }

        return res;
    }
};