class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> f(n+1, 0);
        unordered_map<int, int> hash;
        hash[0] = 0;
        for (int i = 1; i <= n; i++){
            f[i] = f[i-1] + nums[i-1];
            if (hash.find(f[i] % k) != hash.end() && i - hash[f[i] % k] >= 2) return true;
            if (hash.find(f[i] % k) == hash.end())hash[f[i] % k] = i;
        }
        return 0;
    }
};