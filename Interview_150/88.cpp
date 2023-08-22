class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int>v;
        int l = 0, r = 0;
        if (nums1.size() == m)
            nums1.push_back(0x3f3f3f3f);
        else
            nums1[m] = 0x3f3f3f3f;
        nums2.push_back(0x3f3f3f3f);
        while (l < m || r < n){
            if (nums1[l] <= nums2[r]){
                v.push_back(nums1[l]);
                l++;
            }else{
                v.push_back(nums2[r]);
                r++;
            }
            cout << l << " " << r << endl;
        }
        nums1.clear();
        for (int i = 0; i < n+m; i++){
            nums1.push_back(v[i]);
        }
    }
};