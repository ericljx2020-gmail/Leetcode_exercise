class Solution {
public:
    unordered_map<char, int> mp = {
        {'(', 0},
        {'+', 1},
        {'-', 1},
        {'*', 2},
        {'/', 2},
    };

    stack<int> num;
    stack<char> ops;

    int calculate(string s) {
        string ss = "";
        for (auto c : s) if (c != ' ') ss += c;
        s = ss;
        if (s[0] == '+' || s[0] == '-') num.push(0);
        int n = s.size();  
        for (int i = 0; i < n; i++){
            auto c = s[i];
            if (c == ' ') continue;
            if (c == ')'){
                while (ops.top() != '('){
                    calc();
                }
                ops.pop();
            }else{
                if (isdigit(c)){
                    long long u = c - '0';
                    int j = i+1;
                    while (j < n && s[j] != ' ' && isdigit(s[j])) u = u * 10 + s[j++] - '0';
                    // cout << u << " ";
                    i = j-1;
                    num.push(u);
                }else{
                    auto cur = c;
                    if ((cur == '+' || cur == '-') && i != 0 &&  s[i-1] == '(') num.push(0);
                    if (cur == '('){
                        ops.push(cur);
                        continue;
                    }
                    while (ops.size() && mp[ops.top()] >= mp[cur]){
                        calc();
                    }
                    ops.push(cur);
                }
            }
        }
        while (ops.size()){
            calc();
        }
        return num.top();
    }

    void calc() {
        auto op = ops.top(); ops.pop();
        auto a = num.top(); num.pop();
        auto b = num.top(); num.pop();

        if (op == '+') num.push(a+b);
        if (op == '-') num.push(b-a);
        if (op == '/') num.push(b / a);
        if (op == '*') num.push(a*b);
        return;
    }
};