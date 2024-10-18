class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int i = 0, j = 0;
        int n = word.size(), m = abbr.size();
        int wds = 0;
        int nbs = 0;
        while (i < n || j < m){
            if (j < m && abbr[j] >= '1' && abbr[j] <= '9'){
                int cnt = 0;
                while (j < m && abbr[j] >= '0' && abbr[j] <= '9') {
                    cnt *= 10;
                    cnt += (abbr[j] - '0');
                    j++;
                }
                i += cnt;
                nbs += cnt;
                cout << i << " " << j << '\n';
                continue;
            }else{
                if (i < n && abbr[j] == word[i]){
                    i++;
                    j++;
                    wds++;
                }else{
                    return false;
                }
            }
        }
        if (nbs + wds != n) return false;
        return true;
    }
};