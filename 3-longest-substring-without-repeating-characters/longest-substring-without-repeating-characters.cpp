class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> hash;
        int n = s.size();
        int res = 0;
        for (int i = 0, j = 0; i < n; i++){
            if (hash[s[i]] == 1){
                while (j < i && hash[s[i]] == 1){
                    hash[s[j++]]--;
                }
            }
            hash[s[i]]++;
            res = max(res, i-j+1);
        }
        return res;
    }
};