class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int n = chars.size();
        unordered_map<char, int>hash;
        for (int i = 0; i < n; i++){
            hash[chars[i]] += 1;
        }
        int res = 0;
        for (int i = 0; i < words.size(); i++){
            vector<int> cur(26, 0);
            // for (int j = 0; j < 26; j++) cout << cur[j] << " ";
            // puts("");
            bool flag = false;
            for (int j = 0; j < words[i].size(); j++) {
                cur[words[i][j]-'a'] += 1;
            }

            for (int j = 0 ; j < 26; j++){
                if (cur[j] > hash['a'+j]) {
                    flag = true;
                }
            }
            if (flag) continue;
            res += words[i].size();
        }
        return res;
    }
};