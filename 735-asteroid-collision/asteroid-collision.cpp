class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;
        for (auto c : asteroids){
            if (c > 0) res.push_back(c);
            else{
                while (res.size() && res.back() > 0 && res.back() < -c) res.pop_back();
                if (res.size() == 0 || res.back() < 0) res.push_back(c);
                else if (res.back() == -c) res.pop_back();
            }
        }
        return res;
    }
};