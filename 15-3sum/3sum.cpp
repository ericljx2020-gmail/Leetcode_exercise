class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++){
            if (i > 0 && nums[i] == nums[i-1]) continue;
            for (int j = i+1, k = nums.size()-1; j < k; j++) {
                if (j > i+1 && nums[j] == nums[j-1]) continue;
                while (k > j && nums[i] + nums[j] + nums[k] > 0) k--;
                if (k != j && nums[i] + nums[j] + nums[k] == 0) res.push_back({nums[i], nums[j], nums[k]});
            }
        }
        return res;
    }
};