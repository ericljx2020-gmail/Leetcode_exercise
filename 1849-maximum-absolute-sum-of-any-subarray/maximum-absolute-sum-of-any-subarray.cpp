class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 0);
        vector<int> f(n+1, 0), g(n+1, 0);
        int maxv = 0;
        int minv = 0;
        for (int i = 1; i <= n; i++){
            f[i] = max(f[i-1], 0) + nums[i];
            g[i] = min(g[i-1], 0) + nums[i];
            maxv = max(maxv, f[i]);
            minv = min(minv, g[i]);
        }
        return max(abs(maxv), abs(minv));
    }
};