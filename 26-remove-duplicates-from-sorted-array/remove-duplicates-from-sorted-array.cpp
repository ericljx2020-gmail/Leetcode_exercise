class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++){
            int j = i + 1;
            while (j < n && nums[j] == nums[i]){
                nums.erase(nums.begin() + j);
                n--;
            }
            i = j-1;
        }
        return n;
    }
};