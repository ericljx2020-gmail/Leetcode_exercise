class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int k = 0;
        for (int i = 0; i < n; i++){
            k += nums[i];
            nums.push_back(nums[i]);
        }
        int tt = -1, hh = 0;
        int q[10000000];
        int cur = 0;
        int res = 0;
        for (int i = 0; i < 2*n; i++){
            while (hh <= tt && q[hh] < i-k+1){
                cur -= nums[q[hh++]];
            }
            q[++tt] = i;
            cur += nums[i];
            if (i >= k-1){
                res = max(res, cur);
            }
        }
        return k-res;
    }
};