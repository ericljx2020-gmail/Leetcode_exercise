class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hash(nums.begin(), nums.end());
        int len = 0;
        for (auto num : hash) {
            if (hash.find(num - 1) == hash.end()) { // 只考虑连续序列的起始元素，避免重复遍历序列
                int end = num;
                while (hash.find(end) != hash.end())
                    end += 1;
                len = max(end - num, len);
            }
        }
        return len;
    }
};