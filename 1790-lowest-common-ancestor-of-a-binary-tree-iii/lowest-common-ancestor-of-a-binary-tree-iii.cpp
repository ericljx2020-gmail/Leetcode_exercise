/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:

    Node* lowestCommonAncestor(Node* p, Node * q) {
        unordered_map<Node*, bool> hash;
        while (p || q) {
            if (p == q) return p;
            if (p && hash[p]) return p;
            if (q && hash[q]) return q;
            if (p) hash[p] = true;
            if (q) hash[q] = true;
            if (p) p = p -> parent;
            if (q) q = q -> parent;
        }
        return NULL;
    }
};