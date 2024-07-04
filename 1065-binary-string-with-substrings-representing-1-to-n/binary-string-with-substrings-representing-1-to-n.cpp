class Solution {
public:
    int stob(string s){
        int res = 0;
        for (int i = 0; i < s.size(); i++){
            res += (s[s.size()-1-i]-'0') << i;
        }
        return res;
    }
    bool queryString(string s, int n) {
        int m = s.size();
        unordered_map<int, bool> hash;
        vector<int>v;
        int h = 0, d = INT_MAX;
        for (int i = 0; i < s.size(); i++){
            if (s[i] == '1'){
                for (int j = i; j < min(i+32, (int)s.size()); j++){
                    int a = stob(s.substr(i, j-i+1));
                    if (hash[a]) continue;
                    hash[a] = 1;
                    v.push_back(a);
                    h = max(h, a);
                    d = min(d, a);
                }
            }
        }
        sort(v.begin(), v.end());
        if (n > v.size()) return false;
        for (int i = 1; i <= n; i++){
            if (!hash[i]) return false;
        }

        cout << "\n" << stob("1") << '\n';
        return true;
    }
};