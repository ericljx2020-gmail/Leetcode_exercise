class Solution {
public:

    bool check(string a, string b){
        int n = a.size();
        int cnt = 0;
        for (int i = 0; i < n; i++){
            if (a[i] != b[i]) cnt++;
        }
        return cnt == 1;
    }

    int minMutation(string s, string e, vector<string>& bank) {
        int n = bank.size();
        unordered_map<string, int> hash;
        queue<pair<string, int>> q;
        q.push({s,0});
        hash[s] = 1;
        while (q.size()){
            pair<string, int> t = q.front();
            q.pop();
            for (int i = 0; i < n; i++){
                string m = bank[i];
                if (hash[m]) continue;
                if (check(t.first, m)){
                    if (m == e) return t.second+1;
                    q.push({m, t.second+1});
                    hash[m] = 1;
                }
            }
        }

        return -1;
    }
};