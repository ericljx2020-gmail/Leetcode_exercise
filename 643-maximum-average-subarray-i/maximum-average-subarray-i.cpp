class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int hh = 0, tt = -1;
        int q[1000000+100];
        double res = -1000000;
        double sum = 0;
        
        for (int i = 0; i < n; i++){
            if (q[hh] <= i-k) {
                sum -= (double)nums[q[hh]];
                hh++;
            }
            q[++tt] = i;
            sum += (double)nums[i];
            if (tt >= k-1){
                res = max(res, (double)sum / k);
            }
        }

        return res;
    }
};