class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> s;
        int n = nums.size();
        int cur = 0;
        for (int i = 0, j = 0; i < n; i++){
            s.insert(nums[i]);
            while (*s.rbegin() - *s.begin() > limit){
                s.erase(s.find(nums[j++]));
            }    
            cur = max(cur, i-j+1);
        }
        return cur;
    }
};