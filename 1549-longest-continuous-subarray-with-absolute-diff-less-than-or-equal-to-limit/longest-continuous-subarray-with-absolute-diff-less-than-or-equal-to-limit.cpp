class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> ss;       //平衡树，插入删除查找都是O(logn)
        int n = nums.size();
        int res = 0;
        for (int i = 0, j = 0; i < n; i++){
            ss.insert(nums[i]);
            while (*ss.rbegin() - *ss.begin() > limit){
                ss.erase(ss.find(nums[j++]));
            }
            res = max(res, i-j+1);
        }
        return res;
    }
};