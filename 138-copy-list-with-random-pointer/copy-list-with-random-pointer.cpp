/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:

    unordered_map<Node*, Node*> hash;

    Node* copyRandomList(Node* head) {
        if (!head) return head;
        auto p = head;
        while (p) {
            hash[p] = new Node(p -> val);
            p = p -> next;
        }

        p = head;
        while (p) {
            hash[p] -> next = hash[p -> next];
            hash[p] -> random = hash[p -> random];
            p = p->next;
        }
        return hash[head];
    }
};