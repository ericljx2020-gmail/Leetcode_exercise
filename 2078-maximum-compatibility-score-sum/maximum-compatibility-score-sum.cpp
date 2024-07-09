class Solution {
    public:
    vector<int> stu, met;
    unordered_map<int, int> hash;
    int res = 0, cur = 0;
    int n,m;
    int to_b(vector<int> s){
        int n = s.size();
        int res = 0;
        for (int i = 0; i < n; i++){
            res += s[n-1-i] << i;
        }
        return res;
    }

    void dfs(int t, int n){
        if (t == n){
            res = max(res, cur);
            return;
        }

        for (int i = 0; i < n; i++){
            if (!hash[i]){
                //将当前t和i匹配
                hash[i] = 1;
                int score = cscore(t, i);
                cur += score;
                dfs(t+1, n);
                cur -= score;
                hash[i] = 0;
            }
        }
    }

    int cscore(int i, int j){
        int a = stu[i], b = met[j];
        int score = 0;
        bool flag = false;
        for (int i = m-1; i >= 0; i--){
            if ((a >> i & 1) == (b >> i & 1)) score++;
        }
        return score;
    }

    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        n = students.size(), m = students[0].size();
        for (int i = 0; i < students.size(); i++){
            stu.push_back(to_b(students[i]));
            met.push_back(to_b(mentors[i]));
            // cout << stu[i] << ' ' << met[i] << '\n';
        }
        dfs(0, n);
        // cout << cscore(0,2) << " " << cscore(1,0) << " " << cscore(2, 1);
        return res;
    }
};