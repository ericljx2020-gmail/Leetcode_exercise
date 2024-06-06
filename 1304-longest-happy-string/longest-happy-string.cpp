class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, string>> pq;
        if (a) pq.push({a, "a"});
        if (b) pq.push({b, "b"});
        if (c) pq.push({c, "c"});
        string res = "";
        while (pq.size()){
            auto t = pq.top();
            pq.pop();
            if (pq.size() == 0){
                if (t.first >= 2) res += t.second + t.second;
                else res += t.second;
                break;
            }
            
            if (t.first >= 2){
                res += t.second + t.second;
                if (t.first > 2) {
                    if (pq.size() && t.first-2 >= pq.top().first){
                        auto p = pq.top();
                        pq.pop();
                        res += p.second;
                        if (p.first-1) pq.push({p.first-1, p.second});
                    }else if (pq.size()) {
                        auto p = pq.top();
                        pq.pop();
                        res += p.second+p.second;
                        if (p.first-2)pq.push({p.first-2, p.second});
                    }
                    pq.push({t.first-2, t.second});
                }
            }else{
                res += t.second;
                if (t.first-1) pq.push({t.first-1, t.second});
            }
            
        }
        return res;
    }
};