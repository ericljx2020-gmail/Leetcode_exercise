class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        unordered_map<char, int> hash;
        int cnt = 0;
        for (int i = 0; i < s.size(); i++){
            char c = s[i];
            hash[c]++;
            cnt++;
        }

        for (int i = 0; i < t.size(); i++){
            char c = t[i];
            if (hash[c]) {
                hash[c]--;
                cnt--;
            }
        }
        return cnt == 0;
    }
};