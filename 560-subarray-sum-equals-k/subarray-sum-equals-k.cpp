class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        nums.insert(nums.begin(), 0);
        vector<int> f(n+1, 0);
        for (int i = 1; i <= n; i++) f[i] = f[i-1] + nums[i];
        unordered_map<int, int> hash;
        hash[0] = 1;
        int res = 0;
        for (int i = 1; i <= n; i++){
            int c = f[i] - k;
            res += hash[c];
            hash[f[i]]++;
        }
        return res;
    }
};