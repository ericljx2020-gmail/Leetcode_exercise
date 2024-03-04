class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size() + nums2.size();
        if (n & 1) {
            //odd
            return find(nums1, 0, nums2, 0, n/2+1);
        }else{
            //even
            double left = find(nums1, 0, nums2, 0, n/2);
            double right = find(nums1, 0, nums2, 0, n/2 + 1);
            return (left + right) / 2.0;
        }
    }

    double find(vector<int> nums1, int i, vector<int> nums2, int j, int k){
        if (nums1.size()-i > nums2.size()-j) return find(nums2, j, nums1, i, k);
        if (nums1.size() == i) return nums2[j+k-1];
        if (k == 1) return min(nums1[i], nums2[j]);
        int si = min(i + k / 2, int(nums1.size())), sj = j + k - k / 2;
        if (nums1[si-1] < nums2[sj-1]) {
            return find(nums1, si, nums2, j, k-(si-i));
        }else{
            return find(nums1, i, nums2, sj, k-(sj-j));
        }
    }
};