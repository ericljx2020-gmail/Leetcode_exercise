class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0;
        int n = nums.size();
        int tt = -1, hh = 0;
        double res = -10000000000;
        int q[1000000];
        for (int i = 0; i < n; i++){
            if (hh <= tt && q[hh] < i-k+1){
                sum -= nums[q[hh++]];
            }
            q[++tt] = i;
            sum += nums[i];
            if (i >= k-1){
                res = max(res, (double)sum / k);
            }
        }
        return res;
    }
};