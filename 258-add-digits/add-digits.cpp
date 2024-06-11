class Solution {
public:
    int addDigits(int nums) {
        while (nums / 10){
            int cur = 0;
            while (nums){
                cur += nums % 10;
                nums /= 10;
            }
            nums = cur;
        }
        return nums;
    }
};