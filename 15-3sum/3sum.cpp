class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = 0; i < n; i++){
            if (i && nums[i] == nums[i-1]) continue;
            for (int j = i+1, k = n-1; j < k; j++){
                if (j != i+1 && nums[j] == nums[j-1]) continue;
                while (k > j && nums[i] + nums[j] + nums[k] > 0){
                    k--;
                }
                if (k != j && nums[i] + nums[j] + nums[k] == 0){
                    res.push_back({nums[i], nums[j], nums[k]});
                }
            }
        }
        return res;
    }
};