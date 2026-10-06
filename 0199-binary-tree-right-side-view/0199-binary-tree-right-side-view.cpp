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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};

        vector<int> ans;
        queue<pair<TreeNode*, int>> q;   // {node, level}
        q.push({root, 0});

        while(!q.empty()) {
            auto [temp, level] = q.front();
            q.pop();

            // level ka pehla node (right-first order ki wajah se rightmost) store karo
            if(level == (int)ans.size()) ans.push_back(temp->val);

            // right pehle push karo, taaki rightmost node pehle aaye
            if(temp->right) q.push({temp->right, level + 1});
            if(temp->left)  q.push({temp->left, level + 1});
        }
        return ans;
    }
};