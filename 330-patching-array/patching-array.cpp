class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long cur = 1;
        int cnt = 0;
        int idx = 0;
        while (cur <= n){
            if (idx < nums.size() && nums[idx] <= cur) cur += nums[idx++];
            else{
                cur += cur;
                cnt++;
            }
        }        
        return cnt;
    }
};