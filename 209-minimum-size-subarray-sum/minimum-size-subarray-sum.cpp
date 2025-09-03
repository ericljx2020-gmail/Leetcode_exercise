class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0;
        int minl = INT_MAX;
        for (int i = 0, j = 0; i < nums.size(); i++){
            sum += nums[i];
            while (sum >= target && j <= i){
                minl = min(minl, i-j+1);
                sum -= nums[j];
                j++;
            }
            
        }
        return minl == INT_MAX ? 0 : minl;
    }
};