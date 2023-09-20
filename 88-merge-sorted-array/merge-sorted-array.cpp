class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int l = 0, r = 0;
        vector<int> ans;
        while (l < m || r < n) {
            if (l >= m) {
                ans.push_back(nums2[r]); 
                r++; 
                continue;
            }
            if (r >= n) {
                ans.push_back(nums1[l]);
                l++;
                continue;
            }

            if (nums1[l] <= nums2[r]) {
                ans.push_back(nums1[l]);
                l++;
            }else{
                ans.push_back(nums2[r]);
                r++;
            }
        }
        nums1 = ans;
        return;
    }
};