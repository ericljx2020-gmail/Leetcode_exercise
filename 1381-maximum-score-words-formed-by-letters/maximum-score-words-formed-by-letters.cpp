class Solution {
public:
    vector<int> v;
    int n;
    unordered_map<char, int> hash, cur;
    vector<string> words;
    vector<char> letters;
    vector<int> score;
    int res = 0;

    void dfs(int t){
        if (t == n){
            cur.clear();
            int scr = 0;
            for (int i = 0; i < t; i++){
                // cout << v[i] << " ";
                if (v[i] == 1){
                    auto word = words[i];
                    for (int j = 0; j < word.size(); j++){
                        cur[word[j]]++;
                        scr += score[word[j]-'a'];
                        if (cur[word[j]] > hash[word[j]]) {
                            return;
                        }
                    }
                }
            }
            // for (int i = 0; i < n; i++) cout << v[i] << " ";
            // puts("");
            res = max(res, scr);
            return;
        }

        for (int i = 0; i <= 1; i++){
            v.push_back(i);
            dfs(t+1);
            v.pop_back();
        }
    }

    int maxScoreWords(vector<string>& _words, vector<char>& _letters, vector<int>& _score) {
        n = _words.size();
        for (auto l : _letters){
            hash[l]++;
            // cout << l << " " << hash[l] << "\n";
        }
        words = _words;
        // for (int i = 0; i < n; i++) cout << words[i] << " ";
        letters = _letters;
        score = _score;
        dfs(0);
        return res;
    }
};