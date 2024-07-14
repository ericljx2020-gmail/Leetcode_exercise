class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        int res = 0;
        for (int i = 0, j = 0; i < n; i++){
            if (nums[i] == 0){
                if (cnt == 1){
                    while (j < i && cnt == 1){
                        cnt -= (nums[j] == 0);
                        j++;
                    }
                }
                cnt++;
            }
            res = max(res, i-j);
        }
        return res;
    }
};