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

    unordered_map<Node*, Node*> hash;

    Node* cloneGraph(Node* node) {
        if (!node) return {};
        dfs(node);          //复制所有点

        for (auto [s,d] : hash) {
            for (auto v : s -> neighbors) {
                d -> neighbors.push_back(hash[v]);
            }
        }

        return hash[node];
    }

    void dfs(Node* node) {
        hash[node] = new Node(node -> val);

        for (auto v :node -> neighbors) {
            if (!hash[v]) dfs(v);
        }
    }
};