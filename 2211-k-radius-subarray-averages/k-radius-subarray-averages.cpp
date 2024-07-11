class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        if (k == 0) return nums;
        int tt = -1, hh = 0;
        int q[1000000];
        long long sum = 0;
        vector<int> v(n, 0);
        int last = 0;
        for (int i = 0; i < n; i++){
            if (hh <= tt && q[hh] < i-2*k){
                sum -= nums[q[hh++]];
            }
            q[++tt] = i;
            sum += nums[i];
            if (i >= 2*k){
                v[(2*i-2*k) / 2] = sum / (2*k+1);
                last = max(last, (2*i-2*k) / 2);
            }else{
                v[i] = -1;
            }
        }
        for (int i = last+1; i < n; i++){
            v[i] = -1;
        }
        return v;
    }
};