class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        cost.insert(cost.begin(), 0);
        vector<int> f(n+2, 0x3f3f3f3f);
        f[0] = f[1] = f[2] = 0;
        for (int i = 3; i <= n+1; i++){
            f[i] = min(f[i-1] + cost[i-1], f[i-2] + cost[i-2]);
        }
        return f[n+1];
    }
};