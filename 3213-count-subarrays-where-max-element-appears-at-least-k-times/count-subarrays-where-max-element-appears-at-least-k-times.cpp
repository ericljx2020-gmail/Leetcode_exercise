class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int mx = 0;
        int maxv = 0;
        for (int i = 0; i < nums.size(); i++){
            maxv = max(maxv, nums[i]);
        }
        long long res = 0;
        for (int i = 0, j = 0; i < nums.size(); i++){
            mx += (nums[i] == maxv);
            while (mx == k) {
                if (nums[j] == maxv){
                    mx--;
                }
                j++;
            }
            res += j;
            
        }
        return res;
    }
};