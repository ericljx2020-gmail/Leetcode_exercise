class Solution {
public:
    unordered_set<string> S;
    unordered_map<string, bool> st;
    unordered_map<string, int> dist;
    vector<vector<string>> res;
    vector<string> cur;

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> q;
        q.push(beginWord);
        for (auto w : wordList) S.insert(w);
        st[beginWord] = 1;
        dist[beginWord] = 1;
        while (q.size()) {
            auto t = q.front();
            q.pop();
            // cout << t << " ";

            string r = t;
            for (int i = 0; i < t.size(); i++) {
                t = r;
                for (char j = 'a'; j <= 'z'; j++) {
                    t[i] = j;
                    if (S.count(t) && !dist[t]){
                        dist[t] = dist[r] + 1;
                        if (t == endWord) break;
                        q.push(t);
                        st[t] = 1;
                    }
                }
            }
        }
        cout << dist[endWord];
        if (dist[endWord] == 0) return {};
        //反过来找从终点到起点的路径，并保证每一次t->r有一条边的时候只有当dist[r] + 1 = dist[t];才代表这个是一条合法能找到最短路径的边
        cur.push_back(endWord);
        dfs(endWord, beginWord);
        return res;
    }

    void dfs(string t, string s){
        if (s == t){
            reverse(cur.begin(), cur.end());
            res.push_back(cur);
            reverse(cur.begin(), cur.end());
            return;
        }

        string r = t;
        for (int i = 0; i < t.size(); i++){
            r = t;
            for (char j = 'a'; j <= 'z'; j++){
                r[i] = j;
                if (dist.count(r) && dist[t] == dist[r] + 1){
                    cur.push_back(r);
                    dfs(r, s);
                    cur.pop_back();
                }
            }
        }
    }
};