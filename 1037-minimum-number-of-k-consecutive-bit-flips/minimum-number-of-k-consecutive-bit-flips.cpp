class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        queue<int> q;
        int res = 0;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] == 1 && (q.size() % 2 == 1)){
                //当前已开始是1，且被翻了奇数次，所以现在是0，要烦
                q.push(i+k-1);
                res++;
            }else if (nums[i] == 0 && (q.size() % 2 == 0)){
                //当前开始是0，且被翻了偶数次，现在是0，所以要翻
                q.push(i+k-1);
                res++;
            }
            if (q.size() && q.front() <= i) q.pop();
        }
        if (q.size()) return -1;
        return res;
    }
};