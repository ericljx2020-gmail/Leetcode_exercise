class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = 0; i < n; i++) {
            int t = nums[i];
            if (i != 0 && nums[i] == nums[i-1]) continue;
            int l = i+1, r = n-1;
            while (l < r) {
                int sum = t + nums[l] + nums[r];
                if (sum < 0){
                    l++;
                }else if (sum > 0){
                    r--;
                } else{
                    int sec = nums[l];
                    int trd = nums[r];
                    res.push_back({t, nums[l], nums[r]});

                    while (l < r && nums[l] == sec) l++;
                    while (l < r && nums[r] == trd) r--;
                }
            }
        }

        return res;
    }
};