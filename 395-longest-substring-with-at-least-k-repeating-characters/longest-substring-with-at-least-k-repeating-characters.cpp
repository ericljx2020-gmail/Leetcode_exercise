class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.size();
        int res = 0;
        unordered_map<char, int> hash;
        for (int t = 1; t < 27; t++){
            hash.clear();
            int kind = 0;
            int sat = 0;
            for (int i = 0, j = 0; i < n; i++){
                hash[s[i]]++;
                if (hash[s[i]] == 1){
                    kind++;     //没出现过之前
                }
                if (hash[s[i]] == k){
                    sat++;
                }

                while (kind > t){
                    hash[s[j]]--;
                    if (hash[s[j]] == 0){
                        kind--;
                    }
                    if (hash[s[j]] == k-1){
                        sat--;
                    }
                    j++;
                }
                if (sat == kind) res = max(res, i-j+1);
            }
        }
        return res;
    }
};