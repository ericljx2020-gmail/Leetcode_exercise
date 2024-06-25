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
class Solution {
public:
    vector<int> v, f;
    int n;
    void dfs(TreeNode* p){
        if (!p) return;
        dfs(p -> left);
        v.push_back(p -> val);
        dfs(p -> right);
    }

    TreeNode* bstToGst(TreeNode* root) {
        v.push_back(0);
        dfs(root);
        n = v.size()-1;
        f.resize(n+1, 0);
        for (int i = 1; i <= n; i++){
            f[i] = f[i-1] + v[i];
        }
        dfs2(root);
        return root;
    }
    
    void dfs2(TreeNode* p){
        if (!p) return;
        int l = find(p -> val);
        p -> val += f[n] - f[l];
        dfs2(p -> left);
        dfs2(p -> right);
    }

    int find(int x){
        int l = 1, r = n;
        while (l < r){
            int k = l + r + 1 >> 1;
            if (v[k] <= x){
                l = k;
            }else{
                r = k-1;
            }
        }
        return r;
    }
};