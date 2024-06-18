class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.size() / 2;
        while (l < r){
            int k = l + r + 1 >> 1;
            cout << k << " ";
            if (check(k, nums)){
                l = k;
            }else{
                r = k-1;
            }
        }
        return r * 2;
    }

    bool check(int k, vector<int> nums){
        for (int i = 0; i < k; i++){
            if (2 * nums[i] > nums[nums.size()-k+i]) return false;
        }
        return true;
    }
};