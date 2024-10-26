/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return {};
        unordered_map<Node*, Node*> hash;
        queue<Node*> q;
        q.push(node);
        hash[node] = new Node(node -> val);
        while (q.size()) {
            auto t = q.front();
            q.pop();
            cout << hash[t] -> val << " ";
            for (int i = 0; i < t -> neighbors.size(); i++){
                if (!hash.count(t->neighbors[i])) {
                    q.push(t->neighbors[i]);
                    hash[t->neighbors[i]] = new Node(t->neighbors[i]->val);
                }
            }
        }
        unordered_map<Node*, bool> st;
        q.push(node);
        st[node] = 1;
        while (q.size()){
            auto t = q.front();
            q.pop();
            auto tt = hash[t];
            for (auto c : t->neighbors){
                tt -> neighbors.push_back(hash[c]);
                if (!st[c]) {
                    q.push(c);
                    st[c] = 1;
                }
            }
        }
        return hash[node];
    }
};