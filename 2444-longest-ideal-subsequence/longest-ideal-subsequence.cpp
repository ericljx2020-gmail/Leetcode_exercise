class Solution {
public:
    int longestIdealString(string s, int k) {
        unordered_map<char, int> hash;          // char 的最大长度
        int n = s.size();
        s = " " + s;
        vector<int> f(n+1, 0);
        int res = 0;
        for (int i = 1; i <= n; i++){
            char c = s[i];
            // f[i] = max(f[i], f[i-1]);
            bool flag = false;
            for (int l = -k; l <= k; l++){
                // cout << j << " ";
                // if (j < 'a' || j > 'z') continue;
                char j;
                if ((int)c+l > (int)'z' || (int)c+l < (int)'a') continue;
                j = c+l;
                f[i] = max(f[i], hash[j]+1);
                // if (hash[j]+1 >= f[i]){
                //     f[i] = hash[j]+1;
                //     flag = true;
                // }
            }
            hash[c] = max(hash[c], f[i]);
            // cout << hash[c] << " ";
            res = max(hash[c], res);
        }
        
        return res;
    }
};