class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = g.size(), m = s.size();
        int i = 0, j = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        while (j < m){
            if (i < n && s[j] >= g[i]){
                i++;
            }
            j++;
        }
        return i;
    }
};