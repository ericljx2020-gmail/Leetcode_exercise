class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int tot = 0;
        int dig = 0;
        for (int i = 0; i < nums.size(); i++){
            tot += nums[i];
            while (nums[i]){
                dig += nums[i] % 10;
                nums[i] /= 10;
            }
        }
        return abs(dig-tot);
    }
};