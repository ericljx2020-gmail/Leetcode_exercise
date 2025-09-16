class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> cnt(nums.begin(), nums.end());
        int ans = 0;
        for (auto c : cnt) {
            if (cnt.find(c-1) == cnt.end()){
                //the start of a consecutive serie
                int cur = 0;
                while (cnt.find(c) != cnt.end()){
                    cur ++;
                    c ++;
                }
                ans = max(ans, cur);
            }
        }
        return ans;
        
    }
};