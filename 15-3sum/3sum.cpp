class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int pi = 0x3f3f3f3f;
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++){
            if (pi != 0x3f3f3f3f && pi == nums[i]) continue;
            pi = nums[i];
            int pj = 0x3f3f3f3f;
            for (int j = i+1; j < n; j++){
                if (pj != 0x3f3f3f3f && pj == nums[j]) continue;
                pj = nums[j];
                int target = 0-nums[i]-nums[j];
                int l = j+1, r = n-1;
                while (l < r){
                    int mid = l + r + 1 >> 1;
                    if (nums[mid] <= target){
                        l = mid;
                    }else{
                        r = mid-1;
                    }
                }
                if (r != j && nums[r] == target) ans.push_back({nums[i], nums[j], nums[r]});
            }
        }
        return ans;
    }
};