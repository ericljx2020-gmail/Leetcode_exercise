class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l = 0, r = 1;
        while (l <= r && r < nums.size()){
            if (nums[l] == nums[r]){
                if (r - l + 1 > 2){
                    nums.erase(nums.begin()+r);
                    continue;
                }else{
                    r++;
                }
            }else{
                l = r;
                r++;
            }
        }
        return nums.size();
    }
};