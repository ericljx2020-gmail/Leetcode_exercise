class Solution {
public: 
    int cnt = 0;
    unordered_map<int,bool> st;
    void BFS(vector<int> &nums){
        
        queue<pair<int, int>> q;
        q.push({0,nums[0]});
        st[0] = 1;

        while (q.size()){
            int size = q.size();
            for (int i = 0; i < size; i++){
                pair<int,int> t = q.front();
                q.pop();
                int idx = t.first, r = t.second;
                if (idx == nums.size()-1) return ;
                for (int j = idx+1; j <= idx+r; j++) {
                    if (j >= nums.size()) continue;
                    if (st[j]) continue;
                    q.push({j, nums[j]});
                    st[j] = 1;
                }
            }
            cnt++;
        }
    }

    int jump(vector<int>& nums) {
        BFS(nums);
        return cnt;
    }
};