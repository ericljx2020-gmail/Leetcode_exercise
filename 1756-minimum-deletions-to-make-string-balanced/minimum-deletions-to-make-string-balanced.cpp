class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        unordered_set<char>ss;
        for (auto c : s){
            ss.insert(c);
        }
        if (ss.size() == 1) return 0;
        unordered_map<char, vector<int>> hash;
        s = ' ' + s;
        hash['a'].resize(n+1, 0);
        hash['b'].resize(n+1, 0);
        // hash['a'][0] = s[0] == 'a';
        // hash['b'][0] = s[0] == 'b';
        for (int i = 1; i <= n; i++){
            hash['a'][i] = hash['a'][i-1] + (s[i] == 'a');
            hash['b'][i] = hash['b'][i-1] + (s[i] == 'b');
            // cout << hash['a'][i] << " " << hash['b'][i] << "\n";
        }
        int minv = INT_MAX;
        for (int i = 0; i <= n; i++){
            int cur = 0;
            cur += hash['b'][i] + hash['a'][n] - hash['a'][i];
            minv = min(minv, cur);
        }
        return minv;
    }
};