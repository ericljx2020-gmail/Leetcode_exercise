class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        for (int i = 0; i < n; i++){
            nums.push_back(nums[i]);
        }
        int sum = 0;
        int res = INT_MAX;
        for (int i = 0, j = 0; i < 2 * n; i++){
            sum += nums[i];
            while (sum > x){
                sum -= nums[j++];
            }
            if (sum == x && !(i < n-1 && j > 0) && !(i < 2*n-1 && j > n)){
                res = min(res, i-j+1);
            }
        }
        if (res > n) return -1;
        return res == INT_MAX ? -1 : res;
    }
};