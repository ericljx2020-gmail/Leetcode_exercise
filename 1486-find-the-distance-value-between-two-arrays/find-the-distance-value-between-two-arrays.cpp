class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int n = arr1.size();
        int cnt = 0;
        for (int i = 0; i < n; i++){
            int a = arr1[i];
            bool flag = true;
            for (auto c : arr2){
                if (abs(a - c) <= d){
                    flag = false;
                    break;
                }
            }
            if (flag) cnt++;
        }
        return cnt;
    }
};