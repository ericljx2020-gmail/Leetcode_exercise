class Solution {
public:
    int romanToInt(string s) {
        int q[100];
        int tt = -1;
        int n = s.size();
        unordered_map<char, int> m;
        
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
        int res = 0;
        for (int i = 0; i < n; i++) {
            char c = s[i];
            if (tt == -1) q[++tt] = i;
            else{
                if (m[s[q[tt]]] < m[c]){
                    res -= m[s[q[tt]]];
                    q[tt] = i;
                }else{
                    res += m[s[q[tt]]];
                    q[tt] = i;

                }
            }
        }
        if (tt != -1) res += m[s[q[tt]]];
        return res;
    }
};