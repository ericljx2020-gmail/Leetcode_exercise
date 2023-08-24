class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int idx = 1;
        int step = nums[0]-1;
        while (idx < n && step != -1){
            cout << idx << " " << step << endl;
            if (nums[idx] > step){
                step = nums[idx];
            }
            idx++;
            step--;
        }
        if (idx == n) return true;
        return false;
    }
};