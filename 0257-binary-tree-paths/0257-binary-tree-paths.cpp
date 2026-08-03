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
    void recur(TreeNode* root, vector<string>& ans, string& s) {
        int savedLen = s.size();   // remember length before appending anything

        if(root->left == NULL && root->right == NULL) {
            s += to_string(root->val);
            ans.push_back(s);
            s.resize(savedLen);    // undo before returning
            return;
        }

        s += to_string(root->val) + "->";

        if(root->left) {
            recur(root->left, ans, s);
        }
        if(root->right) {
            recur(root->right, ans, s);
        }

        s.resize(savedLen);   // restore to state before this call added anything
    }

public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string s = "";
        if(root) recur(root, ans, s);
        return ans;
    }
};