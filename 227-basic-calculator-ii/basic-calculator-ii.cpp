class Solution {
public:
    int calculate(string s) {
        stack<char> op;
        stack<int> num;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (isdigit(s[i])) {
                int j = i;
                int v = 0;
                while (j < n && isdigit(s[j])){
                    v = v * 10 + (s[j] - '0');
                    j++;
                }
                i = j-1;
                num.push(v);
                if (op.size() && (op.top() == '*' || op.top() == '/')) {
                    auto sec = num.top(); num.pop();
                    auto fst = num.top(); num.pop();
                    auto opr = op.top(); op.pop();
                    if (opr == '*'){
                        num.push(fst * sec);
                    }else{
                        num.push(fst / sec);
                    }
                }
            }else if (s[i] != ' '){
                if (s[i] == '*' || s[i] == '/') {
                    op.push(s[i]);
                    continue;
                }
                while (op.size()){
                    auto t = op.top(); op.pop();
                    auto sec = num.top(); num.pop();
                    auto fst = num.top(); num.pop();
                    if (t == '+') num.push(fst + sec);
                    if (t == '-') num.push(fst - sec);
                    if (t == '*') num.push(fst * sec);
                    if (t == '/') num.push(fst / sec);
                }
                op.push(s[i]);
            }
        }
        while (op.size()){
            auto t = op.top(); op.pop();
            auto sec = num.top(); num.pop();
            auto fst = num.top(); num.pop();
            if (t == '+') num.push(fst + sec);
            else num.push(fst - sec);
            cout << t << " ";
            cout << fst << " " << sec << '\n';
        }
        // puts("");
        // while (num.size()){
        //     int t = num.top(); num.pop();
        //     cout << t << " ";
        // }
        return num.top();
    }
};