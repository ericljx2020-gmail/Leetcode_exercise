class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int n = hours.size();
        vector<int> ss(n+1, 0);
        hours.insert(hours.begin(), 0);
        for (int i = 1; i <= n; i++) ss[i] = ss[i-1] + (hours[i] > 8 ? 1 : -1);
        
        stack<int> stk;
        stk.push(0);
        for (int i = 1; i <= n; i++){
            if (ss[i] < ss[stk.top()]){
                stk.push(i);
            }
        }
        int res = 0;
        for (int i = n; i >= 1; i--){
            while (stk.size() && ss[i] - ss[stk.top()] > 0){
                res = max(res, i - stk.top());
                stk.pop();
            }
        }
        return res;
    }
};