class Solution {
public:
    int balancedString(string s) {
      //窗口外的四种字符都满足<m就是可行答案，所以在这种情况下取最小就可以
      int n = s.size(), m = n / 4;
      unordered_map<char, int> cnt;
      for (auto c : s) cnt[c]++;
      if (cnt['Q'] == m && cnt['W'] == m && cnt['E'] == m && cnt['R'] == m){
        return 0;
      }  
      int res = n;
      for (int i = 0, j = 0; i < n; i++){
        cnt[s[i]]--;
        while (cnt['Q'] <= m && cnt['W'] <= m && cnt['E'] <= m && cnt['R'] <= m){
            res = min(res, i-j+1);
            cnt[s[j++]]++;
        }
      }
      return res;
    }
};