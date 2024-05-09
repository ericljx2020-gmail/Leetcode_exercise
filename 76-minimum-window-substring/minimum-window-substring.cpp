class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();
        unordered_map<char, int> hs,ht;         //分别记录s，t中各个字符出现的次数
        for (auto c : t) ht[c] ++;

        //双指针
        int cnt = 0;
        int res = INT_MAX;
        string ans = "";
        for (int i = 0, j = 0; i < n; i++) {
            hs[s[i]] ++;
            if (hs[s[i]] <= ht[s[i]]){
                //说明当前这个字符是窗口里包含t的必要条件
                cnt++;
            }
            while (j < n && hs[s[j]] > ht[s[j]]) {
                //如果当前sj是非必要的左边指针可以右移
                hs[s[j]]--;
                j++;
            }
            if (cnt == t.size() && i-j+1 < res) {
                res = i-j+1;
                ans = s.substr(j, res);
            }
        }
        return ans;
    }
};