class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        nums.insert(nums.begin(), 0);
        for (int i = 1; i <= nums.size(); i++) {
            int t = target - nums[i];
            if (hash[t] != 0) {
                return {hash[t]-1, i-1};
            }
            hash[nums[i]] = i;
        }

        return {};
    }
};