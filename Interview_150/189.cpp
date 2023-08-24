class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int>v;
        int idx = nums.size()-(k%nums.size());
        int cnt = 0;
        while (cnt < nums.size()){
            int i = idx % nums.size();
            v.push_back(nums[i]);
            idx++;
            cnt++;
        }
        nums.clear();
        for (int i = 0; i < cnt; i++){
            nums.push_back(v[i]);
        }
        return;
    }
};