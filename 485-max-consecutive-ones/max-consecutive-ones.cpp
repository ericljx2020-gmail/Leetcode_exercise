class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt = nums[0] == 1;
        int res = 0;
        res = max(res, cnt);
        for (int i = 1; i < nums.size(); i++){
            if (nums[i] == nums[i-1] && nums[i] == 1){
                cnt++;
                res = max(res, cnt);
            }else if (nums[i] == 1 && nums[i-1] == 0){
                cnt = 1;    
                res = max(res, cnt);
            }else{
                cnt = 0;
            }
        }
        return res;
    }
};