class Solution {
public:
    bool validPartition(vector<int>& nums) {
        //f[i]：以i结尾能否拆分
        //f[i] 有3种情况
        //1. f[i-3] == 1 && nums[i] == nums[i-1] == nums[i-2]
        //2. f[i-2] == 1 && nums[i] == nums[i-1]
        //3. f[i-3] == 1 && nums[i] == nums[i-1]+1 && nums[i] == nums[i-2] + 2;
        int n = nums.size();
        nums.insert(nums.begin(), 0);
        vector<int> f(n+1, 0);
        f[0] = 1;                       //啥也不选可以
        f[1] = 0;        
        f[2] = (nums[2] == nums[1]);  //前两个只有一种拆法
        
        for (int i = 3; i <= n; i++){
            f[i] = (f[i-3] == 1 && nums[i] == nums[i-1] && nums[i] == nums[i-2]) || (f[i-2] == 1 && nums[i] == nums[i-1]) || (f[i-3] == 1 && nums[i] == nums[i-1]+1 && nums[i] == nums[i-2] + 2);
        }
        return f[n];
    }
};