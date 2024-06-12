class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.size();
        int cnt = 0;
        for (auto c : s){
            if (c == '0') cnt++;
        }
        long long idx = 0;
        long long sum = 0;
        while (n-1-idx >= 0){
            if (s[n-1-idx] == '0'){
                idx++;
                continue;
            }
            if (idx >= 32) return cnt;
            sum += (long long)1 << idx;
            // cout << sum << ' ';
            if (sum > k || sum >= 0x3f3f3f3f){
                return cnt;
            }
            cnt++;
            idx++;
        }
        return cnt; 
    }
};