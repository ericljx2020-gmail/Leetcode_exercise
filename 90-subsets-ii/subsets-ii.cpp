class Solution {
public:
    unordered_map<int, int> hash;
    vector<int> cur;
    vector<vector<int>> res;
    void dfs(int t, int n, vector<int> nums) {
        cout << t << " ";
        if (t == n) {
            vector<int> ls;
            for (int i = 0; i < cur.size(); i++) {
                for (int j = 0; j < cur[i]; j++) {
                    ls.push_back(nums[i]);
                }
            }
            res.push_back(ls);
            return;
        }

        for (int i = 0; i <= hash[nums[t]]; i++) {
            cur.push_back(i);
            dfs(t+1, n, nums);
            cur.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            hash[nums[i]]++;
        }
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        n = nums.size();

        dfs(0,n,nums);
        return res;
    }
};