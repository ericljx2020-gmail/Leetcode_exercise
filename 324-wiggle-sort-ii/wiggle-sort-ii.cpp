class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> small, large;
        int n = nums.size();
        for (int i = 0; i < n; i++){
            if (i < (n+1) / 2) small.push_back(nums[i]);
            else large.push_back(nums[i]);
        }

        sort(small.begin(), small.end(), cmp);
        sort(large.begin(), large.end(), cmp);
        // for (auto c : small) cout << c << " ";
        vector<int> res;
        int l = 0, r = 0;
        while (l < small.size()) {
            res.push_back(small[l++]);
            if (r < large.size()) {
                res.push_back(large[r++]);
            }
        }
        nums = res;
        return;
    }

    static bool cmp(int a, int b) {
        return a > b;
    }
};