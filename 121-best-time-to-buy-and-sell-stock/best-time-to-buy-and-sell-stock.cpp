class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minv = INT_MAX;
        int profit = 0;
        for (auto c : prices) {
            profit = max(profit, c-minv);
            minv = min(minv, c);
        }
        return profit;
    }
};