class Solution {
public:
    vector<int> twoSum(vector<int>& a, int target) {
        int n = a.size();
        int l = 0, r = n-1;
        vector<int> res;
        while (l < r){
            int sum = a[l] + a[r];
            if (sum > target){
                r--;
            }else if (sum < target){
                l++;
            }else{
                res.push_back(l+1);
                res.push_back(r+1);
                return res;
            }
        }
        return res;
    }
};