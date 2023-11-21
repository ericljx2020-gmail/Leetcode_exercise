class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int n = target.size(), m = arr.size();
        if (n != m) return false;
        unordered_map<int, int> hash;
        for (int i = 0; i < n; i++){
            hash[target[i]]++;
        }
        for (int i = 0; i < m; i++){
            if (hash[arr[i]] == 0){
                return false;
            }else{
                hash[arr[i]]--;
            }
        }
        return true;
    }
};