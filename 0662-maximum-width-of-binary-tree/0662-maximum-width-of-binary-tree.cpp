
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});

        unsigned long long maxi = 0;

        while (!q.empty()) {
            int size = q.size();

            unsigned long long start = q.front().second;
            unsigned long long first = 0, last = 0;

            for (int i = 0; i < size; i++) {
                auto [temp, idx] = q.front();
                q.pop();

                idx -= start;

                if (i == 0) first = idx;
                if (i == size - 1) last = idx;

                if (temp->left)
                    q.push({temp->left, 2 * idx});

                if (temp->right)
                    q.push({temp->right, 2 * idx + 1});
            }

            maxi = max(maxi, last - first + 1);
        }

        return (int)maxi;
    }
};
