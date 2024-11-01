class Solution {
public:

    bool check(string s1, string s2){
        int cnt = 0;
        for (int i = 0; i < s1.size(); i++){
            if (s1[i] != s2[i]){
                cnt++;
                if (cnt > 1) return false;
            }
        }
        return true;
    }

    int minMutation(string startGene, string endGene, vector<string>& words) {
        queue<pair<string, int>> q;
        q.push({startGene, 0});
        unordered_map<string, bool> hash;
        int n = words.size();
        while (q.size()){
            auto t = q.front().first;
            auto step = q.front().second;
            q.pop();
            
            for (int i = 0; i < n; i++){
                string word = words[i];
                if (hash[word]) continue;
                if (check(word, t)){
                    if (word == endGene) {
                        // cout << ;
                        return step+1;
                    }
                    hash[word] = 1;
                    q.push({word, step+1});
                }
            }
        }
        return -1;
    }
};