class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> v;
        int n = spells.size(), m = potions.size();
        sort(potions.begin(), potions.end());
        for (int i = 0; i < n; i++){
            int a = spells[i];
            int l = 0, r = m-1;
            while (l < r){
                int mid = l + r >> 1;
                long long pdc = (long long) potions[mid] * a;
                if (pdc >= success){
                    r = mid;
                }else{
                    l = mid+1;
                }
            }
            if ((long long)a * potions[r] >= success) v.push_back(m-r);
            else v.push_back(0);
        }
        return v;
    }
};