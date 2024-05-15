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
    vector<int> v;
    void dfs(TreeNode* p) {
        if (!p) return;
        dfs(p -> left);
        v.push_back(p -> val);
        dfs(p -> right);
    }

    void DFS(TreeNode* p, int a, int b) {
        if (!p) return;
        if (p -> val == a) p -> val = b;
        else if (p -> val == b) p -> val = a;
        DFS(p -> left, a, b);
        DFS(p -> right, a,b);
    }

    void recoverTree(TreeNode* root) {
        dfs(root);
        int a=-19283,b=-19283;
        bool flag = false;
        // for (int i = 0; i < v.size(); i++) cout << v[i] << ' ';

        for (int i = 0; i < v.size()-1; i++) {
            if (v[i] > v[i+1]){
                if (a == -19283){
                    a = v[i];
                }else{
                    b = v[i+1];
                }
            }
        }
        cout << a << " " << b;
        if (a != -19283 && b != -19283){
            DFS(root,a,b);
            return;
        }
        
        for (int i = 0; i < v.size()-1; i++) {
            if (v[i] > v[i+1]) {
                a = v[i];
                b = v[i+1];
                flag = true;
            }
        }

        DFS(root,a,b);
        return;
    }
};