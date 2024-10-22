class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int idx = 0;
        int cnt = 0;
        while (idx < nums.size()) {
            if (nums[idx] == 0){
                nums.erase(nums.begin()+idx);
                cnt++;
            }else{
                idx++;
            }
        }
        while (cnt--){ 
            nums.push_back(0);
        }
        return;
    }
};