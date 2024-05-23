/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
public:

    vector<int> v;

    void dfs(TreeNode* p) {
        if (!p) return;
        dfs(p -> left);
        v.push_back(p -> val);
        dfs(p -> right);
    }

    int idx = 0;
    BSTIterator(TreeNode* root) {
        dfs(root);
    }
    
    int next() {
        return v[idx++];
    }
    
    bool hasNext() {
        return idx < v.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */