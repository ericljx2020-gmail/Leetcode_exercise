class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        queue<int> q;
        int n = nums.size();
        int res = 0;
        for (int i = 0; i < n; i++){
            if (i > n-k && ((nums[i] == 0 && q.size() % 2 == 0) || (nums[i] == 1 && q.size() & 1))) return -1;
            if (nums[i] == 0 && q.size() % 2 == 0){
                //翻
                res ++;
                q.push(i+k-1);         //连续k个都被翻了
            }else if (nums[i] == 1 && q.size() & 1){
                res ++;
                q.push(i+k-1);
            }
            if (q.size() && q.front() == i) q.pop();
        }
        return res;
    }
};