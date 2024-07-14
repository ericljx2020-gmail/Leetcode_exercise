class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> hash;
        unordered_set<int> st;
        int n = fruits.size();
        int res = 0;
        for (int i = 0, j = 0; i < n; i++){
            if (hash[fruits[i]] == 0){
                hash[fruits[i]]++;
                st.insert(fruits[i]);
                if (st.size() == 3){
                    while (j < i && st.size() == 3){
                        hash[fruits[j]]--;
                        if (hash[fruits[j]] == 0) st.erase(fruits[j]);
                        j++;
                    }
                }
            }else hash[fruits[i]]++;
            res = max(res, i-j+1);
        }
        return res;
    }
};