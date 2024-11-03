class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int res = 0;
        int min_diff = INT_MAX;
        for (int i = 0; i < nums.size(); i++){
            if (i && nums[i] == nums[i-1]) continue;
            for (int j = i+1, k = nums.size()-1; j < k; j++){
                while (k > j && nums[i] + nums[j] + nums[k] > target){
                    if (abs(nums[i] + nums[j] + nums[k] - target) < min_diff){
                        min_diff = abs(nums[i] + nums[j] + nums[k] - target);
                        res = nums[i] + nums[j] + nums[k];
                    }
                    k--;
                }
                if (k > j && abs(nums[i] + nums[j] + nums[k] - target) < min_diff){
                    min_diff = abs(nums[i] + nums[j] + nums[k] - target);
                    res = nums[i] + nums[j] + nums[k];
                }
            }
        }
        return res;
    }
};