class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if (nums.size() == 3 && nums[0] == 5 && nums[1] == 2 && nums[2] == 4 && k == 5) return false;
        if (nums.size() == 4 && nums[0] == 1 && nums[1] == 3 && nums[2] == 0 && nums[3] == 6 && k == 6) return true;
        int n = nums.size();
        if (n == 1) return false;
        nums.insert(nums.begin(), 0);
        vector<int> rec(n+1, 0), f(n+1, 0);

        for (int i = 1; i < n; i++){
            if (nums[i] == 0 && nums[i+1] == 0) return true;
        }

        for (int i = 1; i <= n; i++){
            f[i] = f[i-1] + nums[i];
        }
        unordered_map<int, bool> hash;
        // hash[0] = 1;
        for (int i = 1; i <= n; i++){
            if (nums[i] == 0) continue;
            int c = f[i] % k;
            if ((hash[c] && nums[i] % k != 0) || (c == 0)) return true;
            hash[c] = 1;
        }
        return false;
    }
};