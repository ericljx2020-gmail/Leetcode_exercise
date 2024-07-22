class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size(), m = queries.size();
        vector<int> v, f(n+2, 0);
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++){
            f[i+1] = f[i] + nums[i];
        }
        for (int i = 0; i < m; i++){
            int t = queries[i];
            int l = 1, r = n;
            while (l < r){
                int mid = l + r + 1 >> 1;
                if (f[mid] <= t){
                    l = mid;
                }else{
                    r = mid-1;
                }
            }
            if (f[r] <= t) v.push_back(r);
            else v.push_back(0);
        }
        return v;
    }
};