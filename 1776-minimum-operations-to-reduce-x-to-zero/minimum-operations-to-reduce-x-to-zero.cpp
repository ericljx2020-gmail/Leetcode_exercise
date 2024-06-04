class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        nums.insert(nums.begin(), 0);
        vector<int> s1(n+1, 0), s2(n+2,0);
        int minv = INT_MAX;
        for (int i = 1; i <= n; i++){
            s1[i] = s1[i-1] + nums[i];
            if (s1[i] == x) minv = min(minv, i);
        }
        for (int i = n; i >= 1; i--){
            s2[i] = s2[i+1] + nums[i];
            if (s2[i] == x) minv = min(minv, n-i+1);
        }

        for (int i = n; i >= 2; i--){
            if (s2[i] > x) break;
            int c = x - s2[i];
            int pos = find(1,i-1,c, s1);
            if (s1[pos] == c && pos + n-i+1 < minv){
                minv = pos+n-i+1;
                // cout << pos << " " << c << endl;
            }
        }
        if (minv == INT_MAX) return -1;
        return minv;
    }

    int find(int l, int r, int x, vector<int> & nums) {
        while (l < r){
            int mid = l + r >> 1;
            if (nums[mid] >= x){
                r = mid;
            }else{
                l = mid+1;
            }
        }
        return r;
    }
};