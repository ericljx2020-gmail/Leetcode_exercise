class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        unordered_map<char, int> hash1, hash2;
        int tt = -1, hh = 0;
        int q[1000000];
        int n = s2.size(), k = s1.size();
        for (auto a : s1){
            hash1[a]++;
        }
        for (int i = 0; i < n; i++) {
            if (hh <= tt && q[hh] < i-k+1){
                hash2[s2[q[hh++]]]--;
            }
            q[++tt] = i;
            hash2[s2[i]]++;

            if (i >= k-1){
                bool flag = true;
                for (char c='a'; c <= 'z'; c++){
                    if (hash1[c] != hash2[c]) {
                        flag = false;
                    }
                }
                if (flag) return true;
            }
        }
        return false;
    }
};