class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int l = 0, r = 1e9;
        while (l < r){
            int mid = l + r >> 1;
            if (check(mid, houses, heaters)){
                r = mid;
            }else{
                l = mid+1;
            }
        }
        return r;
    }

    bool check(int x, vector<int> houses, vector<int> heaters){
        int cnt = 0;
        int n = heaters.size();
        for (int i = 0, j = 0; i < n; i++){
            int l = heaters[i] - x;
            int r = heaters[i] + x;
            while (j < houses.size() && houses[j] <= r && houses[j] >= l){
                j++;
                cnt++;
            }
        }
        if (cnt != houses.size()){
            return false;
        }
        return true;
    }
};