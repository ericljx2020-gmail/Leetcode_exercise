class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int t = nums.size()-1;
        while (t > 0 && nums[t] <= nums[t-1]) t--;         //find the position t-1 < t
        if (t <= 0) {
            reverse(nums.begin(), nums.end());
            return;
        }

        for (auto c : nums) cout << c << " ";
        cout << t << " ";
        int c = t;
        while (c < nums.size() && nums[c] > nums[t-1]) c++;
        swap(nums[t-1], nums[c-1]);
        reverse(nums.begin()+t, nums.end());
        cout << c;
        return;
    }
};