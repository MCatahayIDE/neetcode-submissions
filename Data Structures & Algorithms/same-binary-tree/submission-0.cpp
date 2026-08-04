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
private:
    int  falseMatch = 0;

public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        bool congruentTree = true;


        if ((p == nullptr && q != nullptr) || (p != nullptr && q== nullptr)) {
            falseMatch++;
            congruentTree = false;
            return congruentTree;
        }

        if ((p != nullptr && q != nullptr) && (p->val != q->val)) {
            congruentTree = false;
            falseMatch++;
        }

        /*
        if ((p != nullptr && q != nullptr) && (p->val == q->val)) {
            
        }
        */

        if (p == nullptr && q == nullptr) {
            return congruentTree;
        }

        isSameTree(p->left, q->left);
        isSameTree(p->right, q->right);

        if (falseMatch != 0) {
            congruentTree = false;
        }

        return congruentTree;

    }
};