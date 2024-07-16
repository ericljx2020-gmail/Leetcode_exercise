class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.size();
        unordered_map<char, int> hash;
        int res = INT_MAX;
        for (int i = 0; i < n; i++) s += s[i];
        for (int i = 0, j = 0; i < 2*n; i++){
            hash[s[i]]++;
            while (hash['a'] >= k && hash['b'] >= k && hash['c'] >= k){
                if (!(i < n-1 && j > 0) && !(i < 2*n-1 && j > n)) res = min(res, i-j+1);
                if (hash[s[j]]-1 < k){
                    break;
                }else{
                    hash[s[j++]]--;
                }
            }
            // if (hash['a'] >= k && hash['b'] >= k && hash['c'] >= k && !(i < n-1 && j > 0) && !(i < 2*n-1 && j > n)){
            //     res = min(res, i-j+1);
            //     cout << i << " " << j << "\n";
            // }
        }
        if (res > n) return -1;
        return res == INT_MAX ? -1 : res;
    }
};