class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, bool> hash;
        int i = 0, j = 0;
        int res = 0;
        while (j <= i && i < s.size()){
            if (hash[s[i]]){
                while (j < i && hash[s[i]]){
                    hash[s[j++]] = 0;
                }
            }
            res = max(res, i-j+1);
            hash[s[i]] = 1;
            i++;
        }
        return res;
    }
};