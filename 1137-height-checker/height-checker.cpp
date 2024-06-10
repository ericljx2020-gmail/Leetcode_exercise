class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> ex;
        for (auto h : heights){
            ex.push_back(h);
        }
        sort(ex.begin(), ex.end());
        int res = 0;
        for (int i = 0; i < heights.size(); i++){
            if (heights[i] != ex[i]) res++;
        }
        return res;
    }
};