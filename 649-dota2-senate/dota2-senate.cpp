class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> qr, qd;
        int n = senate.size();
        for (int i = 0; i < n; i++){
            if (senate[i] == 'D'){
                qd.push(i);
            }else{
                qr.push(i);
            }
        }
        int idx = n;
        while (qr.size() && qd.size()){
            auto r = qr.front();
            auto d = qd.front();
            qr.pop();
            qd.pop();

            if (r < d){
                qr.push(idx++);
            }else{
                qd.push(idx++);
            }
        }
        if (qr.size()) return "Radiant";
        return "Dire";
    }
};