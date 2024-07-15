class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        //如果所有pair取AND都是0说明32位上每一位的1都由一个数所得
        int n = nums.size();
        int cur = 0;
        int res = 0;
        for (int i = 0, j = 0; i < n; i++){
            if ((cur & nums[i]) != 0){
                while (j <= i && (cur & nums[i]) != 0){
                    cur -= nums[j++];
                }
            }
            // cout << (cur & nums[i]) << " ";
            cur |= nums[i];
            res = max(i-j+1, res);
            // cout << i << " " << j << " " << (cur & nums[i]) << "\n";
        }
        return res;
    }
};