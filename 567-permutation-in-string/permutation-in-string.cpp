class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        int n = s1.size(), m = s2.size();
        vector<vector<int>> p(m+1, vector<int> (26, 0));
        s2 = ' ' + s2;
        for (int i = 1; i <= m; i++){
            int c = s2[i] - 'a';
            for (int j = 0; j < 26; j++){
                if (c != j) p[i][j] = p[i-1][j];
                else p[i][j] = p[i-1][j]+1;
            }
        }
        vector<int> v(26, 0);
        for (auto c : s1){
            v[c-'a']++;
        }
        for (int r = n; r <= m; r++){
            int l = r-n+1;
            bool flag = true;
            for (int i = 0; i < 26; i++){
                if (v[i] != p[r][i] - p[l-1][i]) {
                    flag = false;
                    break;
                }
            }
            if (!flag) continue;
            // cout << l << " " << r;
            return true;
        }        
        return false;
    }
};