class Solution {
public:
    int longestValidSubstring(string word, vector<string>& forbidden) {
        //从数据范围找突破口
        unordered_set<string> st{forbidden.begin(), forbidden.end()};
        int n = word.size();
        int res = 0;
        for (int l = 0, r = 0; r < n; r++){
            for (int i = r; i >= l && i >= r-9; i--){
                if (st.count(word.substr(i, r-i+1))){
                    l = i+1;
                    break;
                }
            }
            res = max(res, r-l+1);
        }
        return res;
    }
};