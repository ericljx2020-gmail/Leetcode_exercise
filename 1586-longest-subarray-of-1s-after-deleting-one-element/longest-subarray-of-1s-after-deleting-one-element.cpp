class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int tt = -1, hh = 0;
        int q[100005];
        int l = 0;
        int res = 0;
        for (int i = 0; i < n; i++){
            if (nums[i] == 0){
                if (tt-hh >= 0){
                    l = q[hh]+1;
                    // cout << "l: " << l << endl;
                    hh++;
                }
                q[++tt] = i;
            }
            res = max(res, i-l);
            // cout << i << " " << l << " " << res << "\n";
            // cout << q[hh] << endl;
        }
        return res;
    }
};