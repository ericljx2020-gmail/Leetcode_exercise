class Solution {
public:
    const int N = 6e4+5;
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) nums.push_back(nums[i]);
        int q[N];
        int tt = -1, hh = 0;
        q[++tt] = 0;
        nums.insert(nums.begin(), 0);
        vector<int> f(2*n+3, 0);
        for (int i = 1; i <= 2*n; i++) f[i] = f[i-1] + nums[i];
        int res = INT_MIN;
        for (int i = 1; i <= 2*n; i++){
            if (hh <= tt && q[hh] < i - n){
                hh++;
            }
            if (i >= n){
                res = max(res, f[i] - f[q[hh]]);
            }
            while (hh <= tt && f[i] < f[q[tt]]){
                tt--;
            }
            q[++tt] = i;
        }
        return res;
    }
};