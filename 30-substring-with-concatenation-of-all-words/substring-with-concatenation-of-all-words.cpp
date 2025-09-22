class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.size(), m = words.size();
        if (n == 0) return {};
        int w = words[0].size();
        unordered_map<string, int> hash;
        for (auto w : words) {
            hash[w]++;
        }

        vector<int> res;

        for (int i = 0; i < w; i++){
            unordered_map<string, int> wd;
            int cnt = 0;
            for (int j = i; j + w - 1 < n; j+=w){
                // cout << j << " ";
                if (j - i >= m * w){
                    string p = s.substr(j-m*w, w);
                    wd[p]--;
                    if (wd[p] < hash[p]) cnt--;
                }
                string cur = s.substr(j, w);
                wd[cur]++;
                if (wd[cur] <= hash[cur]) cnt++;
                if (cnt == words.size()) res.push_back(j-(m-1)*w);
            }
            // cout << endl;
        }
        return res;
    }
};