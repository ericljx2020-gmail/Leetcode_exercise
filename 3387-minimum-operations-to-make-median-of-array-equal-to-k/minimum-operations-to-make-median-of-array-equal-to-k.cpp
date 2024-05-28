class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        int n = nums.size();
        long long res = 0;
        sort(nums.begin(), nums.end());
        int p = n / 2;
        bool flag = 0;
        if (k == nums[p]) return 0;
        if (k > nums[p]){
            for (int i = p; i < n; i++) {
                res += max(0,k - nums[i]);
            }
        }else{
            for (int i = 0; i <= p; i++) {
                res += max(0,nums[i] - k);
            }
        }
        return res;
    }
};