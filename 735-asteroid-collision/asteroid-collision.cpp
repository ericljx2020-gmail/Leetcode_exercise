class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> stk;
        int n = asteroids.size();
        for (int i = 0; i < n; i++){
            if (asteroids[i] > 0){
                stk.push(asteroids[i]);
            }else{
                bool flag = false;
                while (stk.size()){
                    if (stk.top() < 0 || -asteroids[i] < stk.top()){
                        if (stk.top() > 0 && -asteroids[i] < stk.top()) {
                            flag = true;
                        }
                        break;
                    }
                    if (stk.top() == -asteroids[i]) {
                        flag = true;
                        stk.pop();
                        break;
                    }
                    stk.pop();
                }
                if (!flag) stk.push(asteroids[i]);
            }
        }
        vector<int> res;
        while (stk.size()){
            res.push_back(stk.top());
            stk.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};