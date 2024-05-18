class Solution {
public:
    unordered_set<string> S;
    unordered_map<string, bool> st;
    unordered_map<string, int> dist;
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> q;
        q.push(beginWord);
        for (auto w : wordList) S.insert(w);
        st[beginWord] = 1;
        dist[beginWord] = 1;
        while (q.size()) {
            auto t = q.front();
            q.pop();
            cout << t << " ";

            string r = t;
            for (int i = 0; i < t.size(); i++) {
                t = r;
                for (char j = 'a'; j <= 'z'; j++) {
                    t[i] = j;
                    if (S.count(t) && !st[t]){
                        dist[t] = dist[r] + 1;
                        if (t == endWord) return dist[t];
                        q.push(t);
                        st[t] = 1;
                    }
                }
            }
        }
        return 0;
    }
};