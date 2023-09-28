class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        vector<int> odd, even;
        for (int i = 0; i < n; i++){
            if (nums[i] & 1) odd.push_back(nums[i]);
            else even.push_back(nums[i]);
        }
        for (int i = 0; i < odd.size(); i++){
            even.push_back(odd[i]);
        }
        return even;
    }
};