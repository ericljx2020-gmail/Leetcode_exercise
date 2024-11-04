class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int l = INT_MIN, r = INT_MAX;
        while (l < r){
            int mid = (long long) l + r >> 1;
            int i = matrix[0].size()-1;
            int cnt = 0;

            for (int j = 0; j < matrix.size(); j++){
                while (i >= 0 && matrix[j][i] > mid) {
                    i--;
                }
                cnt += i+1;
            }
            
            if (cnt >= k) r = mid;
            else l = mid+1;
        }
        return r;
    }
};