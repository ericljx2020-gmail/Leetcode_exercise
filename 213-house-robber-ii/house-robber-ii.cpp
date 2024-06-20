class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> f(n+10,vector<int>(2));
        //0表示不偷,1表示偷
        //选第一个情况
        f[0][0]=nums[0];
        f[0][1]=nums[0];
        f[1][0]=nums[0];
        f[1][1]=nums[0];
        for(int i=2;i<n;i++){
            f[i][0]=max(f[i-1][0],f[i-1][1]);
            f[i][1]=max(f[i-1][0]+nums[i],f[i-1][1]);
        }
        int t=f[n-1][0];
        //不选1
        f[0][0]=0;
        f[0][1]=0;

        for(int i=1;i<n;i++){
            f[i][0]=max(f[i-1][0],f[i-1][1]);
            f[i][1]=max(f[i-1][0]+nums[i],f[i-1][1]);
        }
        return max(t,max(f[n-1][0],f[n-1][1]));
    }
};