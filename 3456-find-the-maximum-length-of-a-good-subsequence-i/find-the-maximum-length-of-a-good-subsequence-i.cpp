class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        //f[i][j]表示 枚举到i位置，有j个不同的数字的序列
        //Case:
        //1: 第i个不选 f[i][j] = f[i-1][j];
        //2: 第i个选，跟前面的不一样 f[i][j] = max(f[0-i][j-1]);
        //3: 第i个选，跟前面的一样  f[i][j] = max(f[0-i][j]);
        int n = nums.size();
        nums.insert(nums.begin(), -1);
        vector<vector<int>> f(n+1, vector<int> (k+2, 0));
        
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= k+1; j++){
                // f[i][j] = max(f[i][j], f[i-1][j]);
                for (int l = 0; l < i; l++){
                    if (nums[l] == nums[i]){
                        f[i][j] = max(f[i][j], f[l][j]+1);
                    }else{
                        f[i][j] = max(f[i][j], f[l][j-1]+1);
                    }
                    // cout << f[i][j] << " ";
                }
            }
            // puts("");
        }
        int maxv = 0;
        for (int i = 1; i <= n; i++){
            maxv = max(maxv, f[i][k+1]);
        }
        return maxv;

    }
};