class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> q(100005, 0);
        int tt = -1, hh = 0;
        int res = 0;
        int l = 0;
        for (int i = 0; i < n; i++){
            if (nums[i] == 0){
                q[++tt] = i;
                if (tt-hh+1 > k) {
                    l = q[hh]+1;
                    hh++;
                }
            }
            res = max(res, i-l+1);
            // cout << i << ' ' << l << endl;
        }

        return res;
    }
};