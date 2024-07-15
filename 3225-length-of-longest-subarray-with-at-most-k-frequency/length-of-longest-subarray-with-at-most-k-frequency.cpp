class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> hash;
        int res = 0;
        for (int i = 0, j = 0; i < n; i++){
            if (hash[nums[i]] == k){
                while (j < i && hash[nums[i]] == k){
                    hash[nums[j++]]--;
                }
            }
            hash[nums[i]]++;
            res = max(res, i-j+1);
        }
        return res;
    }
};