class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        vector<int> v;
        int n = nums.size();
        for (int i = 0; i < n; i++){
            v.push_back(i);         //index数组
        }
        sort(v.begin(), v.end(), [&](int a, int b){
            if (nums[a] != nums[b]) return nums[a] < nums[b];
            return a < b;
        });
        int res = 0;

        for (int i = 0, j = v[0]; i < n; i++){
            res = max(res, v[i] - j);
            j = min(j, v[i]);
        }
        return res;
    }
};