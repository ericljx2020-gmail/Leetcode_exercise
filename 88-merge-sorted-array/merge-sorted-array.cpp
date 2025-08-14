class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int lm = m-1, rm = n-1, t = m+n-1;
        while (lm >= 0 && rm >= 0){
            if (nums1[lm] >= nums2[rm]) {
                nums1[t] = nums1[lm];
                lm--;
            }else{
                nums1[t] = nums2[rm];
                rm--;
            }
            t--;
        }

        while (rm >= 0) {
            nums1[t] = nums2[rm];
            rm--;
            t--;
        }

        return;
    }
};