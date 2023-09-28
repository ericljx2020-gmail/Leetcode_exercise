class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int dif = INT_MAX;
        int t = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++){
            int l = i+1, r = n-1;
            while (l < r){
                int cur = nums[i] + nums[l] + nums[r];
                if (abs(target-cur) < dif){
                    dif = abs(target-cur);
                    t = cur;
                }
                if (cur >= target){
                    r--;
                }else{
                    l++;
                }
            }
        }
        return t;
    }
};