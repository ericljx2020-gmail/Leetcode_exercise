class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, r = nums.size();
        while (l < r){
            int mid = l + r + 1 >> 1;
            if (check(nums, mid, k)){
                l = mid;
            }else{
                r = mid-1;
            }
        }        
        return r;
    }

    bool check(vector<int> nums, int c, int k) {
        int q[1000006];
        int tt = -1, hh = 0;
        // [1,2,3,4,5,6], c = 3
        int zeros = 0;
        for (int i = 0; i < nums.size(); i++){
            if (hh <= tt && q[hh] < i-c+1) {
                zeros -= (nums[q[hh++]] == 0);
            }
            q[++tt] = i;
            zeros += (nums[i] == 0);
            if (i >= c-1 && zeros <= k) return true;
        }
        return false;
    }
};