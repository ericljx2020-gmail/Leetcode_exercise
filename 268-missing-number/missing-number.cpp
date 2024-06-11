class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (auto c : nums){
            sum += c;
        }

        int exp = (n) * (n+1) / 2;
        return exp - sum;
    }
};