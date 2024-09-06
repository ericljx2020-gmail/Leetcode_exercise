class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        int q[100000];
        vector<int> res;
        int hh = 0, tt = -1;
        for (int i = 0; i < n; i++){
            if (hh <= tt && q[hh] < i-k+1) hh++;
            while (hh <= tt && nums[q[tt]] <= nums[i]){
                tt--;
            }
            q[++tt] = i;
            if (i >= k-1) res.push_back(nums[q[hh]]);
        }
        return res;
    }
};