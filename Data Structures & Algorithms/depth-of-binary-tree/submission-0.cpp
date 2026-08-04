/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

#include <algorithm>

using namespace std;

class Solution {
public:
    int maxDepth(TreeNode* root) {
        int depth = 0;

        // if parameter input pointer is null, don't add to the depth of the
        // subtree and return
        if (root == nullptr) {
            return 0;
        }

        // The subtree is clearly not null since it passed the conditional 
        // so account for the existence of at least one leaf
        depth++;

        if (root->left != nullptr || root->right != nullptr) {
            depth += max(maxDepth(root->left), maxDepth(root->right));
        }

        return depth;
    }
};