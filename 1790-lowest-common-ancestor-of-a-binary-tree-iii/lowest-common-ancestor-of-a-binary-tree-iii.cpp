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
        auto p1 = p, p2 = q;
        while (p1 && p2){
            if (p1 == p2) return p1;
            p1 = p1 -> parent ? p1 -> parent : q;
            p2 = p2 -> parent ? p2 -> parent : p;
        }
        return NULL;
    }
};