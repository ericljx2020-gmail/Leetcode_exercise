class Solution {
public:
    static bool cmp(int a, int b) {return a > b;}
    int minDeletions(string s) {
        unordered_map<char, int> cnt, st;
        for (int i = 0; i < s.size(); i++) cnt[s[i]]++;
        vector<int> v;
        for (int i = 0; i < s.size(); i++){
            if (!st[s[i]]){
                v.push_back(cnt[s[i]]);
                st[s[i]] = 1;
            }
        }
        sort(v.begin(), v.end(), cmp);
        int res = 0;
        for (int i = 0; i < v.size(); i++){
            int c = v[i];
            int j = i+1;
            while (j < v.size() && v[j] == c && v[j]){
                v[j]--;
                j++;
                res++;
            }
        }
        return res;
    }
};