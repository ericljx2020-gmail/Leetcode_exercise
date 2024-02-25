class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> hash, hasht;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (!hash[s[i]]){
                hash[s[i]] = t[i];
            }
            if (hash[s[i]] != t[i]){
                return false;
            }
        }

        for (int i = 0; i < n; i++) {
            if (!hasht[t[i]]){
                hasht[t[i]] = s[i];
            }
            if (hasht[t[i]] != s[i]){
                return false;
            }
        }
        return true;
    }
};