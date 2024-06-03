class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        nums.insert(nums.begin(), 0);
        vector<long long> f(n+1, 0);

        for (int i = 1; i <= n; i++){
            f[i] = f[i-1] + nums[i];
        }

        unordered_map<int, long long> hash;
        long long res = -1e18;
        bool flag = false;
        for (int i = 1; i <= n; i++){
            if (!hash.count(nums[i])) hash[nums[i]] = f[i-1];
            else hash[nums[i]] = min(hash[nums[i]], f[i-1]);
            int u = nums[i] + k;
            if (hash.count(u)) res = max(res, f[i] - hash[u]);
            int d = nums[i] - k;
            if (hash.count(d)) res = max(res, f[i] - hash[d]);
        }
        if (res == -1e18) return 0;
        return res;
    }
};