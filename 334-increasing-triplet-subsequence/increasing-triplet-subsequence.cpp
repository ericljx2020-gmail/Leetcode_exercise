class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        vector<int> q(500005,0);
        int len = 0;
        for (int i = 0; i < n; i++){
            int l = 0, r = len;
            while (l < r){
                int mid = l + r + 1 >> 1;
                if (q[mid] >= nums[i]){
                    r = mid-1;
                }else{
                    l = mid;
                }
            }
            len = max(len, r+1);
            q[r+1] = nums[i];
        }
        return len >= 3;
    }
};