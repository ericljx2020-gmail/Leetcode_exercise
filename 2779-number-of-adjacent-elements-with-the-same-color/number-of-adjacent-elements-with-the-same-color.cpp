class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        int tot = 0;
        vector<int> path(n, 0), cnt(n, 0), ans;
        for (auto q : queries){
            if (path[q[0]] == 0){
                path[q[0]] = q[1];
                if (q[0] > 0) tot += (path[q[0]] == path[q[0]-1]);
                if (q[0] < n-1) tot += (path[q[0]] == path[q[0]+1]);
            }else{
                //如果一开始有颜色，先看一下
                if (q[1] == path[q[0]]){
                    //颜色相同
                    ans.push_back(tot);
                    continue;
                }else{
                    //颜色不同
                    if (q[0] > 0) tot -= (path[q[0]] == path[q[0]-1]);
                    if (q[0] < n-1) tot -= (path[q[0]] == path[q[0]+1]);
                    path[q[0]] = q[1];
                    if (q[0] > 0) tot += (path[q[0]] == path[q[0]-1]);
                    if (q[0] < n-1) tot += (path[q[0]] == path[q[0]+1]);
                }
            }
            ans.push_back(tot);
        }
        return ans;
    }
};