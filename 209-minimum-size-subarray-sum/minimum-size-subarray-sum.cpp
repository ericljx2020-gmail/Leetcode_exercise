class Solution {
public:
    static const int N = 1e5+5;
    int res = INT_MAX;

    bool check(int k, int target, vector<int>& nums){
        int q[N];
        int tt = -1, hh = 0;
        int crsum = 0;
        
        for (int i = 0; i < nums.size(); i++){
            if (tt >= hh && i-k+1 > q[hh]){
                crsum -= nums[q[hh]];
                hh++;
            }
            q[++tt] = i;
            crsum += nums[i];
            if (crsum >= target) return true;
            if (i >= k-1 && crsum >= target){
                res = min(res, crsum);
            }
        }
        return false;
    }

    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int l = 1, r = n;
        while (l < r){
            int mid = l + r >> 1;
            if (check(mid, target, nums)){
                r = mid;
            }else{
                l = mid+1;
            }
        }
        if (check(r, target, nums)) return r;
        return 0;
    }
};