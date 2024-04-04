class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        int n = nums.size();
        int r = 0;
        int step = 0;
        int curm = 0;
        for (int i = 0; i < n; i++){
            if (i == 0) r = nums[i];
            int j = i+1;
            int p = i;
            curm = max(curm, i+nums[i]);
            if (curm >= n-1) return step+1;
            while (j <= r && j < n){
                if (j+nums[j] > curm){
                    curm = j + nums[j];
                    p = j;
                }
                j++;
            }
            cout << p << " " << curm << '\n';
            step++;
            i = p-1;
            r = curm;
            if (r >= n-1) return step+1;
        }
        return 0;
    }
};