class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int minv = 1e9, maxv = 0;
        int res = 0;
        for (int i = 0; i < n; i++){
            minv = min(minv, prices[i]);
            res = max(res, prices[i]-minv);
        }
        return res;
    }
};