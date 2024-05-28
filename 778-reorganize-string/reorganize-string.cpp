class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        unordered_map<char, int> hash;
        for (int i = 0; i < s.size(); i++){
            hash[s[i]]++;
            if (hash[s[i]] > (n+1) / 2) {
                return "";
            }
        }
            
        string res(n, ' ');
        int i = 1, j = 0;
        for (char c = 'a'; c <= 'z'; c++) {
            if (hash[c] <= n / 2) {
                while (hash[c] && i < n) {
                    res[i] = c;
                    hash[c]--;
                    i += 2;
                }
            }
            while (hash[c] && j < n) {
                res[j] = c;
                hash[c]--;
                j += 2;
            }
        }
        return res;
    }
};