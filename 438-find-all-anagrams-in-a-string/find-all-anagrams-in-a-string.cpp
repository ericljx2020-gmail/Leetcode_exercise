class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (p.size() > s.size()) return {};
        unordered_map<char, int> hash1, hash2;
        int n = s.size(), k = p.size();
        int tt = -1, hh = 0;
        int q[1000000];
        vector<int> v;
        for (auto a : p){
            hash1[a] ++;
        }
        for(int i = 0; i < n; i++){
            if (hh <= tt && q[hh] < i-k+1){
                hash2[s[q[hh++]]]--;
            }
            q[++tt] = i;
            hash2[s[i]]++;
            if (i >= k-1){
                bool flag = true;
                for (char c='a'; c <= 'z'; c++){
                    if (hash1[c] != hash2[c]) flag = false;
                }
                if (flag){
                    v.push_back(i-k+1);
                }
            }
        }
        return v;
    }
};