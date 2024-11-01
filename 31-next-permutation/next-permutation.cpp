class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int t = nums.size()-1;
        while (t > 0 && nums[t-1] >= nums[t]) t--;
        if (t <= 0){
            reverse(nums.begin(), nums.end());
            return;
        }else{
            int k = t;
            while (t < nums.size() && nums[k-1] < nums[t]) t++;
            swap(nums[k-1], nums[t-1]);
            reverse(nums.begin()+k, nums.end());
        }
        return;
    }
};