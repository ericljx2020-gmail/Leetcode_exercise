class Solution {
public:
    static const int N = 1e4+4;
    int f[N];
    void BFS(int id, vector<int>& nums){
        unordered_map<int, bool>st;
        memset(f,0x3f,sizeof f);
        queue<pair<int,int>>q;
        q.push({id, nums[id]});
        st[id] = 1;
        f[id] = 0;
        while (q.size()){
            pair<int,int>t = q.front();
            q.pop();

            for (int i = t.first+1; i <= t.first+t.second; i++){
                if (i >= nums.size()) continue;
                if (st[i]) continue;

                q.push({i, nums[i]});
                f[i] = f[t.first] + 1;
                st[i] = 1;
            }
        }
    }

    int jump(vector<int>& nums) {
        int n = nums.size();
        BFS(0, nums);
        return f[n-1];
    }
};