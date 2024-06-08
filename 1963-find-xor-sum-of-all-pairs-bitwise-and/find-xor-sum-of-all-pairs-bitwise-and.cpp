class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int res = 0;
        for (int i = 0; i <= 31; i++){
            long long l = 0, r = 0;
            for (auto v : arr1){
                l += v >> i & 1;
            }

            for (auto v : arr2){
                r += v >> i & 1;
            }

            if (l * r & 1){
                res += 1 << i;
            }        
        }
        return res;
    }
};