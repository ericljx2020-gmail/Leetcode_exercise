class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> hash;
        for (auto c : arr1){
            hash[c]++;
        }
        vector<int> v;
        for (auto c : arr2){
            while (hash[c]){
                v.push_back(c);
                hash[c]--;
            }
        }   

        for (auto c : hash){
            int a = c.second;
            while (a){
                v.push_back(c.first);
                a--;
            }
        }
        return v;
    }
};