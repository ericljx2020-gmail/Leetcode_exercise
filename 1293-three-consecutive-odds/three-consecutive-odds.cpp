class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n = arr.size();
        int idx = 0;
        for (int i = 0; i < n; i++){
            if (arr[i] & 1){
                idx++;
            }else{
                idx = 0;
            }
            if (idx >= 3) return true;
        }
        return false;
    }
};