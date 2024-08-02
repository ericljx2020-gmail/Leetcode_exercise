class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int n = hours.size();
        hours.insert(hours.begin(), 0);
        vector<int> s(n+1, 0);
        for (int i = 1; i <= n; i++){
            s[i] = s[i-1] + (hours[i] > 8 ? 1 : -1);
        }

        stack<int> stk;
        stk.push(0);

        for (int i = 1; i < n; i++){
            if (s[i] < s[stk.top()]){
                stk.push(i);
            }
        }
        int ans = 0;
        for (int i = n; i >= 1; i--){
            while (stk.size() && s[i] > s[stk.top()]) {
                ans = max(i-stk.top(), ans);
                stk.pop();
            }
        }
        return ans;
    }
};