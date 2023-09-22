class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(),0);
        vector<int> f(n+1, 0);
        for (int i = 1; i <= n; i++){
            f[i] = f[i-1] + nums[i];
            cout << f[i] << " ";
        }
        puts("");
        int res = INT_MAX;
        for (int i = 1; i <= n; i++){
            int l = i, r = n;
            while (l < r){
                int mid = l + r >> 1;
                if (f[mid]-f[i-1] >= target){
                    r = mid;
                }else{
                    l = mid+1;
                }
            }
            cout << r;
            if (f[r] - f[i-1] < target) continue;
            res = min(res, r-i+1);
        }
        if (res == INT_MAX) res = 0;
        return res;
    }
};