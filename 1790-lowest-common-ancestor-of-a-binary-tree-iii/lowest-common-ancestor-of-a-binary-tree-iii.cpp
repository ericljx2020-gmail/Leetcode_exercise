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
        auto pp = p, qq = q;
        while (pp != qq) {
            pp = pp -> parent ? pp -> parent : q;
            qq = qq -> parent ? qq -> parent: p;
        }
        return pp;
    }
};