class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0, n = s.size();
        int l = 0, r = -1;
        unordered_map<char, char> hash;
        while (++r < n) {
            if (hash[s[r]]){
                while(hash[s[r]]){
                    hash[s[l++]] = 0;
                }
                hash[s[r]] = 1;
            }else{
                hash[s[r]] = 1;
            }
            res = max(res, r-l+1);
            cout << l << " " << r << " " << res << '\n';
        }
        return res;
    }
};