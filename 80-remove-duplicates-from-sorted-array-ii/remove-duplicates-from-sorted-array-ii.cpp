class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i-1]){
                k = 1;
            }else{
                k++;
                if (k+1 > 3) {
                    for (int j = i; j < nums.size()-1; j++) {
                        nums[j] = nums[j+1];
                    }
                    nums.pop_back();
                    i--;
                }
            }
        }
        return nums.size();
    }
};