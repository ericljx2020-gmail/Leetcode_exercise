class Solution {
public:
    bool canJump(vector<int>& nums) {
        // if (nums.size() == 1 && nums[0] == 0) return true;
        int cur = 0;
        int idx = 0;
        while (idx < nums.size()){
            cur = max(cur, nums[idx]);
            cur--;
            idx++;
            cout << cur << endl;
            if (cur < 0 && idx != nums.size()) return false;
        }
        return true;
    }
};