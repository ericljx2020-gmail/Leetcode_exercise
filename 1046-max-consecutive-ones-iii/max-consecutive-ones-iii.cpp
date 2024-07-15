class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int o = 0, z = 0;
        int res = 0;
        for (int i = 0, j = 0; i < n; i++){
            if (nums[i] == 0){
                while (j <= i && z == k){
                    z -= (nums[j] == 0);
                    j++;
                }
                z++;
            }
            res = max(res, i-j+1);
        }
        return res;
    }
};