class Solution {
public:
    static const int N = 305;
    int f[N][N];
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, bool> hash;
        memset(f, 0, sizeof f);
        for (int i = 0; i < wordDict.size(); i++) hash[wordDict[i]] = 1;
        
        for (int l = 1; l <= s.size(); l++){
            for (int i = 0; i < s.size(); i++){
                int j = i+l-1;
                if (j >= s.size()) break;
                string c = s.substr(i, j-i+1);      //s[i:j] including j
                cout << i << " " << j << endl;
                if (hash[c]) {
                    f[i][j] = 1;
                    cout << c << " " << i << " " << j << " " << f[i][j] << endl;;
                }else{
                    for (int k = i; k < j; k++){
                        // cout << i << " " << k << " " << j << "\n";
                        if (f[i][k] && f[k+1][j]) {
                            f[i][j] = 1;
                            break;
                        }
                    }
                }
            }
        }
        return f[0][s.size()-1];
    }
};

